#include "GameBoard.h"
#include "PlayerConfig.h"
#include <string>
#include "GameState.h"
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

		Player currentTurn;
		GameState currentState = GameState::GAME_START;

		bool running = true;

	
		void Print(std::string words);
		void PrintGameState();
		void PlaceSymbol(PlayerConfig currentPlayer);
		void EndTurn();


	};


}