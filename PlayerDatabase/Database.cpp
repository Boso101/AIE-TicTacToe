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

}

void Database::AddPlayer(Player p)
{

}

void Database::RemovePlayer(Player p)
{

}

Database::Database(unsigned int maxPlayers)
{
	//Clamping
	if (maxPlayers <= 0)
	{
		maxPlayers = 4;
	}

	if (maxPlayers > 16)
	{
		maxPlayers = 16;
	}
	
	loadedPlayers = new Player[maxPlayers];
}

Database::Database()
{

}

Database::~Database()
{
	delete[] loadedPlayers;
}
