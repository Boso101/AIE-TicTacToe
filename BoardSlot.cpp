#include "BoardSlot.h"

bool GameBoard::BoardSlot::CanPlace()
{
	if (this->owner == Game::Player::EMPTY)
	{
		return true;
	}

	return false;
}

char GameBoard::BoardSlot::ToString()
{
	return this->value;
}