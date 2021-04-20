#include "GameBoard.h"


GameBoard GameBoard::GetCurrentGameBoard()
{
	return *this;
}
BoardSlot& GameBoard::GetSpace(int row, int column)
{
	return theBoard[row][column];
}

void GameBoard::SetupBoard(int rows, int columns)
{
	// init the board
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			theBoard[j][i].SetPosition(j, i);
	
		}
	}
}