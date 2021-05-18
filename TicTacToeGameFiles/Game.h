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

		Player currentTurn = Player::PLAYER_1;
		GameState currentState;

		bool running = true;

	

		// Helper methods for printing

		void Print(std::string words);
		void PrintLine(std::string words);
		void Print(char word);
		void PrintGameState();

		/// <summary>
		/// Places the current turns player symbol to the specified coordinate
		/// </summary>
		/// <param name="row"></param>
		/// <param name="column"></param>
		void PlaceSymbol(int row, int column);


		/// <summary>
		/// Ends current players turn
		/// </summary>
		void EndTurn();

		/// <summary>
		/// Has a whole lot of checks to determine if the game is a draw or there is a winner
		/// </summary>
		/// <returns></returns>
		bool IsThereWinner();

		/// <summary>
		/// Directly writes to the current gamestate
		/// </summary>
		/// <param name="state"></param>
		void ChangeGameState(GameState state);
		void SetCurrentTurn(Player player);
		/// <summary>
		/// When AI tries to do something
		/// </summary>
		void AIAction();
		// For console based game - Prompt user
		int UserInputPromptInt(std::string prompt);
		std::string UserInputPromptString(std::string prompt);
		void PrintAllFreeSpots();

		/// <summary>
		/// Starts the game again, clearing the board
		/// </summary>
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