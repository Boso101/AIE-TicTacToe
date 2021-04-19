#include "GameBoard.h"


GameBoard GameBoard::GetCurrentGameBoard()
{
	return *this;
}
BoardSlot GameBoard::GetSpace(int row, int column)
{
	return theBoard[row][column];
}