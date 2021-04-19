#include "BoardSpace.h"
#include "Player.h"
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
		const int ROWS = 3;
		const int COLUMNS = 3;
		
		BoardSpace GetSpace(int row, int column);
		void SetSpace(int row, int column, char playerSymbol);
		GameBoard GetCurrentGameBoard();
	};




}