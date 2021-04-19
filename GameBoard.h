#include "BoardSpace.h"
namespace GameBoard
{
	/// <summary>
	/// The main gameboard class. Contains functions to do with the gameboard
	/// such as Setting a Space, Getting a space, etc.
	/// </summary>
	class GameBoard
	{
	protected:
		BoardSpace theBoard[3][3];




	public:
		
		BoardSpace GetSpace(int row, int column);
		void SetSpace(int row, int column, char playerSymbol);
		GameBoard GetCurrentGameBoard();
	};




}