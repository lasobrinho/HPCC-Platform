#ifndef _ESPWIZ_WsQuodGateways_HPP__
#define _ESPWIZ_WsQuodGateways_HPP__

#include "ws_quod_gateways_esp.ipp"


class CWsQuodGatewaysEx : public CWsQuodGateways
{
private:
	Owned<IPropertyTree> m_HttpConfig;
	StringBuffer m_URL;

public:
    IMPLEMENT_IINTERFACE;

	~CWsQuodGatewaysEx() {};
    virtual void init(IPropertyTree *cfg, const char *process, const char *service);

	virtual bool onCallDummyQuodEndpoint(IEspContext &context, IEspDummyAPIRequest& req, IEspDummyAPIResponse& resp);
};

class CWsQuodGatewaysSoapBindingEx : public CWsQuodGatewaysSoapBinding
{
private:
public:
	IMPLEMENT_IINTERFACE;

	CWsQuodGatewaysSoapBindingEx(IPropertyTree* cfg, const char *bindname = NULL, const char *procname = NULL, http_soap_log_level level = hsl_none)
		: CWsQuodGatewaysSoapBinding(cfg, bindname, procname, level) {}

	virtual ~CWsQuodGatewaysSoapBindingEx() {}
};

#endif //_ESPWIZ_WsQuodGateways_HPP__

