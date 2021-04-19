#include "BoardSlot.h"

bool BoardSlot::CanPlace()
{
	if (this->owner == Player::EMPTY)
	{
		return true;
	}

	return false;
}

char BoardSlot::ToString()
{
	return this->value;
}