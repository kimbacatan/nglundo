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

server* g_server = new server();

bool isInside(int circle_x, int circle_y, int rad, int x, int y) {
    // Compare radius of circle with distance
    // of its center from given point
    if ((x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad)
        return true;
    else
        return false;
}

void UpdateMap()
{
    while (true)
    {
        try {
            if (g_server->m_world.connected)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(20ms));
                for (auto& tile : g_server->m_world.tiles) {
                    if (tile.second.header.foreground != 0) {
                        if (tile.second.header.foreground != 6 && tile.second.header.foreground != 410 && tile.second.header.foreground != 20 && tile.second.header.foreground != 26 && tile.second.header.foreground != 608 &&
                            tile.second.header.foreground != 780 && tile.second.header.foreground != 102 && tile.second.header.foreground != 1222 && tile.second.header.foreground != 4422 && tile.second.header.foreground != 2978 &&
                            tile.second.header.foreground != 3524 && tile.second.header.foreground != 762 && tile.second.header.foreground != 4632 && tile.second.header.foreground != 1308 && tile.second.header.foreground != 2862 &&
                            tile.second.header.foreground != 4798 && tile.second.header.foreground != 9740 && tile.second.header.foreground != 4240 && tile.second.header.foreground != 846 && tile.second.header.foreground != 5616 &&
                            tile.second.header.foreground != 9198 && tile.second.header.foreground != 1528 && tile.second.header.foreground != 3002 && tile.second.header.foreground != 430 && tile.second.header.foreground != 5036 &&
                            tile.second.header.foreground != 7444 && tile.second.header.foreground != 482 && tile.second.header.foreground != 12 && tile.second.header.foreground != 22 && tile.second.header.foreground != 16 &&
                            tile.second.header.foreground != 954 && tile.second.header.foreground != 3898 && tile.second.header.foreground != 1042 && tile.second.header.foreground != 6854 && tile.second.header.foreground != 8260 &&
                            tile.second.header.foreground != 5666 && tile.second.header.foreground != 340 && tile.second.header.foreground != 4722 && tile.second.header.foreground != 598 && tile.second.header.foreground != 2810 &&
                            tile.second.header.foreground != 554 && tile.second.header.foreground != 60 && tile.second.header.foreground != 1450 && tile.second.header.foreground != 8682 && tile.second.header.foreground != 5054 &&
                            tile.second.header.foreground != 4202 && tile.second.header.foreground != 3804 && tile.second.header.foreground != 4482 && tile.second.header.foreground != 1104 && tile.second.header.foreground != 4782 &&
                            tile.second.header.foreground != 3806 && tile.second.header.foreground != 2948 && tile.second.header.foreground != 8676 && tile.second.header.foreground != 858 && tile.second.header.foreground != 4740 &&
                            tile.second.header.foreground != 3796 && tile.second.header.foreground != 1700 && tile.second.header.foreground != 3232 && tile.second.header.foreground != 3572 && tile.second.header.foreground != 3566 &&
                            tile.second.header.foreground != 484 && tile.second.header.foreground != 5034 && tile.second.header.foreground != 546 && tile.second.header.foreground != 5032 && tile.second.header.foreground != 1446 &&
                            tile.second.header.foreground != 1604 && tile.second.header.foreground != 7164 && tile.second.header.foreground != 5040 && tile.second.header.foreground != 1684 && tile.second.header.foreground != 1702 &&
                            tile.second.header.foreground != 4704 && tile.second.header.foreground != 4706 && tile.second.header.foreground != 2072 && tile.second.header.foreground != 1162 && tile.second.header.foreground != 1240 &&
                            tile.second.header.foreground != 1770 && tile.second.header.foreground != 1420 && tile.second.header.foreground != 2586 && tile.second.header.foreground != 1422 && tile.second.header.foreground != 3522 &&
                            tile.second.header.foreground != 658 && tile.second.header.foreground != 428 && tile.second.header.foreground != 224 && tile.second.header.foreground != 4720 && tile.second.header.foreground != 998 &&
                            tile.second.header.foreground != 1326 && tile.second.header.foreground != 1752 && tile.second.header.foreground != 1324 && tile.second.header.foreground != 1682 && tile.second.header.foreground != 30 &&
                            tile.second.header.foreground != 4794 && tile.second.header.foreground != 4546 && tile.second.header.foreground != 3808 && tile.second.header.foreground != 10076 && tile.second.header.foreground != 10078 &&
                            tile.second.header.foreground != 2252 && tile.second.header.foreground != 2274 && tile.second.header.foreground != 62 && tile.second.header.foreground != 480 && tile.second.header.foreground != 24 &&
                            tile.second.header.foreground != 5660 && tile.second.header.foreground != 8020 && tile.second.header.foreground != 2244 && tile.second.header.foreground != 2242 && tile.second.header.foreground != 2246 &&
                            tile.second.header.foreground != 2248 && tile.second.header.foreground != 190 && tile.second.header.foreground != 192 && tile.second.header.foreground != 188 && tile.second.header.foreground != 758 &&
                            tile.second.header.foreground != 1256 && tile.second.header.foreground != 5468 && tile.second.header.foreground != 3072 && tile.second.header.foreground != 4352 && tile.second.header.foreground != 2272 &&
                            tile.second.header.foreground != 8994 && tile.second.header.foreground != 1482 && tile.second.header.foreground != 379 && tile.second.header.foreground != 10776 && tile.second.header.foreground != 9614 &&
                            tile.second.header.foreground != 886 && tile.second.header.foreground != 486 && tile.second.header.foreground != 1048 && tile.second.header.foreground != 3286 && tile.second.header.foreground != 3496 &&
                            tile.second.header.foreground != 3832 && tile.second.header.foreground != 756 && tile.second.header.foreground != 1436 && tile.second.header.foreground != 9268 && tile.second.header.foreground != 8634 &&
                            tile.second.header.foreground != 7362 && tile.second.header.foreground != 550 && tile.second.header.foreground != 286 && tile.second.header.foreground != 444 && tile.second.header.foreground != 2964 &&
                            tile.second.header.foreground != 1288 && tile.second.header.foreground != 854 && tile.second.header.foreground != 9330 && tile.second.header.foreground != 7984 && tile.second.header.foreground != 7888 &&
                            tile.second.header.foreground != 652 && tile.second.header.foreground != 1108 && tile.second.header.foreground != 1594 && tile.second.header.foreground != 398 && tile.second.header.foreground != 1434 &&
                            tile.second.header.foreground != 1304 && tile.second.header.foreground != 926 && tile.second.header.foreground != 656 && tile.second.header.foreground != 544 && tile.second.header.foreground != 1698 &&
                            tile.second.header.foreground != 974 && tile.second.header.foreground != 1694 && tile.second.header.foreground != 2646 && tile.second.header.foreground != 2068 && tile.second.header.foreground != 688 &&
                            tile.second.header.foreground != 1432 && tile.second.header.foreground != 9080 && tile.second.header.foreground != 686 && tile.second.header.foreground != 3126 && tile.second.header.foreground != 4698 &&
                            tile.second.header.foreground != 986 && tile.second.header.foreground != 4712 && tile.second.header.foreground != 5792 && tile.second.header.foreground != 6146 && tile.second.header.foreground != 5798 &&
                            tile.second.header.foreground != 3794 && tile.second.header.foreground != 6772 && tile.second.header.foreground != 1696 && tile.second.header.foreground != 4718 && tile.second.header.foreground != 596) {
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 596 && tile.second.header.flags_1 == 32) { //Chest
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 596 && tile.second.header.flags_1 == 0) { //Chest
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 4712 && tile.second.header.flags_1 == 64) { //Gorilla
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 3126 && tile.second.header.flags_1 == 1) { //Dark Magic Barrier
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 3126 && tile.second.header.flags_1 == 0) { //Dark Magic Barrier
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 3126 && tile.second.header.flags_1 == 32) { //Dark Magic Barrier
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 686 && tile.second.header.flags_1 == 1) { //Jail Door
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 686 && tile.second.header.flags_1 == 0) { //Jail Door
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 686 && tile.second.header.flags_1 == 32) { //Jail Door
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 3286 && tile.second.header.flags_1 == 1024) { //Steam Door
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 3286 && tile.second.header.flags_1 == 1056) { //Steam Door
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 3798 && tile.second.header.flags_1 == 1) { //Vip Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 3798 && tile.second.header.flags_1 == 0) { //Vip Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 3798 && tile.second.header.flags_1 == 32) { //Vip Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 4352 && tile.second.header.flags_1 == 0) { //Wolf Gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 4352 && tile.second.header.flags_1 == 32) { //Wolf Gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 224 && tile.second.header.flags_1 == 0) { //House Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 224 && tile.second.header.flags_1 == 32) { //House Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 224 && tile.second.header.flags_1 == 48) { //House Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 224 && tile.second.header.flags_1 == 24) { //House Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 224 && tile.second.header.flags_1 == 288) { //House Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 4240 && tile.second.header.flags_1 == 0) { //Jade Portcullis
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 4240 && tile.second.header.flags_1 == 32) { //Jade Portcullis
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 4240 && tile.second.header.flags_1 == 24) { //Jade Portcullis
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 1162 && tile.second.header.flags_1 == 0) { //Forcefield
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 1162 && tile.second.header.flags_1 == 32) { //Forcefield
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 1162 && tile.second.header.flags_1 == 24) { //Forcefield
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 4706 && tile.second.header.flags_1 == 0) { //Adventure Barrier
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 7164 && tile.second.header.flags_1 == 0) { //Red Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 7164 && tile.second.header.flags_1 == 32) { //Red Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 7164 && tile.second.header.flags_1 == 24) { //Red Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 7164 && tile.second.header.flags_1 > 1000) { //Red Entrance
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5032 && tile.second.header.flags_1 == 32) { //Dirt Gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5032 && tile.second.header.flags_1 == 0) { //Dirt Gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5032 && tile.second.header.flags_1 == 24) { //Dirt Gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5032 && tile.second.header.flags_1 == 16) { //Dirt Gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 60 && tile.second.header.flags_1 == 0) { //portuculis
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 60 && tile.second.header.flags_1 == 32) { //portuculis
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 60 && tile.second.header.flags_1 == 288) { //portuculis
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 2810 && tile.second.header.flags_1 == 0) { //air vent
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 2810 && tile.second.header.flags_1 == 32) { //air vent
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 2810 && tile.second.header.flags_1 == 24) { //air vent
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 598 && tile.second.header.flags_1 == 0) { //dragon gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 598 && tile.second.header.flags_1 == 32) { //dragon gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 598 && tile.second.header.flags_1 == 16) { //dragon gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 598 && tile.second.header.flags_1 == 128) { //dragon gate
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5036 && tile.second.header.flags_1 == 0) { //hidden door 3 VV
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5036 && tile.second.header.flags_1 == 32) { //hidden door 3 VV
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5036 && tile.second.header.flags_1 == 24) { //hidden door 3 VV
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5036 && tile.second.header.flags_1 == 50) { //hidden door 3 VV
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        if (tile.second.header.foreground == 5036 && tile.second.header.flags_1 > 1000) { //hidden door 3 VV
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }

                        if (tile.second.header.flags_1 == 25) {
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.flags_1 == 17) {
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.flags_1 == 19) {
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.flags_1 == 27) {
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.flags_1 == 128) {
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 1162 && tile.second.header.flags_1 == 128) {
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 1042 && tile.second.header.flags_1 == 1) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 6854 && tile.second.header.flags_1 == 1) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 20 && tile.second.header.flags_1 == 1) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 428 && tile.second.header.flags_1 == 1) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 430 && tile.second.header.flags_1 == 1) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 546 && tile.second.header.flags_1 == 1) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 544 && tile.second.header.flags_1 == 1) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 986 && tile.second.header.flags_1 == 1) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 8802 && tile.second.header.flags_1 == 16) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 2272 && tile.second.header.flags_1 == 0) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 8220) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 6154 && tile.second.header.flags_1 == 0) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                        }
                        if (tile.second.header.foreground == 6154 && tile.second.header.flags_1 == 64) { //sumthing lol ahaha
                            g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 1;
                        }
                        //986
                    }
                    if (tile.second.header.foreground == 0) {
                        g_server->gtmap[tile.second.pos.m_y][tile.second.pos.m_x] = 0;
                    }
                }

            }
        }
        catch (...)
        {
        }
    }
}


int main() {
#ifdef _WIN32
    SetConsoleTitleA("Erza Proxy");
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
        printf("\nNow u can login growtopia\n");
        while (true) {
            g_server->poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
 
        }
    }  
    }
    
    else
        printf("Failed to connect Erza Proxy or Key Wrong!\n");
};
