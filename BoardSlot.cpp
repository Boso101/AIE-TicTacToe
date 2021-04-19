#include "BoardSlot.h"

bool GameBoard::BoardSlot::CanPlace()
{
	if (this->owner == Game::Player::EMPTY)
	{
		return true;
	}
}

char GameBoard::BoardSlot::ToString()
{
	return this->value;
}