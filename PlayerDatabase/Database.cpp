#include "Database.h"

#include <algorithm>

void Database::WriteFile(const char* directory)
{
	// Check if file exists



}

void Database::ReadFile(const char* file)
{
	AddPlayer("John", 5);
	AddPlayer("Joe", 69);



	//Give it a sort
	BubbleSortPlayers(loadedPlayers);
}

void Database::BubbleSortPlayers(Player* playerList)

	{
		int i, j;
		for (i = 0; i < this->maxPlayers - 1; i++)

			// Last i elements are already in place 
			for (j = 0; j < this->maxPlayers - 1; j++)
				if (playerList[j].highScore > loadedPlayers[j + 1].highScore)
					Database::Swap(&loadedPlayers[j], &loadedPlayers[j + 1]);
	}




void Database::Swap(Player* p1, Player* p2)
{
	Player temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}




Database::Database(unsigned int maximumPlayers)
{
	this->maxPlayers = std::min(std::max(maximumPlayers, 0u), MAX_PLAYERS);
	
	loadedPlayers = new Player[this->maxPlayers];

	state = DatabaseState::LOAD_PROFILES;
}

void Database::AddPlayer(const std::string& nameP, unsigned int highScore)
{
	if (playerInUse < maxPlayers)
	{
		loadedPlayers[playerInUse] = Player(nameP.c_str(), highScore);
		//Increase player in use after adding 
		playerInUse++;
	}
	else
	{
		//Cannot add anymore
		//throw error
		std::exception("Player Database Full...");
	}
}

bool  Database::IsFull()
{
	return playerInUse == maxPlayers;
}

Database::~Database()
{
	delete[] loadedPlayers;
	delete this;
}
