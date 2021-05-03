#pragma once
#include "Player.h"
#include "DatabaseState.h"
#include <string>
struct Database 
{


	

	Database(unsigned int maxPlayers);
	~Database();


	/// <summary>
	/// Write out the binary file containing all the players in the database
	/// </summary>
	/// <param name="directory"></param>
	void WriteFile(const char* directory);

	/// <summary>
	/// Read the binary file and load all the players in the database
	/// </summary>
	/// <param name="file"></param>
	void ReadFile(const char* file);

	/// <summary>
	/// Add player by passing in parameters of a player then calling a player constructor
	/// </summary>
	/// <param name="nameP"></param>
	/// <param name="score"></param>
	void AddPlayer(const std::string& nameP, unsigned int score);

	/// <summary>
	/// Add player by passing an instance of the player class.
	/// </summary>
	/// <param name="player"></param>
	void AddPlayer(Player& player);
	void BubbleSortPlayers(Player* playerList);
	bool IsFull();



	// Limit of max players
	const static unsigned int MAX_PLAYERS = 16;
	
	int maxPlayers;

	/// <summary>
	/// Keeps track of the amount of loaded players in the loadedPlayer array
	/// </summary>
	int loadedPlayerCount = 0;
	Player* loadedPlayers;
	DatabaseState state;


private:
	//Helper Method
	void Swap(Player* p, Player* p2);
};