#pragma warning (disable : 4786)

#include "ws_quod_gateways_esp.ipp"

//ESP Bindings
#include "http/platform/httpprot.hpp"

//ESP Service
#include "WsQuodGatewaysService.hpp"

#include "espplugin.hpp"

extern "C"
{

//when we aren't loading dynamically
// Change the function names when we stick with dynamic loading.
ESP_FACTORY IEspService * esp_service_factory(const char *name, const char* type, IPropertyTree *cfg, const char *process)
{
   if (strcmp(type, "WsQuodGateways") == 0)
   {
      CWsQuodGatewaysEx* service = new CWsQuodGatewaysEx;
      service->init(cfg, process, name);
      return service;
   }
    else
    {
        throw MakeStringException(-1, "Unknown service type %s", type);
    }
   return NULL;
}

ESP_FACTORY IEspRpcBinding * esp_binding_factory(const char *name, const char* type, IPropertyTree *cfg, const char *process)
{
   if (strcmp(type, "WsQuodGatewaysSoapBinding") == 0)
   {
      return new CWsQuodGatewaysSoapBindingEx(cfg, name, process);
   }
    else
    {
        throw MakeStringException(-1, "Unknown binding type %s", type);
    }

   return NULL;
}

ESP_FACTORY IEspProtocol * esp_protocol_factory(const char *name, const char* type, IPropertyTree *cfg, const char *process)
{
    return http_protocol_factory(name, type, cfg, process);
}

};
