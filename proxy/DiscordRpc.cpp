#include "DiscordRpc.h"

void Discord::Initialize()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize("APPLICATION ID", &Handle, 1, NULL);
}

void Discord::Update()
{
	DiscordRichPresence presence;
    memset(&presence, 0, sizeof(presence));
    presence.state = "Currently In-Game"; // Örneğin "Çevrimiçi" veya "Oyunda"
    presence.details = "Premium Proxy User"; // Örneğin "Hikaye Modu" veya "Çevrimiçi Multiplayer"
    presence.largeImageKey = "logos"; // knk dc devportala ekleyeceğin anahtar varya
    presence.largeImageText = "";
    Discord_UpdatePresence(&presence);
}
