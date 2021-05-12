#pragma once

struct  Player
{
	static const unsigned int NAME_LENGTH = 64;
	//Constructor 
	Player(const char* name, unsigned int highScore);
	Player();

	unsigned int highScore;
	char playerName[NAME_LENGTH];


	 char* const GetName();
	void PrintInformation();


};
