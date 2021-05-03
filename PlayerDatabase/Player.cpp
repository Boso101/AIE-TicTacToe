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

	std::cout << this->playerName;
	std::cout << "," << this->highScore << std::endl;


}
Player::Player()
{

}