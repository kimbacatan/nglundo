#pragma once
#include <fstream>
#include <string>
//#include <unordered_map>//
#include <iostream>
#include <vector>
#include "utils.h"
#include "player.h"
//#include "struct.h"//

struct DroppedItem {
	uint16_t itemID;
	vector2_t pos;
	uint8_t count;
	uint8_t flags;
	uint32_t uid;
};


class world {
   public:
    std::string name{};
    std::vector<player> players{};
    player local{};
    bool connected{};
};

