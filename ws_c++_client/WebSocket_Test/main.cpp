#include <Windows.h>
#include <clocale>

#include "King_WebSocket/King_WebSocket.hpp"
King_WebSocket *g_ws = new King_WebSocket;

#include "Config.hpp"
#include "configor/json.hpp"
using namespace configor;

int main( ) {
    g_ws->run( "ws://127.0.0.1:7068" );

    const std::atomic< bool > run { true };
    auto                      receiver = std::thread( [ & ] {
        std::string s;
        while( run ) {
            if( g_ws->recv( s ) ) {
                auto basic_value    = json::parse( s );
                auto type = basic_value [ "type" ].get< std::string >( );
                if( type == "ConfigList" ) {
                    Config.GetConfigList_Callbak( s );
                }
                if( type == "GetConfig" ) {
                    Config.GetConfig_Callbak( s );
                }
            }
            std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
        }
    } );

    const std::string user = "01/ImKK666";

    while( true ) {
        static bool ButtonDown;
        if( GetAsyncKeyState( VK_F1 ) ) {
            if( !ButtonDown ) {
                Config.SetConfig( user, "Test紫血傻逼" );
            	ButtonDown = true;
            }
        }
        else if( GetAsyncKeyState( VK_END ) ) {
            if( !ButtonDown ) {
                g_ws->close( );
                ButtonDown = true;
                break;
            }
        }
        else {
            ButtonDown = false;
        }
    }
    delete g_ws;


    return 0;
}