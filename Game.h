#include "GameBoard.h"
#include "PlayerConfig.h"
#include <string>
namespace Game
{
	/// <summary>
	/// The main game, will be created in the main function and 
	/// is in charge of controlling the game flow
	/// </summary>
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