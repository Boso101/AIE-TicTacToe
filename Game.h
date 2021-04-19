#include "GameBoard.h"
#include "PlayerConfig.h"
#include <string>
namespace Game
{

	struct Game
	{
		GameBoard::GameBoard board;
		
		PlayerConfig player1;
		PlayerConfig player2;



		void Print(std::string words);
		void PrintGameState();
		void PlaceSymbol(PlayerConfig currentPlayer);
		void EndTurn();


	};


}