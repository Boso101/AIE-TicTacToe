#pragma once
#include "Player.h"
#include "DatabaseState.h"
struct Database 
{
	Database();

	

	Database(unsigned int maxPlayers);
	~Database();

	void WriteFile(const char* directory, Player toWrite);
	void ReadFile(const char* file);
	void BubbleSortPlayers(Player* playerList);



	// Limit of max players
	const static int MAX_PLAYERS = 64;
	
	int maxPlayers = 0;
	Player* loadedPlayers;
	DatabaseState state;


private:
	//Helper Method
	void Swap(Player* p, Player* p2);
};