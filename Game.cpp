#include "Game.h"
#include "Player.h"
#include <iostream>
namespace Game
{


void Game::EndTurn()
{
	if (currentTurn == Player::PLAYER_1)
	{
		// Player 1's turn has ended
		currentTurn = Player::PLAYER_2;
	}
	else	
	{ 
		// Player 2's turn has ended
		currentTurn = Player::PLAYER_1;
	
	
	}
}

void Game::Print(std::string words)
{
	std::cout << words << std::endl;
}

void Game::PrintGameState()
{
	// Empty string
	std::string gameString = "";

	// nested for loop into board

	for (int i = 0; i < board.ROWS - 1; i++)
	{
		for (int j = 0; j < board.COLUMNS; j++)
		{

			gameString << board.GetSpace(j, i);
		}
	}

	


}
}