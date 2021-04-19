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

	for (int i = 0; i < board.ROWS - 1; i++)
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

		// Then end the players turn
		this->EndTurn();

	}
	else
	{
		Print("Cannot place in this spot");

	}

}
}