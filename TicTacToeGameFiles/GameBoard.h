#pragma once

#include "Player.h"
#include "BoardSlot.h"

	/// <summary>
	/// The main gameboard class. Contains functions to do with the gameboard
	/// such as Setting a Space, Getting a space, etc.
	/// </summary>
	class GameBoard
	{
	protected:
		BoardSlot theBoard[3][3];




	public:
		// Use these so that for loops can read them readonly
		const int ROWS = 3;
		const int COLUMNS = 3;

		// All spots
		const BoardSlot ALL_SLOTS[9] =
		{
			theBoard[0][0],
			theBoard[0][1],
			theBoard[0][2],

			theBoard[1][0],
			theBoard[1][1],
			theBoard[1][2],

			theBoard[2][0],
			theBoard[2][1],
			theBoard[2][2],

		};
		
		BoardSlot& GetSpace(int row, int column);
		GameBoard GetCurrentGameBoard();
	};



