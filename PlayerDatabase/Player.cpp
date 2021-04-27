#include "Player.h"
#include <xpolymorphic_allocator.h>

Player::Player(const char* name, unsigned int highScore)
{
	this->highScore = highScore;

	//Copy the char* into a char[]
	strcpy_s(this->playerName, NAME_LENGTH, name);

}