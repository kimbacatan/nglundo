#include "events.h"
#include "gt.hpp"
#include "proton/hash.hpp"
#include "proton/rtparam.hpp"
#include "proton/variant.hpp"
#include "proton/vector.hpp"
#include "server.h"
#include "utils.h"
#include <thread>
#include <limits.h>
#include <stdio.h> /* printf, NULL */ 
#include <stdlib.h> /* srand, rand */ 
#include <time.h> /* time */
#include <curl/curl.h>
#include "world.h"
using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

float hair_change, shirt_change, pant_change = 0.f;
float shoes_change, eye_change, hand_change = 0.f;
float wing_change, neck_change = 0.f;
float ances_change = 0;
float hat_change = 0.f;
std::string hat_changes = "0"; 
std::string eye_changes = "0";
std::string shirt_changes = "0";
std::string wing_changes = "0";
std::string shoes_changes = "0";
std::string hand_changes = "0";
std::string neck_changes = "0";
std::string hair_changes = "0";
std::string pant_changes = "0";
std::string ances_changes = "0";
bool dropwl = false;
bool dropdl = false;
bool dropbgl = false;
bool cdrop = false;
bool block_wrench = false;
std::string wrench_dialog = "0";
std::string wrench_block = "0";
std::string effpart = "";
int bruh;
int bruh2;
int bruh3;
int bruh4;
std::string taxstring = "";
int taxcount;
std::string value = "";



bool fastdrop2 = false;
bool saveset = true;

vector2_t ppos1;
vector2_t ppos2;
vector2_t ppos3;
vector2_t ppos4;
vector2_t pposback;






void tptopos(float x, float y)
{
    vector2_t pos;
    pos.m_x = x;
    pos.m_y = y;
    variantlist_t varlist{ "OnSetPos" };
    varlist[1] = pos;
    g_server->m_world.local.pos = pos;
    g_server->send(true, varlist, g_server->m_world.local.netid, -1);
}


bool dropitem(int itemid, string count) {
    cdrop = true;
    g_server->send(false, "action|drop\nitemID|" + std::to_string(itemid));
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + count); //242
    return true;
}

int balance() {
    int wl = 0;
    wl += g_server->local_player.inventory.getItemCount(242);
    wl += g_server->local_player.inventory.getItemCount(1796) * 100;
    wl += g_server->local_player.inventory.getItemCount(7188) * 10000;
    return wl;
}

int item_count(int itemid) {
    int wl = g_server->local_player.inventory.getItemCount(itemid);
    return wl;
}


int qq_function(int num) {
    return num % 10;
}
int reme_function(int num) {
    int sum = 0;
    while (num > 0) {
        sum = sum + (num % 10);
        num = num / 10;
    }
    return sum;
}
string to_lower(string s) {
    for (char& c : s)
        c = tolower(c);
    return s;
}

void force() {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    fastdrop2 = false;
}

void Sleep(int milliseconds) {
    this_thread::sleep_for(chrono::microseconds(milliseconds));
}


bool custom_drop(int jumlahcd, vector2_t pos, float m_x, float m_y) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    string cdropcount = to_string(jumlahcd);
    if (balance() < jumlahcd) {
        gt::send_log("`9Dont have `#balance`9. balance: " + to_string(balance()) + ".");
        return true;
    }
    if (jumlahcd < 100) {

        if (item_count(242) < jumlahcd) {
            gameupdatepacket_t yahacdrop{ 0 };
            yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
            yahacdrop.m_int_data = 1796;
            g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        dropwl = true;
        g_server->send(false, "action|drop\n|itemID|242");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + cdropcount); //242
        gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
    }

    else if (jumlahcd > 10000) {


        int jumlahcd1 = (jumlahcd / 10000);

        int halohai = ((jumlahcd / 100) - (jumlahcd1 * 100));
        int halohai1 = jumlahcd - ((halohai * 100) + (jumlahcd1 * 10000));
        if (halohai > item_count(1796)) {
            gameupdatepacket_t yahacdrop{ 0 };
            yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
            yahacdrop.m_int_data = 7188;
            g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        else if (item_count(242) < halohai1) {
            gameupdatepacket_t yahacdrop{ 0 };
            yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
            yahacdrop.m_int_data = 1796;
            g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        dropbgl = true;
        g_server->send(false, "action|drop\n|itemID|7188");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + std::to_string(jumlahcd1)); //242

        dropdl = true;
        g_server->send(false, "action|drop\n|itemID|1796");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string(halohai)); //242

        dropwl = true;
        g_server->send(false, "action|drop\n|itemID|242");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + std::to_string(halohai1)); //242

        gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
    }
    else {
        int jumlahcd1 = (jumlahcd / 100);
        int halohai = (jumlahcd % 100);

        if (item_count(242) < halohai) {
            gameupdatepacket_t yahacdrop{ 0 };
            yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
            yahacdrop.m_int_data = 1796;
            g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

        }
        else if (item_count(1796) < jumlahcd1) {
            gameupdatepacket_t yahacdrop{ 0 };
            yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
            yahacdrop.m_int_data = 242;
            g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

        }
        dropdl = true;
        g_server->send(false, "action|drop\n|itemID|1796");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string(jumlahcd1)); //242

        dropwl = true;
        g_server->send(false, "action|drop\n|itemID|242");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + std::to_string(halohai)); //242

        gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
    }
    gt::total_bet = 0;
}


bool events::out::variantlist(gameupdatepacket_t* packet) {
    variantlist_t varlist{};
    varlist.serialize_from_mem(utils::get_extended(packet));
    PRINTS("varlist: %s\n", varlist.print().c_str());
    return false;
}

    



bool events::out::pingreply(gameupdatepacket_t* packet) {
    //since this is a pointer we do not need to copy memory manually again
    packet->m_vec2_x = 1000.f;  //gravity
    packet->m_vec2_y = 250.f;   //move speed
    packet->m_vec_x = 64.f;     //punch range
    packet->m_vec_y = 64.f;     //build range
    packet->m_jump_amount = 0;  //for example unlim jumps set it to high which causes ban
    packet->m_player_flags = 0; //effect flags. good to have as 0 if using mod noclip, or etc.
    return false;
}

    

	






bool find_command(std::string chat, std::string name) {
    bool found = chat.find("/" + name) == 0;
    if (found)
        gt::send_log("`6" + chat);
    return found;
}
bool wrench = false;
bool fastdrop = false;
bool fasttrash = false;
bool wrenchmsg = false; 
bool wrenchspam = false; 
bool automessage = false; 
bool autopull = false;
bool pullauto = false; 
bool setmsg = false;
bool enabled_color = false;
bool son = false;
std::string aspam = "";
std::string swxs = "0";
std::string pos1xm = "";
std::string pos1ym = "";
std::string pos2xm = "";
std::string pos2ym = "";
std::string pos3xm = "";
std::string pos3ym = "";
std::string pos4xm = "";
std::string pos4ym = "";
std::string posbackxm = "";
std::string posbackym = "";
int delay = 0;
std::string message = "";
std::string mode = "pull";
bool events::out::generictext(std::string packet) {
	    
    //PRINTS("Generic text: %s\n", packet.c_str());
    auto& world = g_server->m_world;
    rtvar var = rtvar::parse(packet);
    if (!var.valid())
        return false;
	
	if (packet.find("vmode") != -1) {
        try {
            std::string aaa = packet.substr(packet.find("ode|") + 4, packet.size());
            std::string number = aaa.c_str();
            while (!number.empty() && isspace(number[number.size() - 1]))
                number.erase(number.end() - (76 - 0x4B));
            wrench = stoi(number);
        }
        catch (exception a)
        {
            gt::send_log("`4Critical Error: `2override detected");

        }
    }
    if (packet.find("vblockdialog") != -1) {
        try {
            std::string aaa = packet.substr(packet.find("log|") + 4, packet.size());
            std::string number = aaa.c_str();
            while (!number.empty() && isspace(number[number.size() - 1]))
                number.erase(number.end() - (76 - 0x4B)); 
            block_wrench = stoi(number);
        }
        catch (exception a)
        {
            gt::send_log("`4Critical Error: `2override detected");

        }
    }
    if (wrench == true) {
        if (packet.find("action|wrench") != -1) {
            g_server->send(false, packet);

            std::string str = packet.substr(packet.find("netid|") + 6, packet.length() - packet.find("netid|") - 1);
            std::string gta5 = str.substr(0, str.find("|"));
            if (mode == "`9Pull") {
                g_server->send(false, "action|dialog_return\ndialog_name|popup\nnetID|" + gta5 + "|\nnetID|" + gta5 + "|\nbuttonClicked|pull");
            }
            if (mode == "`9Kick") {
                g_server->send(false, "action|dialog_return\ndialog_name|popup\nnetID|" + gta5 + "|\nnetID|" + gta5 + "|\nbuttonClicked|kick");
            }
            if (mode == "`9Ban") {
                g_server->send(false, "action|dialog_return\ndialog_name|popup\nnetID|" + gta5 + "|\nnetID|" + gta5 + "|\nbuttonClicked|worldban");
            }
            variantlist_t varlist{ "OnTextOverlay" };
            varlist[1] = "Successfuly " + mode + "`` netID: " + gta5;
            g_server->send(true, varlist);
            return true;
        }
    }
    if (packet.find("buttonClicked|Pull") != -1) {
        mode = "`9Pull";

    }
    if (packet.find("buttonClicked|Ban") != -1) {

        mode = "`9Ban";

    }
    if (packet.find("buttonClicked|Kick") != -1) {

        mode = "`9Kick";
    }

	
		
	
	
if (packet.find("spam_text") != -1) {
        try {
            if (packet.find("c_text|") != -1) {
                std::string aaa = packet.substr(packet.find("ext|") + 4, packet.size());
                std::string number = aaa.c_str();
                while (!number.empty() && isspace(number[number.size() - 1]))
                    number.erase(number.end() - (76 - 0x4B));
                enabled_color = stoi(number);
            }
            if (packet.find("auto_enable|") != -1) {
                std::string aaa = packet.substr(packet.find("ble|") + 4, packet.size());
                std::string number = aaa.c_str();
                while (!number.empty() && isspace(number[number.size() - 1]))
                    number.erase(number.end() - (76 - 0x4B));
                son = stoi(number);
            }
            if (packet.find("spam_msg|") != -1) {
                std::string msg = packet.substr(packet.find("spam_msg|") + 9, packet.length() - packet.find("spam_msg") - 1);
                aspam = msg;
            }
            if (packet.find("delay_msg|") != -1) {
                std::string msg = packet.substr(packet.find("delay_msg|") + 10, packet.length() - packet.find("delay_msg") - 1);
                delay = stoi(msg);
            }

        }
        catch (exception a) {
            //std::cout << "error?";
            //std::cout << a.what();
        }
        return true;
    }


	
    if (var.get(0).m_key == "action" && var.get(0).m_value == "input") {
        if (var.size() < 2)
            return false;
        if (var.get(1).m_values.size() < 2)
            return false;

        if (!world.connected)
            return false;

        auto chat = var.get(1).m_values[1];
        
	    
	           if (find_command(chat, "legend")) {
            auto& visuals = g_server->m_world.local;
            variantlist_t va{ "OnNameChanged" };
            va[1] = "``" + visuals.name + " of Legend``";
            g_server->send(true, va, world.local.netid, -1);
            gt::send_log("name set to: " + visuals.name + " of Legend");
            return true;
        }
        else if (find_command(chat, "mentor")) {
            std::string mn = "|showGuild|master";

            variantlist_t mentor{ "OnCountryState" };
            mentor[1] = mn.c_str();
            g_server->send(true, mentor, g_server->m_world.local.netid, -1);
            return true;
        }
        else if (find_command(chat, "maxlevel")) {
            std::string packet125level = "us|showGuild|maxLevel";

            variantlist_t packet123{ "OnCountryState" };
            packet123[1] = packet125level.c_str();
            g_server->send(true, packet123, g_server->m_world.local.netid, -1);
            return true;
        }
        else if (find_command(chat, "g4g")) {
            std::string packet125level = "us|showGuild|donor";

            variantlist_t packet123{ "OnCountryState" };
            packet123[1] = packet125level.c_str();
            g_server->send(true, packet123, g_server->m_world.local.netid, -1);
            return true;
            //visuals end
        }
        else if (find_command(chat, "name ")) { //ghetto solution, but too lazy to make a framework for commands.
            std::string name = "``" + chat.substr(6) + "``";
            variantlist_t va{ "OnNameChanged" };
            va[1] = name;
            g_server->send(true, va, world.local.netid, -1);
            gt::send_log("`#name set to: " + name);
            return true;
        } else if (find_command(chat, "flag ")) {
            int flag = atoi(chat.substr(6).c_str());
            variantlist_t va{ "OnGuildDataChanged" };
            va[1] = 1;
            va[2] = 2;
            va[3] = flag;
            va[4] = 3;
            g_server->send(true, va, world.local.netid, -1);
            gt::send_log("flag set to item id: " + std::to_string(flag));
            return true;
        }  else if (find_command(chat, "country ")) {
            std::string cy = chat.substr(9);
            gt::flag = cy;
            gt::send_log("`#your country set to " + cy + ", (Relog to game to change it successfully!)");
            return true;
        }
        else if (find_command(chat, "fd")) {
            fastdrop = !fastdrop;
            if (fastdrop)
                gt::send_log("`#Fast Drop is now enabled.");
            else
                gt::send_log("`#Fast Drop is now disabled.");
            return true;
        }
        else if (find_command(chat, "ft")) {
            fasttrash = !fasttrash;
            if (fasttrash)
                gt::send_log("`#Fast Trash is now enabled.");
            else
                gt::send_log("`#Fast Trash is now disabled.");
            return true;
        }        

else if (find_command(chat, "particle")) {
	auto& bruh = g_server->m_world.local;
effpart = chat.substr(10);
	int totfect = std::stoi(effpart);
	variantlist_t varlist{"OnParticleEffect"};
        varlist[1] = totfect;
        varlist[2] = vector2_t{ bruh.pos.m_x,  bruh.pos.m_y};
        varlist[3] = 0;
        varlist[4] = 0;
        g_server->send(true, varlist);
        
        gt::send_log("`9Particle effect number : " + effpart);
        return true;
        }



	
	else if (find_command(chat, "tax ")) {
taxstring = chat.substr(5);
 taxcount = stoi(taxstring);
		gt::send_log("`9Tax set to : " + taxstring + "%");
		return true;
	}

else if (find_command(chat, "game ")) { //dropwl
            value = chat.substr(6);
            bruh = stoi(value) % 10;
            bruh2 = stoi(value) * 2;
	std::string value2 = to_string(bruh2);
            if (bruh == 1) {
                bruh2 = bruh2 - 1;
            }
            if (bruh == 2) {
                bruh2 = bruh2 - 2;
            }
            if (bruh == 3) {
                bruh2 = bruh2 - 3;
            }
            if (bruh == 4) {
                bruh2 = bruh2 - 4;
            }
            if (bruh == 5) {
                bruh2 = bruh2 + 5;
            }
            if (bruh == 6) {
                bruh2 = bruh2 + 4;
            }
            if (bruh == 7) {
                bruh2 = bruh2 + 3;
            }
            if (bruh == 8) {
                bruh2 = bruh2 + 2;
            }
            if (bruh == 9) {
                bruh2 = bruh2 + 1;
            }
            bruh3 = bruh2 * taxcount / 100;
            bruh4 = stoi(value2) - bruh3;
	if (taxstring == "") {
gt::send_log("`9Set tax game first using /tax <amount>");
	}
	else {
            gt::send_log("`9Total Bet : " + value2 + " , Tax setted : " + taxstring + "%");
	gt::send_log("`2" + value2 + " - " + taxstring + "% `9= " + to_string(bruh4) + " `9taken `2" + to_string(bruh3) + " wls");
}
            return true;
        }


	
             else if (find_command(chat, "autopull")) {
            autopull = !autopull;
            if (autopull)
                gt::send_log("`#autopull is now enabled.");
            else
                gt::send_log("`#autopull is now disabled.");
            return true;
         } 
            else if (find_command(chat, "pullauto")) {
            pullauto = !pullauto;
            if (pullauto)
                gt::send_log("`#Pull Auto is now enabled.");
            else
                gt::send_log("`#Pull Auto is now disabled.");
            return true;
         }                  

		    
                        
else if (find_command(chat, "cdrop ")) {
	std::string cdropcount = chat.substr(7);
	int jumlahcd = stoi(cdropcount);

	if (balance() < jumlahcd) {
                    gt::send_log("`9Dont have `#balance`9. balance: " + to_string(balance()) + ".");
                    return true;
                }
	
	if (jumlahcd < 100) {
		if (item_count(242) < jumlahcd) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
		dropwl = true;
		g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + cdropcount); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
                }
		
		else if (jumlahcd > 10000) {
			int jumlahcd1 = (jumlahcd / 10000);
			int halohai = ((jumlahcd / 100) - (jumlahcd1 * 100));
			int halohai1 = jumlahcd - ((halohai * 100) + (jumlahcd1 * 10000));
			if (halohai > item_count(1796)) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 7188;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
                    else if (item_count(242) < halohai1) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
			dropbgl = true;
			g_server->send(false, "action|drop\n|itemID|7188");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + std::to_string(jumlahcd1)); //242
                    dropdl = true;
                    g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string(halohai)); //242
                    dropwl = true;
                    g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + std::to_string(halohai1)); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
			}
		
		else {
			int jumlahcd1 = (jumlahcd / 100);
			int halohai = (jumlahcd % 100);
if (item_count(242) < halohai) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));

                    }
                    else if (item_count(1796) < jumlahcd1) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 242;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));

                    }

			dropdl = true;
			g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string(jumlahcd1)); //242
                    dropwl = true;
                    g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + std::to_string(halohai)); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
                
            }
    
        return true;
	}

else if (find_command(chat, "cd ")) {
	std::string cdropcount = chat.substr(4);
	int jumlahcd = stoi(cdropcount);

	if (balance() < jumlahcd) {
                    gt::send_log("`9Dont have `#balance`9. balance: " + to_string(balance()) + ".");
                    return true;
                }
	
	if (jumlahcd < 100) {
		if (item_count(242) < jumlahcd) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
		dropwl = true;
		g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + cdropcount); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
                }
		
		else if (jumlahcd > 10000) {
			int jumlahcd1 = (jumlahcd / 10000);
			int halohai = ((jumlahcd / 100) - (jumlahcd1 * 100));
			int halohai1 = jumlahcd - ((halohai * 100) + (jumlahcd1 * 10000));
			if (halohai > item_count(1796)) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 7188;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
                    else if (item_count(242) < halohai1) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
			dropbgl = true;
			g_server->send(false, "action|drop\n|itemID|7188");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + std::to_string(jumlahcd1)); //242
                    dropdl = true;
                    g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string(halohai)); //242
                    dropwl = true;
                    g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + std::to_string(halohai1)); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
			}
		
		else {
			int jumlahcd1 = (jumlahcd / 100);
			int halohai = (jumlahcd % 100);
if (item_count(242) < halohai) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));

                    }
                    else if (item_count(1796) < jumlahcd1) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 242;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));

                    }

			dropdl = true;
			g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string(jumlahcd1)); //242
                    dropwl = true;
                    g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + std::to_string(halohai)); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
                
            }
    
        return true;
	}
	else if (find_command(chat, "ddrop ")) {
            try {
                std::string cdropcount = chat.substr(7);
                int jumlahdl = stoi(cdropcount);

                if (jumlahdl > 200 && item_count(7188) >= (jumlahdl / 100)) {
                    dropbgl = true;
                    g_server->send(false, "action|drop\n|itemID|7188");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + std::to_string((jumlahdl / 100))); //242
                    dropdl = true;
                    g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string((jumlahdl % 100))); //1796
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 Dl...");
                    return true;
                }
                else if (item_count(1796) < jumlahdl) {
                    dropbgl = true;
                    g_server->send(false, "action|drop\n|itemID|7188");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + std::to_string((jumlahdl / 100))); //242
                    dropdl = true;
                    g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string((jumlahdl % 100))); //1796
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 Dl...");
                    return true;
                }
                dropdl = true;
                g_server->send(false, "action|drop\n|itemID|1796");
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + cdropcount); //1796
                gt::send_log("`9Dropping `c" + cdropcount + "`9 Dl...");
            }
            catch (std::exception) {
// gt::send_log("Critical Error : Invalid String Position"); 
}
        return true;
        }

		else if (find_command(chat, "dd ")) {
            try {
                std::string cdropcount = chat.substr(4);
                int jumlahdl = stoi(cdropcount);

                if (jumlahdl > 200 && item_count(7188) >= (jumlahdl / 100)) {
                    dropbgl = true;
                    g_server->send(false, "action|drop\n|itemID|7188");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + std::to_string((jumlahdl / 100))); //242
                    dropdl = true;
                    g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string((jumlahdl % 100))); //1796
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 Dl...");
                    return true;
                }
                else if (item_count(1796) < jumlahdl) {
                    dropbgl = true;
                    g_server->send(false, "action|drop\n|itemID|7188");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + std::to_string((jumlahdl / 100))); //242
                    dropdl = true;
                    g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string((jumlahdl % 100))); //1796
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 Dl...");
                    return true;
                }
                dropdl = true;
                g_server->send(false, "action|drop\n|itemID|1796");
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + cdropcount); //1796
                gt::send_log("`9Dropping `c" + cdropcount + "`9 Dl...");
            }
            catch (std::exception) {
// gt::send_log("Critical Error : Invalid String Position"); 
}
        return true;
        }
			    
else if (find_command(chat, "bdrop ")) {
        std::string cdropcount = chat.substr(7);
        dropbgl = true;
        g_server->send(false, "action|drop\n|itemID|7188");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + cdropcount); //7188
        gt::send_log("`9Dropping `c" + cdropcount + "`9 Bgl...");
        return true;
        }

	else if (find_command(chat, "bd ")) {
        std::string cdropcount = chat.substr(4);
        dropbgl = true;
        g_server->send(false, "action|drop\n|itemID|7188");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + cdropcount); //7188
        gt::send_log("`9Dropping `c" + cdropcount + "`9 Bgl...");
        return true;
        }
		
        
else if (find_command(chat, "gdrop")) {
	int jumlahcd = bruh4;
	std::string cdropcount = to_string(jumlahcd);
if (balance() < jumlahcd) {
                    gt::send_log("`9Dont have `#balance`9. balance: " + to_string(balance()) + ".");
                    return true;
                }
	
	if (jumlahcd < 100) {
		if (item_count(242) < jumlahcd) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
		dropwl = true;
		g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + cdropcount); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
                }
		
		else if (jumlahcd > 10000) {
			int jumlahcd1 = (jumlahcd / 10000);
			int halohai = ((jumlahcd / 100) - (jumlahcd1 * 100));
			int halohai1 = jumlahcd - ((halohai * 100) + (jumlahcd1 * 10000));
			if (halohai > item_count(1796)) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 7188;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
                    else if (item_count(242) < halohai1) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
			dropbgl = true;
			g_server->send(false, "action|drop\n|itemID|7188");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|7188|\ncount|" + std::to_string(jumlahcd1)); //242
                    dropdl = true;
                    g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string(halohai)); //242
                    dropwl = true;
                    g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + std::to_string(halohai1)); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
			}
		
		else {
			int jumlahcd1 = (jumlahcd / 100);
			int halohai = (jumlahcd % 100);
if (item_count(242) < halohai) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 1796;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));

                    }
                    else if (item_count(1796) < jumlahcd1) {
                        gameupdatepacket_t yahacdrop{ 0 };
                        yahacdrop.m_type = PACKET_ITEM_ACTIVATE_REQUEST;
                        yahacdrop.m_int_data = 242;
                        g_server->send(false, NET_MESSAGE_GAME_PACKET, (uint8_t*)&yahacdrop, sizeof(gameupdatepacket_t));
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));

                    }

			dropdl = true;
			g_server->send(false, "action|drop\n|itemID|1796");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|1796|\ncount|" + std::to_string(jumlahcd1)); //242
                    dropwl = true;
                    g_server->send(false, "action|drop\n|itemID|242");
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|242|\ncount|" + std::to_string(halohai)); //242
                    gt::send_log("`9Dropping `c" + cdropcount + "`9 wls...");
                
            }
    
        return 0;
	}

else if (find_command(chat, "tpos ")) {
	std::string tepos = chat.substr(6);
auto& bruh = g_server->m_world.local;
	ppos1.m_x = atoi(pos1xm.c_str());
	ppos1.m_y = atoi(pos1ym.c_str());
	ppos2.m_x = atoi(pos2xm.c_str());
	ppos2.m_y = atoi(pos2ym.c_str());
	ppos3.m_x = atoi(pos3xm.c_str());
	ppos3.m_y = atoi(pos3ym.c_str());
	ppos4.m_x = atoi(pos4xm.c_str());
	ppos4.m_y = atoi(pos4ym.c_str());

if (tepos == "1") {
		if (pos1xm == "" && pos1ym == "") {
			gt::send_log("`9Please setpos 1 first");
}
			else {
tptopos(ppos1.m_x,ppos1.m_y);
		gt::send_log("`9Teleport to position 1");
		
}
	
}

if (tepos == "2") {
		if (pos2xm == "" && pos2ym == "") {
			gt::send_log("`9Please setpos 2 first");
}
			else {
tptopos(ppos2.m_x,ppos2.m_y);
		gt::send_log("`9Teleport to position 2");
		
}
	
}
if (tepos == "3") {
		if (pos3xm == "" && pos3ym == "") {
			gt::send_log("`9Please setpos 3 first");
}
			else {
tptopos(ppos3.m_x,ppos3.m_y);
		gt::send_log("`9Teleport to position 3");
		
}

}
	
if (tepos == "4") {
		if (pos4xm == "" && pos4ym == "") {
			gt::send_log("`9Please setpos 4 first");
}
			else {
tptopos(ppos4.m_x,ppos4.m_y);
		gt::send_log("`9Teleport to position 4");
		
}
	
}
		return true;

}

	
        else if (find_command(chat, "pos1")) {
        auto& bruh = g_server->m_world.local;
        int pos1x = bruh.pos.m_x;
        int pos1y = bruh.pos.m_y;
        pos1xm = to_string(pos1x);
        pos1ym = to_string(pos1y);
        variantlist_t varlist{"OnParticleEffect"};
        varlist[1] = 88;
        varlist[2] = vector2_t{ bruh.pos.m_x,  bruh.pos.m_y};
        varlist[3] = 0;
        varlist[4] = 0;
        g_server->send(true, varlist);
        
        gt::send_log("`91st position: `#" + pos1xm + ", " + pos1ym);
        return true;
        }

		else if (find_command(chat, "pos2")) {
        auto& bruh = g_server->m_world.local;
        int pos2x = bruh.pos.m_x;
        int pos2y = bruh.pos.m_y;
        pos2xm = to_string(pos2x);
        pos2ym = to_string(pos2y);
        variantlist_t varlist{"OnParticleEffect"};
        varlist[1] = 88;
        varlist[2] = vector2_t{ bruh.pos.m_x,  bruh.pos.m_y};
        varlist[3] = 0;
        varlist[4] = 0;
        g_server->send(true, varlist);
        
        gt::send_log("`92nd position: `#" + pos2xm + ", " + pos2ym);
        return true;
        }

else if (find_command(chat, "pos3")) {
        auto& bruh = g_server->m_world.local;
        int pos3x = bruh.pos.m_x;
        int pos3y = bruh.pos.m_y;
        pos3xm = to_string(pos3x);
        pos3ym = to_string(pos3y);
        variantlist_t varlist{"OnParticleEffect"};
        varlist[1] = 88;
        varlist[2] = vector2_t{ bruh.pos.m_x,  bruh.pos.m_y};
        varlist[3] = 0;
        varlist[4] = 0;
        g_server->send(true, varlist);
        
        gt::send_log("`93rd position: `#" + pos3xm + ", " + pos3ym);
        return true;
        }

		else if (find_command(chat, "pos4")) {
        auto& bruh = g_server->m_world.local;
        int pos4x = bruh.pos.m_x;
        int pos4y = bruh.pos.m_y;
        pos4xm = to_string(pos4x);
        pos4ym = to_string(pos4y);
        variantlist_t varlist{"OnParticleEffect"};
        varlist[1] = 88;
        varlist[2] = vector2_t{ bruh.pos.m_x,  bruh.pos.m_y};
        varlist[3] = 0;
        varlist[4] = 0;
        g_server->send(true, varlist);
        
        gt::send_log("`94th position: `#" + pos4xm + ", " + pos4ym);
        return true;
        }

			else if (find_command(chat, "posb")) {
auto& bruh = g_server->m_world.local;
				int posbackx = bruh.pos.m_x;
				int posbacky = bruh.pos.m_y;
			 posbackxm = to_string(posbackx);
				 posbackym = to_string(posbacky);
				variantlist_t varlist{"OnParticleEffect"};
				varlist[1] = 88;
        varlist[2] = vector2_t{ bruh.pos.m_x,  bruh.pos.m_y};
        varlist[3] = 0;
        varlist[4] = 0;
        g_server->send(true, varlist);
        
        gt::send_log("`9pos hostposition: `#" + posbackxm + ", " + posbackym);
        return true;
        }
			


else if (find_command(chat, "tp")) {
	gt::game_started = true;
	int clt1 = 0;
        int clt2 = 0;
        int clt3 = 0;
        int clt4 = 0;
	ppos1.m_x = atoi(pos1xm.c_str());
	ppos1.m_y = atoi(pos1ym.c_str());
	ppos2.m_x = atoi(pos2xm.c_str());
	ppos2.m_y = atoi(pos2ym.c_str());
	ppos3.m_x = atoi(pos3xm.c_str());
	ppos3.m_y = atoi(pos3ym.c_str());
	ppos4.m_x = atoi(pos4xm.c_str());
	ppos4.m_y = atoi(pos4ym.c_str());
	pposback.m_x = atoi(posbackxm.c_str());
	pposback.m_y = atoi(posbackym.c_str());
        auto p = g_server->m_world.objects;
        for (auto& item : p) {
            if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, (1.2 * 32), (ppos1.m_x * 32), (ppos1.m_y * 32))) {
                if (item.second.itemID == 242) clt1 += item.second.count;
                if (item.second.itemID == 1796) clt1 += item.second.count * 100;
            }

            if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, (1.2 * 32), (ppos2.m_x * 32), (ppos2.m_y * 32))) {
                if (item.second.itemID == 242) clt2 += item.second.count;
                if (item.second.itemID == 1796) clt2 += item.second.count * 100;
}
        
        if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, (1.2 * 32), (ppos3.m_x * 32), (ppos3.m_y * 32))) {
                if (item.second.itemID == 242) clt3 += item.second.count;
                if (item.second.itemID == 1796) clt3 += item.second.count * 100;
            }

            if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, (1.2 * 32), (ppos4.m_x * 32), (ppos4.m_y * 32))) {
                if (item.second.itemID == 242) clt4 += item.second.count;
                if (item.second.itemID == 1796) clt4 += item.second.count * 100;
            }
        }

        if (clt1 == clt2 && clt3 == clt4 && clt1 != 0 && clt2 != 0 && clt3 != 0 && clt4 != 0) {
            gt::total_bet = clt1 + clt2 + clt3 + clt4;
                tptopos(ppos1.m_x, ppos1.m_y);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                tptopos(ppos2.m_x, ppos2.m_y);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                tptopos(ppos3.m_x, ppos3.m_y);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                tptopos(ppos4.m_x, ppos4.m_y);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                tptopos(pposback.m_y, pposback.m_y);
            }
            else {
                for (auto& item : p) {
                    gameupdatepacket_t kuntul{};
                    kuntul.m_type = PACKET_ITEM_ACTIVATE_OBJECT_REQUEST;
                    kuntul.m_player_flags = -1;
                    kuntul.m_vec_x = item.second.pos.m_x;
                    kuntul.m_vec_y = item.second.pos.m_y;
                    kuntul.m_int_data = item.second.uid;
                    kuntul.m_state1 = item.second.pos.m_x + item.second.pos.m_y + 4;
                    if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, 10 * 32, g_server->local_player.pos.m_x, g_server->local_player.pos.m_y)) {
                        if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, (1.2 * 32), (ppos1.m_x * 32), (ppos1.m_y * 32))) {
                            if (item.second.itemID == 242 || item.second.itemID == 1796) {
                                g_server->send(false, 4, (uint8_t*)&kuntul, sizeof(packet));
                                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                            }
                        }
                        if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, (1.2 * 32), (ppos2.m_x * 32), (ppos2.m_y * 32))) {
                            if (item.second.itemID == 242 || item.second.itemID == 1796) {
                                g_server->send(false, 4, (uint8_t*)&kuntul, sizeof(packet));
                                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                            }
                        }
                        
                        if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, (1.2 * 32), (ppos3.m_x * 32), (ppos3.m_y * 32))) {
                            if (item.second.itemID == 242 || item.second.itemID == 1796) {
                                g_server->send(false, 4, (uint8_t*)&kuntul, sizeof(packet));
                                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                            }
                        }
                        if (utils::isInside(item.second.pos.m_x, item.second.pos.m_y, (1.2 * 32), (ppos4.m_x * 32), (ppos4.m_y * 32))) {
                            if (item.second.itemID == 242 || item.second.itemID == 1796) {
                                g_server->send(false, 4, (uint8_t*)&kuntul, sizeof(packet));
                                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                            }
                        }
                        
                    }
}

		    gt::send_log("`9Collected!");	
}
        return true;
    }
    
    
    
    



	
        
        else if (find_command(chat, "win1")) {
        vector2_t pos;
        pos.m_x = ppos1.m_x;
        pos.m_y = ppos1.m_y;
        int normalx = ppos1.m_x / 32;
        int normaly = ppos1.m_y / 32;
        tptopos(normalx, normaly);
            bool aga = custom_drop((gt::total_bet - (gt::total_bet / taxcount)), pos, ppos1.m_x, ppos1.m_y);
        gt::game_started = false;
        return true;
        }
        else if (find_command(chat, "win2")) {
        vector2_t pos;
        pos.m_x = ppos2.m_x;
        pos.m_y = ppos2.m_y;
        int normalx = ppos2.m_x / 32;
        int normaly = ppos2.m_y / 32;
        tptopos(normalx, normaly);
        bool aga = custom_drop((gt::total_bet - (gt::total_bet / taxcount)), pos, ppos2.m_x, ppos2.m_y);
        gt::game_started = false;
        return true;
        }
        
        else if (find_command(chat, "win3")) {
        vector2_t pos;
        pos.m_x = ppos3.m_x;
        pos.m_y = ppos3.m_y;
        int normalx = ppos3.m_x / 32;
        int normaly = ppos3.m_y / 32;
        tptopos(normalx, normaly);
            bool aga = custom_drop((gt::total_bet - (gt::total_bet / taxcount)), pos, ppos3.m_x, ppos3.m_y);
        gt::game_started = false;
        return true;
        }
        else if (find_command(chat, "win4")) {
        vector2_t pos;
        pos.m_x = ppos4.m_x;
        pos.m_y = ppos4.m_y;
        int normalx = ppos4.m_x / 32;
        int normaly = ppos4.m_y / 32;
        tptopos(normalx, normaly);
        bool aga = custom_drop((gt::total_bet - (gt::total_bet / taxcount)), pos, ppos4.m_x, ppos4.m_y);
        gt::game_started = false;
        return true;
        }


			
	    else if (find_command(chat, "wrench")) {
            wrench_dialog = (wrench) ? "1" : "0";
            wrench_block = (block_wrench) ? "1" : "0";
            std::string paket =
                "\nset_default_color|`o"
                "\nadd_label_with_icon|big|Wrench Mode : " + mode +
                "|left|32|"
                "|left|2480|\nadd_spacer|small\n"
                "\nadd_checkbox|vmode|`9Enable Wrench|" +
                wrench_dialog +
                "|"
                "\nadd_checkbox|vblockdialog|`9Block Wrench|" +
                wrench_block +
                "|"
                "\nadd_button|Pull|`9 Set Mode To [ Pull ]``|noflags|0|0|"
                "\nadd_button|Kick|`9 Set Mode To [ Kick ]``|noflags|0|0|"
                "\nadd_button|Ban|`9 Set Mode To [ Ban ]``|noflags|0|0|"
                "\nadd_quick_exit|";
            variantlist_t liste{ "OnDialogRequest" };
            liste[1] = paket;
            g_server->send(true, liste);
            return true;
        }
				    
			
        
        else if (find_command(chat, "uid ")) {
            std::string name = chat.substr(5);
            gt::send_log("resolving uid for " + name);
            g_server->send(false, "action|input\n|text|/ignore /" + name);
            g_server->send(false, "action|friends");
            gt::resolving_uid2 = true;
            return true;

        } else if (find_command(chat, "warp ")) {
            std::string name = chat.substr(6);
            gt::send_log("`#Warping to " + name);
            g_server->send(false, "action|join_request\nname|" + name, 3);
            return true;
          
      } else if (find_command(chat, "pullall")) {
            std::string username = chat.substr(6);
            for (auto& player : g_server->m_world.players) {
                auto name_2 = player.name.substr(2); //remove color
                if (name_2.find(username)) {
                    g_server->send(false, "action|wrench\n|netid|" + std::to_string(player.netid));
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    g_server->send(false, "action|dialog_return\ndialog_name|popup\nnetID|" + std::to_string(player.netid) + "|\nbuttonClicked|pull"); 
                    // You Can |kick |trade |worldban 
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    gt::send_log("`4Pulling all people");
                  
                }
            }
} else if (find_command(chat, "killall")) {
            std::string username = chat.substr(6);
            for (auto& player : g_server->m_world.players) {
                auto name_2 = player.name.substr(2); //remove color
                if (name_2.find(username)) {
                    g_server->send(false, "action|wrench\n|netid|" + std::to_string(player.netid));
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    g_server->send(false, "action|dialog_return\ndialog_name|popup\nnetID|" + std::to_string(player.netid) + "|\nbuttonClicked|kick"); 
                    // You Can |kick |trade |worldban 
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    gt::send_log("`4Kill All People in world");
                  
                }
            }
} else if (find_command(chat, "tradeall")) {
            std::string username = chat.substr(6);
            for (auto& player : g_server->m_world.players) {
                auto name_2 = player.name.substr(2); //remove color
                if (name_2.find(username)) {
                    g_server->send(false, "action|wrench\n|netid|" + std::to_string(player.netid));
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    g_server->send(false, "action|dialog_return\ndialog_name|popup\nnetID|" + std::to_string(player.netid) + "|\nbuttonClicked|trade"); 
                    // You Can |kick |trade |worldban 
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    gt::send_log("`4Trade all people in world");
                  
                }
            }
} else if (find_command(chat, "banall")) {
            std::string username = chat.substr(6);
            for (auto& player : g_server->m_world.players) {
                auto name_2 = player.name.substr(2); //remove color
                if (name_2.find(username)) {
                    g_server->send(false, "action|wrench\n|netid|" + std::to_string(player.netid));
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    g_server->send(false, "action|dialog_return\ndialog_name|popup\nnetID|" + std::to_string(player.netid) + "|\nbuttonClicked|worldban"); 
                    // You Can |kick |trade |worldban 
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    gt::send_log("`4Banned all people in world");
                  
                }
            }

}  else if (find_command(chat, "skin ")) {
            int skin = atoi(chat.substr(6).c_str());
            variantlist_t va{ "OnChangeSkin" };
            va[1] = skin;
            g_server->send(true, va, world.local.netid, -1);
            return true;
        } else if (find_command(chat, "wrench ")) {
            std::string name = chat.substr(6);
            std::string username = ".";
            for (auto& player : g_server->m_world.players) {
                auto name_2 = player.name.substr(2);
                std::transform(name_2.begin(), name_2.end(), name_2.begin(), ::tolower);
                    g_server->send(false, "action|wrench\n|netid|" + std::to_string(player.netid));
            }
            return true;

}else if (find_command(chat, "info")) {
                   std::string paket;
            paket =
                "\nadd_label_with_icon|big|Proxy information|left|20|"
                "\nadd_spacer|small"
                "\nadd_textbox|`9Proxy Made By TehTarik#1195 And kimbacatan#6426|left|2480|"
                "\nadd_textbox|`9See All Command List do /proxy|left|2480|"
                "\nadd_textbox|`9Buy Proxy only dm discord kimbacatan#6426|left|2480|"
                "\nadd_quick_exit|"
                "\nend_dialog|end|Cancel|Okay|";
            variantlist_t liste{ "OnDialogRequest" };
            liste[1] = paket;
            g_server->send(true, liste);
            return true;
        
}
	
	else if (find_command(chat, "spam")) {
        if (enabled_color == true) {
            swxs = "1";
        }
        else {
            swxs = "0";
        }
        std::string msg;
        msg =
            "add_label_with_icon|big|Auto Spam Page|left|242|"
            "\nadd_textbox|`9Leave the text uncolored, it will automaticcly color itself|left|2480|"
            "\nadd_textbox|`9if colored Text is enabled|left|2480|"
            "\nadd_checkbox|c_text|`2Enable `ccolored text|" +
            swxs +
            "|"
            //"\nadd_text_input |spam_msg|`9Spam text: | " + gt:: + " |30"
            "\nadd_text_input|spam_msg|`9Spam text: |" + aspam + "|50|"
            //add_text_input|" + name + "|" + text + "|" + cont + "|" + to_string(size) + "|
            "\nadd_text_input|delay_msg|`9Delay`2(ms): |" + to_string(delay) + "|4|"
            "\nadd_textbox|`91000`2ms`9 = 1 Second|left|2480|"
            "\nend_dialog|spam_text|Cancel|Set|"; //"\nend_dialog|colored_text|Cancel|Set|";
        variantlist_t send{ "OnDialogRequest" };
        send[1] = msg;
        g_server->send(true, send);
        return true;
}

else if (find_command(chat, "/")) {
        son = !son;
                std::thread([&]() {
                    const string colored_text_array[10] = { "`2", "`3", "`4", "`#", "`9", "`8", "`c", "`6", "`^" , "`b" };
                    while (son) {
                        int baba = (rand() % 9 ) + 1;
                            string send_ = colored_text_array[baba];
                            if (enabled_color == true) {
                                g_server->send(false, "action|input\n|text|" + send_ + aspam);
                            }
                            else {
                                g_server->send(false, "action|input\n|text|" + aspam);
                            }
                            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                        
                    }
                    }).detach();
            return true;

}
else if (find_command(chat, "countrylist") || find_command(chat, "clist")) {
            std::string paket;
            paket =
                "\nadd_label_with_icon|big|Country List|left|3394|"
                "\nadd_spacer|small"
                "\nadd_textbox|`clt: `#Lithuania|left|2480|"
                "\nadd_textbox|`ctr: `#Turkey|left|2480|"
                "\nadd_textbox|`cen: `#USA|left|2480|"
                "\nadd_textbox|`ckr: `#Korean|left|2480|"
                "\nadd_textbox|`cid: `#Indonesia|left|2480|"
                "\nadd_textbox|`caf: `#Afghanistan|left|2480|"
                "\nadd_textbox|`cal: `#Albania|left|2480|"
                "\nadd_textbox|`cdz: `#Algeria|left|2480|"
                "\nadd_textbox|`cas: `#American Samoa|left|2480|"
                "\nadd_textbox|`cad: `#Andorra|left|2480|"
                "\nadd_textbox|`cao: `#Angola|left|2480|"
                "\nadd_textbox|`cai: `#Anguilla|left|2480|"
                "\nadd_textbox|`caq: `#Antarctica|left|2480|"
                "\nadd_textbox|`cag: `#Antigua and Barbuda|left|2480|"
                "\nadd_textbox|`car: `#Argentina|left|2480|"
                "\nadd_textbox|`cam: `#Armenia|left|2480|"
                "\nadd_textbox|`cth: `#Thailand|left|2480|"
                "\nadd_textbox|`ces: `#Spain|left|2480|"
                "\nadd_textbox|`cso: `#Somalia|left|2480|"
                "\nadd_textbox|`cse: `#Sweden|left|2480|"
                "\nadd_textbox|`cmm: `#Myanmar|left|2480|"
                "\nadd_quick_exit|"
                "\nend_dialog|end|Cancel|Okay|";
            variantlist_t liste{ "OnDialogRequest" };
            liste[1] = paket;
            g_server->send(true, liste);
            return true;
}
else if (find_command(chat, "proxy")) {
           // gt::send_log(
            //    "`2/tp [name] (teleports to a player in the world), /ghost (toggles ghost, you wont move for others when its enabled), /uid "
            //    "`2[name] (resolves name to uid), /flag [id] (sets flag to item id), /name [name] (sets name to name), /banall, /kickall, /tradeall"
            //    "`2/warp [world name] (warping world without SSUP), /skin [Id] (change skin colours), /wrenchmode (for wrench pull, kick, pull, ban, trade)"
           //     "`2/ft (fast trash), /fd (fast drop), /setcountry (bug), /wrenchset (for set wrenchmode : pull,kick,ban,trade,add friend),/msgall (bug), /pinfo"
            //    "`2/wrenchmsg (Auto Msg Wrench People), /setmsg (for set message text)");
           std::string paket1;
            paket1 =
                "\nadd_label_with_icon|big|`9Erza Proxy Command|left|5956|"
                "\nadd_spacer|small"
		"\nadd_label_with_icon|small|`9Main Command|left|5956|"
		    "\nadd_textbox|`2/uid [name] (resolves no uid)|left|2480|"
                "\nadd_smalltext|`2/spam (spam menu)|left|2480|"
		"\nadd_smalltext|`2// (start auto spam)|left|2480|"
                "\nadd_smalltext|`2/banall (World Ban All People in world)|left|2480|"
                "\nadd_smalltext|`2/killall (Kick all People in world)|left|2480|"
                "\nadd_smalltext|`2/tradeall (trade all people in the world|left|2480|"
                "\nadd_smalltext|`2/warp [world name] (warping world without SSUP)|left|2480|"
                "\nadd_smalltext|`2/skin [Id] (change skin colours)|left|2480|"
		    "\nadd_smalltext|`2/ft (fast trash) |left|2480|"
                "\nadd_smalltext|`2/fd (fast drop) |left|2480|"
"\nadd_smalltext|`2/info (Proxy information) |left|2480|"
                "\nadd_smalltext|`2/autopull (auto pull when people enter world) |left|2480|"
                "\nadd_smalltext|`2/pullauto (auto pull for casino hoster) |left|2480|"
		    "\nadd_spacer|small|"
		    "\nadd_label_with_icon|small|`9Visual Command|left|9228|"
		    "\nadd_smalltext|`2/flag [id] (sets flag to item id)|left|2480|"
"\nadd_smalltext|`2/name [name] (Change Name Visual)|left|2480|"
"\nadd_smalltext|`2/country (/countrylist for check list)|left|2480|"
		    "\nadd_smalltext|`2/countrylist (List Country For /country) |left|2480|"
		    "\nadd_smalltext|`2/legend (visual legendary title)|left|2480|"
		    "\nadd_smalltext|`2/g4g (visual grow4good title)|left|2480|"
		    "\nadd_smalltext|`2/maxlevel (visual maxlevel)|left|2480|"
		    "\nadd_smalltext|`2/mentor (visual mentor title)|left|2480|"
		    "\nadd_spacer|small|"
"\nadd_label_with_icon|small|`9Casino/Host Feature|left|758|"
"\nadd_smalltext|`2/pos1 - /pos4 (set pos 1 - 4)|left|2480|"
		    "\nadd_smalltext|`2/tpos [number] (teleport to pos 1-4)|left|2480|"
		    "\nadd_smalltext|`2/tp (take wl/dl from pos 1-4)|left|2480|"
		    "\nadd_smalltext|`2/win1 - /win4 (drop wl include tax to pos1 - pos4)|left|2480|"
		    "\nadd_spacer|small|"
		    "\nadd_label_with_icon|small|`9Player Command|left|32|"
		    "\nadd_smalltext|`2/wrench (dialog wrench)|left|2480|"
		    "\nadd_spacer|small|"
		    "\nadd_label_with_icon|small|`9Drop Command|left|242|"
		    "\nadd_smalltext|`2/cd [amount] or /cdrop [amount] (custom drop locks)|left|2480|"
		    "\nadd_smalltext|`2/dd [amount] or /ddrop [amount] (diamond locks drop)|left|2480|"
		    "\nadd_smalltext|`2/bd [amount] or /bdrop [amount] (blue gem lock drop)|left|2480|"
                "\nadd_spacer|small|\n\nadd_url_button||`3Discord``|NOFLAGS|https://discord.gg/2YZj3fmxRk|Join Erza Proxy Discord!|"
                "\nadd_quick_exit|"
                "\nend_dialog|end|Cancel|Okay|";
            variantlist_t liste{ "OnDialogRequest" };
liste[1] = paket1;
            g_server->send(true, liste);
            
            return true;
        } 
        return false;
    }

    if (packet.find("game_version|") != -1) {
        rtvar var = rtvar::parse(packet);
        auto mac = utils::generate_mac();
        auto hash_str = mac + "RT";
        auto hash2 = utils::hash((uint8_t*)hash_str.c_str(), hash_str.length());
	CURL *curl;
        std::string readBuffer;
        struct curl_slist *headers = NULL;
        curl = curl_easy_init();
        if(curl) {
            std::string postfields = string("version=") + gt::version + string("&platform=4&protocol=191");
            headers = curl_slist_append(headers, "User-Agent: UbiServices_SDK_2017.Final.21_ANDROID64_static");
            curl_easy_setopt(curl, CURLOPT_URL, "https://www.growtopia1.com/growtopia/server_data.php");
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postfields.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 5000);
            curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            rtvar var1 = rtvar::parse(readBuffer);

            if (var1.find("meta")) {
                g_server->meta = var1.get("meta");
                g_server->m_server = var1.get("server");
                g_server->m_port = var1.get_int("port");
                PRINTS("Meta: %s\n\n", g_server->meta.c_str());
            }
        }
        var.set("mac", mac);
        var.set("gid", utils::generate_rid());
        var.set("meta", g_server->meta);
        var.set("game_version", gt::version);
        var.set("country", gt::flag);
        packet = var.serialize();
        gt::in_game = false;
        PRINTS("Spoofing login info\n");
        g_server->send(false, packet);
        return true;
    }

    return false;
}

bool events::out::gamemessage(std::string packet) {
    PRINTS("Game message: %s\n", packet.c_str());
    if (packet == "action|quit") {
        g_server->quit();
        return true;
    }

    return false;
}

bool events::out::state(gameupdatepacket_t* packet) {
    if (!g_server->m_world.connected)
        return false;

    g_server->m_world.local.pos = vector2_t{ packet->m_vec_x, packet->m_vec_y };
    PRINTS("local pos: %.0f %.0f\n", packet->m_vec_x, packet->m_vec_y);

    if (gt::ghost)
        return true;
    return false;
}

bool events::in::variantlist(gameupdatepacket_t* packet) {
    variantlist_t varlist{};
    auto extended = utils::get_extended(packet);
    extended += 4; //since it casts to data size not data but too lazy to fix this
    varlist.serialize_from_mem(extended);
    PRINTC("varlist: %s\n", varlist.print().c_str());
    auto func = varlist[0].get_string();

    //probably subject to change, so not including in switch statement.
    if (func.find("OnSuperMainStartAcceptLogon") != -1)
        gt::in_game = true;

    switch (hs::hash32(func.c_str())) {

        case fnv32("OnRequestWorldSelectMenu"): {
            auto& world = g_server->m_world;
            world.players.clear();
            world.local = {};
            world.connected = false;
            world.name = "EXIT";
        } break;

	   
	   
   
        case fnv32("OnSendToServer"): g_server->redirect_server(varlist); return true;

        case fnv32("OnConsoleMessage"): {
            varlist[1] = "`2[`9ErzaProxy`2]`o " + varlist[1].get_string();
            auto cnsl = varlist[1].get_string();
          g_server->send(true, varlist);
       return true;
//std::string console = varlist[1].get_string();
//std::transform(console.begin(),console.end(),console.begin(),::tolower);

    if (pullauto == true) {
              g_server->send(true, varlist);
                if (cnsl.find("Skem") != -1) {
                    if (cnsl.find("`$") != -1) {
                        std::string nasmasma = cnsl.substr(cnsl.find("[W]_ `6<`") + 10, cnsl.length() - cnsl.find("[W]_ `6<`") - 1);
                        nasmasma.erase(nasmasma.begin() + nasmasma.find("``>``"), nasmasma.end());
                        g_server->send(false, "action|input\n|text|bapak kau " + nasmasma);
                    }
                } else if (cnsl.find("scam") != -1) {
                    if (cnsl.find("`w") != -1) {
                        std::string nasmasma = cnsl.substr(cnsl.find("[W]_ `6<`w") + 10, cnsl.length() - cnsl.find("[W]_ `6<`w") - 1);
                        nasmasma.erase(nasmasma.begin() + nasmasma.find("``>``"), nasmasma.end());
                        g_server->send(false, "action|input\n|text|/ban " + nasmasma);
                    }
                } else if (cnsl.find("dont") != -1) {
                    if (cnsl.find("`w") != -1) {
                        std::string nasmasma = cnsl.substr(cnsl.find("[W]_ `6<`w") + 10, cnsl.length() - cnsl.find("[W]_ `6<`w") - 1);
                        nasmasma.erase(nasmasma.begin() + nasmasma.find("``>``"), nasmasma.end());
                        g_server->send(false, "action|input\n|text|/ban " + nasmasma);
                    }
                } else if (cnsl.find("Scam") != -1) {
                    if (cnsl.find("`w") != -1) {
                        std::string nasmasma = cnsl.substr(cnsl.find("[W]_ `6<`w") + 10, cnsl.length() - cnsl.find("[W]_ `6<`w") - 1);
                        nasmasma.erase(nasmasma.begin() + nasmasma.find("``>``"), nasmasma.end());
                        g_server->send(false, "action|input\n|text|/ban " + nasmasma);
                    }
                } else if (cnsl.find("SCam") != -1) {
                    if (cnsl.find("`w") != -1) {
                        std::string nasmasma = cnsl.substr(cnsl.find("[W]_ `6<`w") + 10, cnsl.length() - cnsl.find("[W]_ `6<`w") - 1);
                        nasmasma.erase(nasmasma.begin() + nasmasma.find("``>``"), nasmasma.end());
                        g_server->send(false, "action|input\n|text|/ban " + nasmasma);
                    }
                } else if (cnsl.find("noob") != -1) {
                    if (cnsl.find("`w") != -1) {
                        std::string nasmasma = cnsl.substr(cnsl.find("[W]_ `6<`w") + 10, cnsl.length() - cnsl.find("[W]_ `6<`w") - 1);
                        nasmasma.erase(nasmasma.begin() + nasmasma.find("``>``"), nasmasma.end());
                        g_server->send(false, "action|input\n|text|/ban " + nasmasma);
                    }
                } else if (cnsl.find("lol") != -1) {
                    if (cnsl.find("`w") != -1) {
                        std::string nasmasma = cnsl.substr(cnsl.find("[W]_ `6<`w") + 10, cnsl.length() - cnsl.find("[W]_ `6<`w") - 1);
                        nasmasma.erase(nasmasma.begin() + nasmasma.find("``>``"), nasmasma.end());
                        g_server->send(false, "action|input\n|text|/ban " + nasmasma);
                    }
                } else if (cnsl.find("LOL") != -1) {
                    if (cnsl.find("`w") != -1) {
                        std::string nasmasma = cnsl.substr(cnsl.find("[W]_ `6<`w") + 10, cnsl.length() - cnsl.find("[W]_ `6<`w") - 1);
                        nasmasma.erase(nasmasma.begin() + nasmasma.find("``>``"), nasmasma.end());
                        g_server->send(false, "action|input\n|text|/ban " + nasmasma);
                    }
                }  
	    
    }
	} break;

case fnv32("OnTalkBubble"): {
        auto wry = varlist[2].get_string();
        auto netid = varlist[1].get_int32();
auto& bruh = g_server->m_world.local;

		if (wry.find("spun the wheel and got") != -1)
        {
            if (packet->m_int_data == 1800)
            {
                varlist[2] = "`0[`2REAL`0]`w`` " + varlist[2].get_string();
                g_server->send(true, varlist);
                return true;
            }
            else {
                varlist[2] = varlist[2].get_string() + "`0[`4FAKE`0]`w``  ";
                g_server->send(true, varlist);
                return true;
            }
        }


        g_server->send(true, varlist);
        return true;
    } break;
        case fnv32("OnDialogRequest"): {
            auto content = varlist[1].get_string();
if (dropwl == true) {
            if (content.find("Drop") != -1) {
                dropwl = false;
                return true;
            }
        }
       
        if (cdrop == true) {
            if (content.find("Drop") != -1) {
                cdrop = false;
                return true;
            }
        }
        else if (dropdl == true) {
            if (content.find("Drop") != -1) {
                dropdl = false;
                return true;
            }
        }
        else if (dropbgl == true) {
            if (content.find("Drop") != -1) {
                dropbgl = false;
                return true;
            }
        }
		
        if (wrench == true) {
            if (content.find("add_button|report_player|`wReport Player``|noflags|0|0|") != -1) {
                if (content.find("embed_data|netID") != -1) {
                    return true; // block wrench dialog
                }
            }
	}
		
        if (fastdrop == true) {
            std::string itemid = content.substr(content.find("embed_data|itemID|") + 18, content.length() - content.find("embed_data|itemID|") - 1);
            std::string count = content.substr(content.find("count||") + 7, content.length() - content.find("count||") - 1);
            if (content.find("embed_data|itemID|") != -1) {
                if (content.find("Drop") != -1) {
                    g_server->send(false, "action|dialog_return\ndialog_name|drop_item\nitemID|" + itemid + "|\ncount|" + count);
                    return true;
                }
            }
        }
        if (fasttrash == true) {
            std::string itemid = content.substr(content.find("embed_data|itemID|") + 18, content.length() - content.find("embed_data|itemID|") - 1);
            std::string count = content.substr(content.find("you have ") + 9, content.length() - content.find("you have ") - 1);
            std::string delimiter = ")";
            std::string token = count.substr(0, count.find(delimiter));
            if (content.find("embed_data|itemID|") != -1) {
                if (content.find("Trash") != -1) {
                    g_server->send(false, "action|dialog_return\ndialog_name|trash_item\nitemID|" + itemid + "|\ncount|" + token);
                    return true;
                }
            }
        }
      
      if (wrenchmsg == true) {
    if (content.find("embed_data|netID") !=-1) {
     if(content.find("Add as friend") !=-1) {
        //std::string yourmsg = "Message from FakeModz YT";
        std::string titit = content.substr(content.find("add_label_with_icon|big|`w") + 26, content.length() - content.find("add_label_with_icon|big|`w") - 1);
        titit.erase(titit.begin() + titit.find(" (`2"), titit.end());
        std::string memq = titit + " ";
        std::string ada = "`9"+ message;
        std::string bab = "`8"+ message;
	std::string cok = "`b"+ message;
	std::string ded = "`6"+ message;
        std::string ert = "`$"+ message;
        std::string fuy = "`e"+ message;
	std::string gog = "`c"+ message;
	std::string hew = "`4"+ message;
        std::string ire = "`3"+ message;
        std::string jok = "`2"+ message;
	std::string klo = "`1"+ message;
	std::string lol = "`a"+ message;
        srand(time(NULL)); 
        std::string Message[12] = {ada, bab, cok, ded, ert, fuy, gog, hew, ire, jok, klo, lol};
        int Random = rand() % 12; 
        g_server->send(false, "action|input\n|text|/msg " + memq + Message[Random]);
        gt::send_log("Message Send to "  + memq); 
        return true;
    }
} 
}
if (wrenchspam == true) {
    if (content.find("embed_data|netID") !=-1) {
     if(content.find("Add as friend") !=-1) {
        //std::string yourmsg = "Message from FakeModz YT";
        std::string titit1 = content.substr(content.find("add_label_with_icon|big|`w") + 26, content.length() - content.find("add_label_with_icon|big|`w") - 1);
        //titit1.erase(titit1.begin() + titit1.find(" (`2"), titit1.end());
        //std::string memq = titit1 + " ";
        g_server->send(false, "action|input\n|text|"+message);
     
 
        return true;
    }
} 
}
       

            //hide unneeded ui when resolving
            //for the /uid command
            if (gt::resolving_uid2 && (content.find("friend_all|Show offline") != -1 || content.find("Social Portal") != -1) ||
                content.find("Are you sure you wish to stop ignoring") != -1) {
                return true;
            } else if (gt::resolving_uid2 && content.find("Ok, you will now be able to see chat") != -1) {
                gt::resolving_uid2 = false;
                return true;
            } else if (gt::resolving_uid2 && content.find("`4Stop ignoring") != -1) {
                int pos = content.rfind("|`4Stop ignoring");
                auto ignore_substring = content.substr(0, pos);
                auto uid = ignore_substring.substr(ignore_substring.rfind("add_button|") + 11);
                auto uid_int = atoi(uid.c_str());
                if (uid_int == 0) {
                    gt::resolving_uid2 = false;
                    gt::send_log("name resolving seems to have failed.");
                } else {
                    gt::send_log("Target UID: " + uid);
                    g_server->send(false, "action|dialog_return\ndialog_name|friends\nbuttonClicked|" + uid);
                    g_server->send(false, "action|dialog_return\ndialog_name|friends_remove\nfriendID|" + uid + "|\nbuttonClicked|remove");
                }
                return true;
            }
        } break;
        case fnv32("OnRemove"): {
            auto text = varlist.get(1).get_string();
            if (text.find("netID|") == 0) {
                auto netid = atoi(text.substr(6).c_str());

                if (netid == g_server->m_world.local.netid) {
                    g_server->m_world.local = {};
		}

                auto& players = g_server->m_world.players;
                for (size_t i = 0; i < players.size(); i++) {
                    auto& player = players[i];
                    if (player.netid == netid) {
                        players.erase(std::remove(players.begin(), players.end(), player), players.end());
                        break;
                    
		}
                }
            }
        } break;
        case fnv32("OnSpawn"): {
            std::string meme = varlist.get(1).get_string();
            rtvar var = rtvar::parse(meme);
            auto name = var.find("name");
            auto netid = var.find("netID");
            auto onlineid = var.find("onlineID");

            if (name && netid && onlineid) {
                player ply{};

                if (var.find("invis")->m_value != "1") {
                    ply.name = name->m_value;
                    ply.country = var.get("country");
                    name->m_values[0] += " `4[" + netid->m_value + "]``";
                    auto pos = var.find("posXY");
                    if (pos && pos->m_values.size() >= 2) {
                        auto x = atoi(pos->m_values[0].c_str());
                        auto y = atoi(pos->m_values[1].c_str());
                        ply.pos = vector2_t{ float(x), float(y) };
                    }
                } else {
                    ply.mod = true;
                    ply.invis = true;
                }
                if (var.get("mstate") == "1" || var.get("smstate") == "1")
                    ply.mod = true;
                ply.userid = var.get_int("userID");
                ply.netid = var.get_int("netID");
                if (meme.find("type|local") != -1) {
                    //set mod state to 1 (allows infinite zooming, this doesnt ban cuz its only the zoom not the actual long punch)
                    var.find("mstate")->m_values[0] = "1";
                    g_server->m_world.local = ply;
                }
                g_server->m_world.players.push_back(ply);
                auto str = var.serialize();
                utils::replace(str, "onlineID", "onlineID|");
                varlist[1] = str;
                PRINTC("new: %s\n", varlist.print().c_str());
                g_server->send(true, varlist, -1, -1);
                if (automessage == true) {
                    try {
                        std::string jokey = "`2   [1]"+ message;
	                std::string klore = "`1   [2]"+ message;
	                std::string loler = "`8   [3]"+ message;
                        std::string jokuy = "`6   [4]"+ message;
	                std::string klori = "`9   [5]"+ message;
	                std::string lolir = "`4   [6]"+ message;
                        srand(time(NULL)); 
                        std::string Message2[6] = {jokey, klore, loler, jokuy, klori, lolir};
                        int Random2 = rand() % 6; 
                        std::this_thread::sleep_for(std::chrono::milliseconds(250));
                        g_server->send(false, "action|input\n|text|/msg " + ply.name +     Message2[Random2]);
		    }
		    catch (std::exception) { 
			    //gt::send_log("Critical Error : Invalid String Position"); 
		    }
                }
                 if (autopull == true) {
                    try { 
                       g_server->send(false, "action|input\n|text|/pull " +ply.name.substr(2));
                      //  gt::send_log("Cooming Soon if possible");
                        
   

                    } 
		    catch (std::exception) { 
			  //  gt::send_log("Critical Error : Invalid String Position");
		    }
                }
                return true;
            }

            
        } break;
    }
    return false;
}

bool events::in::generictext(std::string packet) {
    PRINTC("Generic text: %s\n", packet.c_str());
    return false;
}

bool events::in::gamemessage(std::string packet) {
    PRINTC("Game message: %s\n", packet.c_str());

    if (gt::resolving_uid2) {
        if (packet.find("PERSON IGNORED") != -1) {
            g_server->send(false, "action|dialog_return\ndialog_name|friends_guilds\nbuttonClicked|showfriend");
            g_server->send(false, "action|dialog_return\ndialog_name|friends\nbuttonClicked|friend_all");
        } else if (packet.find("Nobody is currently online with the name") != -1) {
            gt::resolving_uid2 = false;
            gt::send_log("Target is offline, cant find uid.");
        } else if (packet.find("Clever perhaps") != -1) {
            gt::resolving_uid2 = false;
            gt::send_log("Target is a moderator, can't ignore them.");
        }
    }
    return false;
}

bool events::in::OnChangeObject(gameupdatepacket_t* packet) {
    if (packet->m_vec_x == 0 && packet->m_vec_y == 0) {
        if (packet->m_player_flags == g_server->localPlayer.netid) {
            auto object = g_server->m_world.objects.find(packet->m_int_data);
            if (object->second.itemID != 112) {
                auto s_items_ptr = &g_server->localPlayer.inventory.items;
                int buffer = g_server->localPlayer.inventory.getObjectAmountToPickUpUnsafe(object->second);
                if (!g_server->localPlayer.inventory.doesItemExistUnsafe(object->second.itemID)) {
                    Item item;
                    item.id = object->second.itemID;
                    item.count = buffer;
                    item.type = 0;
                    s_items_ptr->operator[](item.id) = item;
                }
                else s_items_ptr->operator[](object->second.itemID).count += buffer;
            }
            else g_server->localPlayer.gems_balance += object->second.count;
        }
        g_server->m_world.objects.erase(packet->m_int_data);
    }
    else {

        if (packet->m_player_flags == -3) {
            auto obj = g_server->m_world.objects.find(packet->m_item);
            if (obj != g_server->m_world.objects.end()) {
                obj->second.itemID = packet->m_int_data;
                obj->second.pos = vector2_t(packet->m_vec_x, packet->m_vec_y);
                obj->second.count = uint32_t(packet->m_struct_flags);
            }
        }
        if (packet->m_player_flags == -1) {
            g_server->m_world.lastDroppedUid = g_server->m_world.lastDroppedUid + 1;
            DroppedItem item;
            item.uid = g_server->m_world.lastDroppedUid;
            item.pos.m_x = packet->m_vec_x;
            item.pos.m_y = packet->m_vec_y;
            item.itemID = packet->m_int_data;
            item.count = (int)packet->m_struct_flags;
            item.flags = packet->m_packet_flags;

            g_server->m_world.objects[item.uid] = item;

        }
        if (packet->m_item == -1 && packet->m_player_flags != -1) {
            g_server->m_world.lastDroppedUid = packet->m_int_data;
            g_server->m_world.objects.erase(packet->m_int_data);

        }
    }

    return false;
}

bool events::in::sendmapdata(gameupdatepacket_t* packet) {
    g_server->m_world = {};
    auto extended = utils::get_extended(packet);
    extended += 4;
    auto data = extended + 6;
    auto name_length = *(short*)data;

    char* name = new char[name_length + 1];
    memcpy(name, data + sizeof(short), name_length);
    char none = '\0';
    memcpy(name + name_length, &none, 1);

    g_server->m_world.name = std::string(name);
    g_server->m_world.connected = true;
    delete[] name;
    PRINTC("world name is %s\n", g_server->m_world.name.c_str());
    return false;
}

bool events::in::state(gameupdatepacket_t* packet) {
    if (!g_server->m_world.connected)
        return false;
    if (packet->m_player_flags == -1)
        return false;

    auto& players = g_server->m_world.players;
    for (auto& player : players) {
        if (player.netid == packet->m_player_flags) {
            player.pos = vector2_t{ packet->m_vec_x, packet->m_vec_y };
            PRINTC("player %s position is %.0f %.0f\n", player.name.c_str(), player.pos.m_x, player.pos.m_y);
            break;
        }
    }
    return false;
}

bool events::in::tracking(std::string packet) {
    PRINTC("Tracking packet: %s\n", packet.c_str());
    if (packet.find("eventName|102_PLAYER.AUTHENTICATION") != -1)
    {
        std::string wlbalance = packet.substr(packet.find("Worldlock_balance|") + 18, packet.length() - packet.find("Worldlock_balance|") - 1);

	    gt::send_log("`9Welcome to [`bErzaProxy`9]");
	    
		    
        if (wlbalance.find("PLAYER.") != -1)
        {
            gt::send_log("`9World Lock Balance: `#0");
        }
        else
        {
            gt::send_log("`9World Lock Balance: `#" + wlbalance);

        }
        if (packet.find("Authenticated|1") != -1)
        {
            gt::send_log("`9Player Authentication `2Successfuly.");
        }
        else
        {
            gt::send_log("`9Player Authentication `4Failed.");
        }

    }
    if (packet.find("eventName|100_MOBILE.START") != -1)
    {
        std::string gems = packet.substr(packet.find("Gems_balance|") + 13, packet.length() - packet.find("Gems_balance|") - 1);
       std::string level = packet.substr(packet.find("Level|") + 6, packet.length() - packet.find("Level|") - 1);
        std::string uid = packet.substr(packet.find("GrowId|") + 7, packet.length() - packet.find("GrowId|") - 1);
        gt::send_log("`9Gems Balance: `#" + gems);
        gt::send_log("`9Account Level: `#" + level);
        gt::send_log("`9Your Current UID: `#" + uid);
    }
    if (packet.find("eventName|300_WORLD_VISIT") != -1)
    {
        if (packet.find("Locked|0") != -1)
        {
            gt::send_log("`4This world is not locked by a world lock.");
        }
        else
        {
            gt::send_log("`2This world is locked by a world lock.");

            if (packet.find("World_owner|") != -1)
            {
                std::string uidd = packet.substr(packet.find("World_owner|") + 12, packet.length() - packet.find("World_owner|") - 1);
                gt::send_log("`9World Owner UID: `#" + uidd);

            }
        }
    }

    return true;
}
