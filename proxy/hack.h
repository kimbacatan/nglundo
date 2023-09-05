#pragma once
#include <stdint.h>
#include <string>
#include <vector>
#include "enet/include/enet.h"
#include "packet.h"
#include "proton/variant.hpp"


namespace commands {
    std::pair<int, int> DropDLWL(int count, int tax);
}
