#include "DiscordRpc.h"

void Discord::Initialize()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize("APPLICATION ID", &Handle, 1, NULL);
}

void Discord::Update()
{
	//Discord Visualizer
}
