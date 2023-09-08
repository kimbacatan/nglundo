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
#include "discord-rpc.h"

server* g_server = new server();


int main() {
#ifdef _WIN32
    SetConsoleTitleA("Erza Proxy");
    DiscordEventHandlers handlers;
#endif
Discord_Initialize("1149579895886852146", &handlers, 1, NULL); // id yaz buraya

    DiscordRichPresence presence;
    memset(&presence, 0, sizeof(presence));
    presence.state = "In-Game"; // Ã–rneÄŸin "Ã‡evrimiÃ§i" veya "Oyunda"
    presence.details = "https://discord.gg/GeQ8mcU2Qt"; // Ã–rneÄŸin "Hikaye Modu" veya "Ã‡evrimiÃ§i Multiplayer"
    presence.largeImageKey = "20230908_123912"; // knk dc devportala ekleyeceÄŸin anahtar varya
    presence.largeImageText = "Currently playing Erza Proxy";
    Discord_UpdatePresence(&presence);
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
        printf("Erza Proxy Online!!\n\n");
        printf("Now u can login growtopia");
        while (true) {
            g_server->poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
 
        }
    }  
    }
    
    else
        printf("Failed to connect Erza Proxy or Key Wrong!\n");
};
