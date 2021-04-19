#include "Game.h"
#include "Player.h"
#include <iostream>
#include <time.h>

	Game::Game(PlayerConfig p1, PlayerConfig p2)
	{
		// setup the rng seed 
		currentState = GameState::GAME_START;

		player1 = p1;
		player2 = p2;

		srand(time(NULL));
	}

void Game::EndTurn()
{
	if (currentTurn == player1.playerID)
	{
		// Player 1's turn has ended
		SetCurrentTurn(Player::PLAYER_2);
		ChangeGameState(GameState::PLAYER_2_INPUT);
	}
	else	
	{ 
		// Player 2's turn has ended
		SetCurrentTurn(Player::PLAYER_1);
		ChangeGameState(GameState::PLAYER_1_INPUT);

	
	}
}
void Game::PrintLine(std::string words)
{
	std::cout << "\n" << words << std::endl;
}
void Game::Print(std::string words)
{
	std::cout << words;
}

void Game::Print(char word)
{
	std::cout << word;
}

void Game::PrintGameState()
{
	// Empty string
	

	// nested for loop into board
	Print("\n");

	for (int i = 0; i < board.ROWS; i++)
	{
		Print("\n");
		for (int j = 0; j < board.COLUMNS; j++)
		{

          Print(board.GetSpace(j, i).ToString());
		}
	}

	


}

bool Game::IsThereWinner()
{
	// Check all possibles win cons
	return false;
}

void Game::PlaceSymbol( int row, int column)
{
	//Get Current Player
	PlayerConfig currentPlayer;

	//TODO: Probably change
	if (currentTurn == Player::PLAYER_1)
	{
		currentPlayer = player1;
	}
	else
	{
		currentPlayer = player2;

	}

	// Get the passed BoardSlot
	BoardSlot slot = board.GetSpace(row, column);

	// Can we place here
	if (slot.CanPlace())
	{

		// We can so lets place players symbol here
		slot.owner = currentPlayer.playerID;
		slot.value = currentPlayer.playerSymbol;

		//Check for Winner
		if (IsThereWinner())
		{
			// Do stuff



			return;

		}

		// Then end the players turn
		this->EndTurn();

	}
	else
	{
		Print("Cannot place in this spot");

	}

}

void Game::ChangeGameState(GameState state)
{
	currentState = state;
}

void Game::SetStartingPlayer()
{
	int randomValue = rand() % 1;

	if (randomValue == 0)
	{
		SetCurrentTurn(Player::PLAYER_1);
		ChangeGameState(GameState::PLAYER_1_INPUT);
	}

	else
	{
		SetCurrentTurn(Player::PLAYER_2);
		ChangeGameState(GameState::PLAYER_2_INPUT);

	}

	PrintLine("");
	PrintLine("Starting Player :");
	
}

void Game::SetCurrentTurn(Player p)
{
	currentTurn = p;
}


