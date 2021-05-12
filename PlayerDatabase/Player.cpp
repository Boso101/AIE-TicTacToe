#include "Player.h"
#include <xpolymorphic_allocator.h>
#include <iostream>

Player::Player(const char* name, unsigned int highScore)
{
	this->highScore = highScore;

	//Copy the char* into a char[]
	strcpy_s(this->playerName, NAME_LENGTH, name);

}
void Player::PrintInformation()
{


	std::cout << this->highScore;
	std::cout <<", " <<  this->playerName << std::endl;

}

bool Player::operator<(const Player& other) const
{
	return highScore < other.highScore;
}

 char* const Player::GetName()
{
	 return playerName;
}

Player::Player()
{
	// Not my favourite thing to do but works for error checking
	strcpy_s(this->playerName, NAME_LENGTH, "null");
}