#pragma once

#include "GameBoard.h"
#include "PlayerConfig.h"
#include <string>
#include "GameState.h"
#include <vector>

	/// <summary>
	/// The main game, will be created in the main function and 
	/// is in charge of controlling the game flow.
	/// 
	/// To make use out of it, Create 2 PlayerConfig variables and then assign 
	/// the player1 and player2 variables to them
	/// </summary>
	struct Game
	{
		GameBoard board;
		
		PlayerConfig player1;
		PlayerConfig player2;

		Player currentTurn;
		GameState currentState;

		bool running = true;

	
		void Print(std::string words);
		void PrintLine(std::string words);
		void Print(char word);
		void PrintGameState();
		void PlaceSymbol(int row, int column);
		void EndTurn();
		bool IsThereWinner();
		void ChangeGameState(GameState state);
		void SetCurrentTurn(Player player);
		void AIAction();
		int UserInputPromptInt(std::string prompt);
		std::string UserInputPromptString(std::string prompt);
		void PrintAllFreeSpots();
		void ResetGame();
		/// <summary>
		/// Get the player config of whoevers turn it is
		/// </summary>
		/// <returns></returns>
		PlayerConfig GetCurrentPlayer();

		/// <summary>
		/// Randomize the starting player
		/// </summary>
		void SetStartingPlayer();

		//Constructor
		Game(PlayerConfig p1, PlayerConfig p2);

		std::vector<BoardSlot>  GetAllFreeSlots();


	};