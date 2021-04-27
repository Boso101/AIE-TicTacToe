#pragma once
#include "Player.h"
struct Database 
{

	Player loadedPlayers[];



	void WriteFile(const char* directory, Player toWrite);
	void ReadFile(const char* file);



};