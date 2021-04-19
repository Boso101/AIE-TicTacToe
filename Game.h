#pragma once

#include "GameBoard.h"
#include "PlayerConfig.h"
#include <string>
#include "GameState.h"
namespace Game
{
	/// <summary>
	/// The main game, will be created in the main function and 
	/// is in charge of controlling the game flow.
	/// 
	/// To make use out of it, Create 2 PlayerConfig variables and then assign 
	/// the player1 and player2 variables to them
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
		void PrintLine(std::string words);
		void Print(char word);
		void PrintGameState();
		void PlaceSymbol(PlayerConfig currentPlayer, int row, int column);
		void EndTurn();
		bool IsThereWinner();
		void ChangeGameState(GameState state);

		/// <summary>
		/// Randomize the starting player
		/// </summary>
		void SetStartingPlayer();

		//Constructor
		Game();


	};


}