#pragma once
#include "enet/include/enet.h"
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include "proton/vector.hpp"
#include "proton/variant.hpp"
#include <mutex>
#include <queue>
#include "packet.h"
#include <vector>
#include <thread>
#include "server.h"


//return value: true - dont send original packet, false - send original packet
namespace events {

    namespace out {
        bool variantlist(gameupdatepacket_t* packet);
        bool pingreply(gameupdatepacket_t* packet);
        bool generictext(std::string packet);
        bool gamemessage(std::string packet);
        bool state(gameupdatepacket_t* packet);

    }; // namespace out
    namespace in {
        bool variantlist(gameupdatepacket_t* packet);
        bool generictext(std::string packet);
        bool gamemessage(std::string packet); 
        bool sendmapdata(gameupdatepacket_t* packet);
        bool state(gameupdatepacket_t* packet);
        bool tracking(std::string packet);
    }; // namespace in
};     // namespace events



