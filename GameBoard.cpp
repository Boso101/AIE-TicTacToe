#include "GameBoard.h"



GameBoard::GameBoard GameBoard::GameBoard::GetCurrentGameBoard()
{
	return *this;
}
GameBoard::BoardSlot GameBoard::GameBoard::GetSpace(int row, int column)
{
	return theBoard[row][column];
}