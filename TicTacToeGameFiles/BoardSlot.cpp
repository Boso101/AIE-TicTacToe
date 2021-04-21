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

void BoardSlot::SetPosition(int row, int column)
{
	this->row = row;
	this->column = column;
}

