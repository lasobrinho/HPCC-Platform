#pragma warning (disable : 4786)

#include "WsQuodGatewaysService.hpp"

void CWsQuodGatewaysEx::init(IPropertyTree *cfg, const char *process, const char *service)
{
	StringBuffer xpath;
	xpath.appendf("Software/EspProcess[@name=\"%s\"]/EspService[@name=\"%s\"]", process, service);
	Owned<IPropertyTree> srvcfg = cfg->getPropTree(xpath.str());
	StringBuffer systemName, deployDir;
	if (!srvcfg)
	{
		throw MakeStringException(5002, "Unable to load configuration");
	}

	Owned<IPropertyTree> httpConfig = srvcfg->getPropTree("GatewayEndpoint");
	if (!httpConfig)
	{
		throw MakeStringException(5003, "Unable to load endpoint configuration");
	}
	m_HttpConfig = httpConfig;

	StringBuffer endpointURL;
	m_HttpConfig->getProp("URL", endpointURL);

	if (endpointURL.isEmpty())
	{
		throw MakeStringException(5004, "Unable to load URL endpoint configuration");
	}
	m_URL = endpointURL;
}

bool CWsQuodGatewaysEx::onCallDummyQuodEndpoint(IEspContext &context, IEspDummyAPIRequest &req, IEspDummyAPIResponse &resp)
{
	Owned<IHttpClientContext> httpClientContext = createHttpClientContext(m_HttpConfig);
	Owned<IHttpClient> httpClient = httpClientContext->createHttpClient(NULL, m_URL);

	StringBuffer method("GET");
	StringBuffer requestBuffer("");
	StringBuffer responseBuffer, responseStatus;

	httpClient->sendRequest(method, NULL, requestBuffer, responseBuffer, responseStatus, true);

	resp.setResponse(responseBuffer);
	return true;
}
