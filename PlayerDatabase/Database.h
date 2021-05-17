#pragma once
#include "Player.h"
#include "DatabaseState.h"
#include <string>
struct Database 
{


	

	Database(unsigned int maxPlayers);
	~Database();

	/// <summary>
	/// Easy getters for elements
	/// </summary>
	const Player* FirstElement();
	const Player* LastElement();

	Player& operator[](unsigned int pos);

	/// <summary>
	/// Write out the binary file containing all the players in the database
	/// </summary>
	/// <param name="directory"></param>
	bool WriteFile(const char* directory);

	/// <summary>
	/// Read the binary file and load all the players in the database
	/// </summary>
	/// <param name="file"></param>
	bool ReadFile(const char* file);

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

	/// <summary>
	/// Bubbme sort function for score
	/// </summary>
	/// <param name="playerList"></param>
	/// <param name="op"></param>
	void BubbleSortPlayersByScore(Player* playerList, char op);
	void BubbleSortPlayersByName(Player* playerList, char op);
	bool IsFull();

	/// <summary>
	/// Lets the user modify both the Name and Highscore of a Player reference.
	/// </summary>
	/// <param name="player"></param>
	void ModifyPlayerPrompt(Player& player);

	unsigned int ModifyHighScorePrompt();
	std::string ModifyPlayerNamePrompt();


	/// <summary>
	/// Use this method to scan through the file and find the modified player
	/// </summary>
	/// <param name="toModify"></param>
	void ModifyPlayerEntry(const char* directory, Player& toModify, const char* modType);


	/// <summary>
	/// Tries to find a player via binary search with the passed high score.
	/// </summary>
	/// <param name="highScore"></param>

	void BinarySearchPlayer(unsigned int highScore);


	//TODO: Name Version
	/// <summary>
	/// The actual binary search recursive algorithm
	/// </summary>
	/// <param name="playerArray"></param>
	/// <returns>The index of the found player</returns>
	int BinarySearch(Player* playerList, int left, int right, unsigned int targetScore);



	// Limit of max players
	const static unsigned int MAX_PLAYERS = 16;

	//file name
	const char* FILE_NAME = "PlayerList.bin";
	
	unsigned int maxPlayers;

	/// <summary>
	/// Keeps track of the amount of loaded players in the loadedPlayer array
	/// </summary>
	int loadedPlayerCount = 0;
	Player* loadedPlayers = nullptr;
	DatabaseState state;

	/// <summary>
	/// Print all Players
	/// </summary>
	void PrintAllPlayers();

	// Helper methods for sorting

	static bool ComparePlayerScoreDesc( Player& left,  Player& right);
	static bool ComparePlayerScoreAsc( Player& left,  Player& right);

	static bool ComparePlayerNameDesc( Player& left,  Player& right);
	static bool ComparePlayerNameAsc( Player& left,  Player& right);


	static bool ComparePlayerNameDescEqual(Player& left, Player& right);

};