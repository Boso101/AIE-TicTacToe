#pragma once
#include "Player.h"
struct Database 
{

	Player loadedPlayers[];



	void WriteFile(const char* directory);
	void ReadFile(const char* file);

};