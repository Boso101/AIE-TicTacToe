#include "Database.h"
#include <algorithm>
#include <iostream>]
#include <fstream>

bool Database::WriteFile(const char* directory)
{
	// Check if file exists
	std::fstream file;
	file.open(directory, std::ios::out | std::ios::binary);


	if (file.good())
	{
		BubbleSortPlayersByName(loadedPlayers, '>');


		//Write maximum players out
		file.write((const char*) & maxPlayers, sizeof(maxPlayers));

		//Write players in use
		file.write((const char*)&loadedPlayerCount, sizeof(loadedPlayerCount));

		// Write our list of players
		file.write((const char*)loadedPlayers, loadedPlayerCount * sizeof(Player) );



		file.close();
		return true;
	}

	file.close();
	return false;
}

bool Database::ReadFile(const char* file)
{
	std::fstream fileS;
	fileS.open(file, std::ios::in | std::ios::binary);
	
	if (fileS.good())
	{
		unsigned int maximumPlayers;
		//load up the array of player pointers
		fileS.read((char*)&maximumPlayers, sizeof(unsigned int));

		if (maximumPlayers > 10000)
		{
			fileS.close();
			return false;
		}

		//Reallocate player list if different size
		if (this->maxPlayers != maximumPlayers)
		{
			this->maxPlayers = maximumPlayers;
			delete[] this->loadedPlayers;
			this->loadedPlayers = new Player[maximumPlayers];
		}

		//loadedPlayerCount is the size of how many file elements exist

		//Read players in use 
		unsigned int currentPlayersInUse;
		fileS.read((char*)&currentPlayersInUse, sizeof(unsigned int));

		if (currentPlayersInUse > maximumPlayers)
		{
			fileS.close();
			return false;
		}

		std::cout << "Sucessfully Loaded " << loadedPlayerCount << " Players." << std::endl;


		//Match the count from the file
		this->loadedPlayerCount = currentPlayersInUse;

		
		//Read the array of players
		fileS.read((char*)loadedPlayers, currentPlayersInUse * sizeof(Player) );



		//Give it a sort just incase
	    BubbleSortPlayersByName(loadedPlayers, '>');
		fileS.close();
		return true;
	}
	
	std::cout << "No File Detected..." << std::endl;

	fileS.close();
	return false;
}


void Database::BubbleSortPlayersByScore(Player* playerList, char op)

	{
	//int i, j;
	//	for (i = 0; i < this->loadedPlayerCount - 1; i++)
	//	{ 
	//		// Last i elements are already in place 
	//		for (j = 0; j < this->loadedPlayerCount - 1 ; j++)
	//		{
	//			//desc
	//			if (op == '>')
	//			{
	//				//Swap so that highest comes first
	//				if (playerList[j].highScore > loadedPlayers[j - 1].highScore)
	//					Database::Swap(&loadedPlayers[j], &loadedPlayers[j - 1]);
	//			}

	//			//asc
	//			else
	//			{
	//				if (playerList[j].highScore > loadedPlayers[j + 1].highScore)
	//					Database::Swap(&loadedPlayers[j], &loadedPlayers[j + 1]);
	//			}

	//		
	//		}
	//	}

	if (op == '>')
	{
		std::sort(loadedPlayers, loadedPlayers + loadedPlayerCount, ComparePlayerScoreDesc);

	}
	else
	{
		std::sort(loadedPlayers, loadedPlayers + loadedPlayerCount, ComparePlayerScoreAsc);

	}

	}

void Database::BubbleSortPlayersByName(Player* playerList, char op)

{
	//int i, j;
	//for (i = 0; i < this->loadedPlayerCount - 1; i++)
	//{
	//	// Last i elements are already in place 
	//	for (j = 0; j < this->loadedPlayerCount - 1; j++)
	//	{

	//		//desc
	//		if (op == '>')
	//		{
	//			//Swap so that highest comes first
	//			if (playerList[j].GetName() > loadedPlayers[j - 1].GetName())
	//				Database::Swap(&loadedPlayers[j], &loadedPlayers[j - 1]);
	//		}

	//		//asc
	//		else
	//		{
	//			if (playerList[j].GetName() > loadedPlayers[j + 1].GetName())
	//				Database::Swap(&loadedPlayers[j], &loadedPlayers[j + 1]);
	//		}


	//	}
	//}

	if (op == '>')
	{
		std::sort(loadedPlayers, loadedPlayers + loadedPlayerCount, ComparePlayerNameDesc);

	}
	else
	{
		std::sort(loadedPlayers, loadedPlayers + loadedPlayerCount, ComparePlayerNameAsc);


	}
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
			Database::ModifyPlayerEntry("PlayerList.bin",player,"name");
			
		}
		else if (choice == "score" || choice == "highscore")
		{
			Database::ModifyPlayerEntry("PlayerList.bin", player, "score");


		}

	
	}

std::string Database::ModifyPlayerNamePrompt()
{
	char* newName = nullptr;

	std::cout << "New Name : ";
	std::cin >> newName;


	//Change if something new
	if (newName != "")
	{
		return newName;
	}
}

void Database::ModifyPlayerEntry(const char* directory, Player& toModify, const char* modType)
{
	std::fstream file(directory, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	
	
	
	if (file.good())
	{
		int constexpr playerSize = sizeof(Player);
		//Pass the header stuff such as loaded player count and max players
		
		file.seekg(sizeof(unsigned int) * 2);

		//Iterate through players and compare name

		//current looking player
		Player p;

		while (!file.eof())
		{
			file.read((char*)&p, playerSize);
			
			// We found our player
		
			if (*toModify.playerName == *p.playerName)
			{
				//offset start player
				file.seekg(-playerSize, file.cur);

				//check what we need to change
				if (modType == "name")
				{
					strcpy_s(p.playerName, Player::NAME_LENGTH, ModifyPlayerNamePrompt().c_str());

					

					//Overwrite name

					file.write((const char*)&p, playerSize);
					return;
				}
				else if (modType == "highscore")
				{
					p.highScore = ModifyHighScorePrompt();

					//Overwrite Score
					file.write((const char*)&p, playerSize);
					return;
				}

				
			}
		}

		


	}

	file.close();
	
	//Reload Database
	ReadFile("PlayerList.bin");
}

unsigned int Database::ModifyHighScorePrompt()
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

	return newScore;

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


void Database::BinarySearchPlayer(unsigned int highScore)
{
	// Sort first
	BubbleSortPlayersByName(loadedPlayers, '>');


	int element = BinarySearch(loadedPlayers, 0, loadedPlayerCount - 1, highScore);

	//Algorithm returns -1 if it did not find
	if (element != -1)
	{
		std::cout << "Found an entry" << std::endl;
		loadedPlayers[element].PrintInformation();
	}
	else
	{
		std::cout << "Could not find anyone with a highscore value of "<< highScore << std::endl;

	}

}

//TODO: Change to name instead of targetScore
int Database::BinarySearch(Player* playerList, int left, int right, unsigned int targetScore)
{
	// A recursive binary search function. It returns
	// a reference  to the first player it finds which holds 
	// the specified highScore
	
		if (right >= left) {
			int mid = left + (right - left) / 2;

			// If the element is present at the middle
			// itself
			if (playerList[mid].highScore == targetScore)
				return mid;

			// If element is smaller than mid, then
			// it can only be present in left subarray
			if (playerList[mid].highScore > targetScore)
				return BinarySearch(playerList, left, mid - 1, targetScore);

			// Else the element can only be present
			// in right subarray
			return BinarySearch(playerList, mid + 1, right, targetScore);
		}

		// We reach here when element is not
		// present in array
		return -1;

}

bool  Database::IsFull()
{
	return loadedPlayerCount == maxPlayers;
}

const Player* Database::FirstElement()
{
	return loadedPlayers;
}

const Player* Database::LastElement()
{
	return loadedPlayers + loadedPlayerCount;
}

Player& Database::operator[](unsigned int pos)
{
	if (pos < loadedPlayerCount)
		return loadedPlayers[pos];

	else
		throw std::out_of_range("Invalid Element");

}

void Database::PrintAllPlayers()
{
	std::cout << "\n" << std::endl;
	std::cout << "==========================" << std::endl;
	for (int i = 0; i < loadedPlayerCount; i++)
	{
		std::cout << "[" << i << "]" << " ";
		loadedPlayers[i].PrintInformation();
	}
	std::cout << "==========================" << std::endl;

	std::cout << "\n" << std::endl;
}

//TODO: Interface
//Should really have this as an interface eventually
bool Database::ComparePlayerScoreDesc(Player& left, Player& right)
{
	return left.highScore > right.highScore;
}

bool Database::ComparePlayerScoreAsc(Player& left,  Player& right)
{
	return left.highScore < right.highScore;
}

bool Database::ComparePlayerNameDesc(Player& left, Player& right)
{
	return (strcmp(left.playerName, right.playerName) > 0);
}

bool Database::ComparePlayerNameAsc(Player& left, Player& right)
{
	return (strcmp(left.playerName, right.playerName) < 0);
}

bool Database::ComparePlayerNameDescEqual(Player& left, Player& right)
{
	return (strcmp(left.playerName, right.playerName) > 0);
}


Database::~Database()
{
	//WriteFile("PlayerList.bin");
	delete[] loadedPlayers;
	delete this;
}
