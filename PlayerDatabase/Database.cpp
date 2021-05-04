#include "Database.h"

#include <algorithm>
#include <iostream>

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
				if (playerList[j].highScore < loadedPlayers[j + 1].highScore)
					Database::Swap(&loadedPlayers[j], &loadedPlayers[j - 1]);
	}




void Database::Swap(Player* p1, Player* p2)
{
	Player temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void Database::ModifyPlayerPrompt(Player& player)
{
	
		//Valid element
		std::cout << "Now modifying " << player.playerName << std::endl;
		std::cout << "Do you wish to modify the highscore or name?\n\nPlease type either name for name change or score for highscore change." << std::endl;
		std::string choice;
		std::cin >> choice;

		if (choice == "name")
		{
			// if we are here then we decided to modify the name
			Database::ModifyPlayerNamePrompt(player);
			
		}
		else if (choice == "score")
		{
			Database::ModifyHighScorePrompt(player);


		}
	}

void Database::ModifyPlayerNamePrompt(Player& player)
{
	std::string newName;

	std::cout << "New Name : ";
	std::cin >> newName;


	//Change if something new
	if (newName != "")
	{
		strcpy_s(player.playerName, Player::NAME_LENGTH, newName.c_str());
		std::cout << "Name changed sucessfully!" << std::endl;
	}
}

void Database::ModifyHighScorePrompt(Player& player)
{
	unsigned int newScore;
	// here because we decided to change the high score

	//TODO: Make sure its actually a number..

	std::cout << "New Score : ";
	std::cin >> newScore;

	if (newScore < 0)
	{
		newScore = 0;
	}

	player.highScore = newScore;
	std::cout << "Score changed sucessfully!" << std::endl;
}





Database::Database(unsigned int maximumPlayers)
{
	this->maxPlayers = std::min(std::max(maximumPlayers, 0u), MAX_PLAYERS);
	
	loadedPlayers = new Player[this->maxPlayers];

	state = DatabaseState::LOAD_PROFILES;
}

void Database::AddPlayer(const std::string& nameP, unsigned int highScore)
{
	if (!IsFull())
	{
		loadedPlayers[loadedPlayerCount] = Player(nameP.c_str(), highScore);
		//Increase player in use after adding 
		loadedPlayerCount++;
	}
	else
	{
		//Cannot add anymore
		//throw error
		std::exception("Player Database Full...");
	}
}

void Database::AddPlayer(Player& player)
{
	if (!IsFull())
	{
		loadedPlayers[loadedPlayerCount] = player;
		//Increase player in use after adding 
		loadedPlayerCount++;
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
	return loadedPlayerCount == maxPlayers;
}

Database::~Database()
{
	delete[] loadedPlayers;
	delete this;
}
