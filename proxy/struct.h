#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <ctime>
#include <functional>
#include <iostream>
#include "enet/include/enet.h"
#include "proton/variant.hpp"
#include "proton/rtparam.hpp"
#include "utils.h"
#include "packet.h"
#include "server.h"
#include "events.h"
#include "PathFinder.h"

struct Item {
	uint16_t id;
	uint8_t count;
	uint8_t type;
};

struct PlayerInventory {
	uint32_t slotCount;
	uint16_t itemCount;
	std::unordered_map<uint32_t, Item> items;

	bool isItemEquipped(uint32_t itemID) {
		return doesItemExistUnsafe(itemID) ? items[itemID].type == 1 : false;
	}

	bool doesItemExist(uint32_t itemID) {
		return doesItemExistUnsafe(itemID);
	}

	bool doesItemExistUnsafe(uint32_t itemID) {
		return items.find(itemID) != items.end();
	}

	int getItemCount(uint32_t itemID) {
		return getItemCountUnsafe(itemID);
	}

	int getItemCountUnsafe(uint32_t itemID) {
		return doesItemExistUnsafe(itemID) ? items.find(itemID)->second.count : 0;
	}

	int getObjectAmountToPickUp(DroppedItem obj) {
		return getObjectAmountToPickUpUnsafe(obj);
	}

	int getObjectAmountToPickUpUnsafe(DroppedItem obj) {
		int count = getItemCountUnsafe(obj.itemID);
		return count ? (count < 200 ? (200 - count < obj.count ? 200 - count : obj.count) : 0) : (slotCount > items.size() ? obj.count : 0);
	}
};


struct Player {
	std::string name;
	std::string country;
	int netid = -1;
	int userid = -1;
	int state = 0;
	vector2_t pos{};
	bool invis = false;
	bool mod = false;

	virtual ~Player() = default;
	virtual vector2_t GetPos() const {
		return pos;
	}
};


struct LocalPlayer : Player {
PathFinder pf = PathFinder(100,60);
	PlayerInventory inventory;
	uint32_t gems_balance = -1;
	uint32_t wl_balance = -1;
	uint32_t level = -1;
	uint32_t awesomeness = -1;

vector2_t GetPos() const override {
		return pos;
	}
};
