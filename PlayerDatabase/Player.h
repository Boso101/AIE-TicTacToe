#pragma once

struct  Player
{
	static const unsigned int NAME_LENGTH = 16;
	//Constructor 
	Player(const char* name, unsigned int highScore);

	unsigned int highScore;
	char playerName[NAME_LENGTH];


};
