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
		
		BoardSlot GetSpace(int row, int column);
		GameBoard GetCurrentGameBoard();
	};



