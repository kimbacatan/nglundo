#include "gt.hpp"
#include "packet.h"
#include "server.h"
#include "utils.h"
#include "Pathfinder/PathFinder.h"

std::string gt::version = "4.35";
std::string gt::flag = "id";
bool gt::resolving_uid2 = false;
bool gt::connecting = false;
bool gt::in_game = false;
bool gt::ghost = false;
int gt::total_bet = 0;
bool gt::game_started = false;
int gt::lastCollect1 = 0;
int gt::lastCollect2 = 0;
int gt::fakeFastDrop = 0;
int gt::path_amount = 0;


void gt::send_log(std::string text) {
    g_server->send(true, "action|log\nmsg|" + text, NET_MESSAGE_GAME_MESSAGE);
}

void gt::findpath(int x, int y)
{
    typedef pair<int, int> Pair;
    Pair src((int)g_server->m_world.local.pos.m_x / 32, (int)g_server->m_world.local.pos.m_y / 32);
    Pair dest((int)x, (int)y);
    Pathfinder* pathfinder = new Pathfinder(100, 60);
    for (int i = 0; i < pathfinder->width; i++) {
        for (int j = 0; j < pathfinder->height; j++) {
            pathfinder->nodes->insert(std::pair<Pathfinder::Point, int>(Pathfinder::Point(i, j), g_server->gtmap[j][i]));
        }
    }
    std::vector<Pathfinder::Point> path = pathfinder->findPath(Pathfinder::Point(src.first, src.second), Pathfinder::Point(dest.first, dest.second));
    if (path.size() < 35) {
        for (int i = 0; i < path.size(); i++) {
            GameUpdatePacket packet{ 0 };
            packet.type = PACKET_STATE;
            packet.int_data = 2250;
            packet.int_x = path[i].x;
            packet.int_y = path[i].y;
            packet.pos_x = path[i].x * 32;
            packet.pos_y = path[i].y * 32;
            packet.flags = 32 | (1 << 10) | (1 << 11);
            g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&packet, sizeof(GameUpdatePacket));
           
        }
    }
    else {
        for (int i = 0; i < path.size(); i++) {
            GameUpdatePacket packet{ 0 };
            packet.type = PACKET_STATE;
            packet.int_data = 2250;
            packet.int_x = path[i].x;
            packet.int_y = path[i].y;
            packet.pos_x = path[i].x * 32;
            packet.pos_y = path[i].y * 32;
            packet.flags = 32 | (1 << 10) | (1 << 11);

            g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&packet, sizeof(GameUpdatePacket));
        }
    }
    gt::path_amount = 0;
}
