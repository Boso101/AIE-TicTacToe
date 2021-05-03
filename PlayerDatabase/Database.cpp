#include "Database.h"

void Database::WriteFile(const char* directory)
{
	// Check if file exists



}

void Database::ReadFile(const char* file)
{

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




Database::Database(unsigned int maxPlayers)
{
	//Clamping
	if (maxPlayers <= 0)
	{
		this->maxPlayers = 4;
	}

	if (maxPlayers > 16)
	{
		this->maxPlayers = 16;
	}
	
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

Database::Database()
{

}

Database::~Database()
{
	delete[] loadedPlayers;
}
