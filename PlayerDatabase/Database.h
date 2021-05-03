#pragma once
#include "Player.h"
#include "DatabaseState.h"
#include <string>
struct Database 
{


	

	Database(unsigned int maxPlayers);
	~Database();

	void WriteFile(const char* directory);
	void ReadFile(const char* file);
	void AddPlayer(const std::string& nameP, unsigned int score);
	void BubbleSortPlayers(Player* playerList);
	bool IsFull();



	// Limit of max players
	const static unsigned int MAX_PLAYERS = 16;
	
	int maxPlayers;
	int playerInUse = 0;
	Player* loadedPlayers;
	DatabaseState state;


private:
	//Helper Method
	void Swap(Player* p, Player* p2);
};