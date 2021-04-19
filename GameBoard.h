#include "BoardSpace.h"
namespace GameBoard
{
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