#include "Game.h"
#include "Player.h"
namespace Game
{


void Game::Game::EndTurn()
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
}