#pragma once
#include <fstream>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include "utils.h"
#include "player.h"
//#include "struct.h"//
#include "gt.hpp"
using namespace std;

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

int lastDroppedUid = 0;

std::unordered_map<uint32_t, DroppedItem> objects;

void LoadFromMem(gameupdatepacket_t* packet) {
		try
		{
			auto extended = utils::get_extended(packet);
			
int droppedCount;
				memcpy(&droppedCount, extended, 4);
				memcpy(&lastDroppedUid, extended + 4, 4);
				extended += 8;
				//gt::send_log("Count: " + to_string(droppedCount) + " last uid: " + to_string(lastDroppedUid));

				for (int i = 0; i < droppedCount; i++) {
					DroppedItem item;
					memcpy(&item.itemID, extended, 2);
					memcpy(&item.pos.m_x, extended + 2, 4);
					memcpy(&item.pos.m_y, extended + 6, 4);
					memcpy(&item.count, extended + 10, 1);
					memcpy(&item.flags, extended + 11, 1);
					memcpy(&item.uid, extended + 12, 4);
					extended += 16;
					objects[item.uid] = item;
				}
				connected = true;
			
		}
		catch (const std::exception&)
		{
			gt::send_log("`4Unable To serialize this world");
		}
}
	
};

