#include "Game.h"
#include "Player.h"
#include <iostream>
#include <time.h>
namespace Game
{
	Game::Game(PlayerConfig p1, PlayerConfig p2)
	{
		// setup the rng seed 
		currentState = GameState::GAME_START;

		player1 = p1;
		player2 = p2;

		srand(time(NULL));
		SetStartingPlayer();
	}

void Game::EndTurn()
{
	if (currentTurn == Player::PLAYER_1)
	{
		// Player 1's turn has ended
		currentTurn = Player::PLAYER_2;
		ChangeGameState(GameState::PLAYER_2_INPUT);
	}
	else	
	{ 
		// Player 2's turn has ended
		currentTurn = Player::PLAYER_1;
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

void Game::PlaceSymbol(PlayerConfig currentPlayer, int row, int column)
{

	// Get the passed BoardSlot
	GameBoard::BoardSlot slot = board.GetSpace(row, column);

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
		currentTurn = Player::PLAYER_1;
		ChangeGameState(GameState::PLAYER_1_INPUT);
	}

	else
	{
		currentTurn == Player::PLAYER_2;
		ChangeGameState(GameState::PLAYER_2_INPUT);

	}

	PrintLine("");
	PrintLine("Starting Player :");
	
}




}