#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include "enet/include/enet.h"
#include "http.h"
#include "NubiAuth.h"
#include "android_device_id.h"
#include "server.h"
#include "events.h"
#include "gt.hpp"
#include "DiscordRpc.h"

server* g_server = new server();
Discord* g_Discord;

int main() {
#ifdef _WIN32
    SetConsoleTitleA("Erza Proxy");
    g_Discord->Initialize();
    g_Discord->Update();
#endif
    
printf("Erza Proxy Authentication.\n\n");

    std::string user_name = "";
    printf("Enter License : "); std::cin >> user_name;


    std::thread http(http::run, "127.0.0.1", "17191");
    http.detach();


    NubiAuth auth;
    // api key from https://auth.nubizaserver.my.id/
    auth.ApiKey = "ed651633ae61610b8a2b50c91f1830af42552if48mwbord";
    // set device id
    auth.device_id = get_device_id();
    
    enet_initialize();
    if (auth.login(user_name)) {
        printf("\nDevice Authorized\n");
        
    if (g_server->start()) {
         
   

     printf("Erza Proxy is Running...\n");
        printf("Erza Proxy Online!!\n");
        
        printf("U can now login growtopia\n");
        while (true) {
            g_server->poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
 
        }
    }  
    }
    
    else
        printf("Failed to connect Erza Proxy or Key Wrong!\n");
};
