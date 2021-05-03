#include "Database.h"

void Database::WriteFile(const char* directory, Player toWrite)
{
	// Check if file exists



}

void Database::ReadFile(const char* file)
{

}

void Database::BubbleSortPlayers(Player playerList[])

	{
		int i, j;
		for (i = 0; i < this->maxPlayers - 1; i++)

			// Last i elements are already in place 
			for (j = 0; j < this->maxPlayers - 1; j++)
				if (loadedPlayers[j].highScore > loadedPlayers[j + 1].highScore)
					Database::Swap(&loadedPlayers[j], &loadedPlayers[j + 1]);
	}


void Database::AddPlayer(Player p)
{

}

void Database::Swap(Player* p1, Player* p2)
{
	Player temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


void Database::RemovePlayer(Player p)
{

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
}

Database::Database()
{

}

Database::~Database()
{
	delete[] loadedPlayers;
}
