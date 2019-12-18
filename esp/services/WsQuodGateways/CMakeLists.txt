################################################################################
#    HPCC SYSTEMS software Copyright (C) 2012 HPCC Systems®.
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
################################################################################


# Component: WsQuodGateways 
#####################################################
# Description:
# ------------
#    Cmake Input File for WsQuodGateways
#####################################################

project( WsQuodGateways ) 

include(${HPCC_SOURCE_DIR}/esp/scm/espscm.cmake)

set (    SRCS 
         ${ESPSCM_GENERATED_DIR}/ws_quod_gateways_esp.cpp 
         WsQuodGatewaysPlugin.cpp 
         WsQuodGatewaysService.cpp 
    )

include_directories ( 
         ./../../esplib 
         ./../.. 
         ./../../platform 
         ./../../../system/jlib 
         ./../../../common/environment 
         ./../../services 
         ./../common 
         ./../../../system/xmllib 
         ./../../../system/security/securesocket 
         ./../../../system/security/shared 
         ./../../../system/include 
         ./../../../common/remote 
         ./../../clients 
         ./../../../dali/base 
         ./../../../common/dllserver 
         ./../../bindings 
         ./../../bindings/SOAP/xpp 
         ./../../bindings/http/client
    )

ADD_DEFINITIONS( -D_USRDLL )

HPCC_ADD_LIBRARY( WsQuodGateways SHARED ${SRCS}  )
add_dependencies (WsQuodGateways espscm)
install ( TARGETS WsQuodGateways RUNTIME DESTINATION ${EXEC_DIR} LIBRARY DESTINATION ${LIB_DIR} )
target_link_libraries ( WsQuodGateways  
         jlib
         xmllib 
         esphttp 
    )
