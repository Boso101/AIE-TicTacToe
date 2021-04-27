#pragma once
#include "Player.h"
#include "DatabaseState.h"
struct Database 
{
	Database();

	



	void WriteFile(const char* directory, Player toWrite);
	void ReadFile(const char* file);
	void BubbleSortPlayers(Player playerList[]);

	void AddPlayer(Player p);
	void RemovePlayer(Player p);

	const static int MAX_PLAYERS = 64;
	Player loadedPlayers[MAX_PLAYERS];
	DatabaseState state;
};