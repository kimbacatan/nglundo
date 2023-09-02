#pragma once
#include <string>

namespace gt {
    extern std::string version;
    extern std::string flag;
    extern bool resolving_uid2;
    extern bool connecting;
    extern bool in_game;
    extern bool ghost;
extern int total_bet;
extern bool game_started;
extern int lastCollect1;
    extern int lastCollect2;
extern int fakeFastDrop;
    void send_log(std::string text);
}
