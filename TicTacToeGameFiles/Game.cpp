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

	//TODO: Maybe dont have this here
	// AI Begins thinking
	AIAction();
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
	
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board.GetSpace(0,0).ToString() << "  |  " << board.GetSpace(0, 1).ToString() << "  |  " << board.GetSpace(0,2).ToString() << std::endl;

	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;

	std::cout << "  " << board.GetSpace(1,0).ToString() << "  |  " << board.GetSpace(1,1).ToString() << "  |  " << board.GetSpace(1,2).ToString() << std::endl;

	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;

	std::cout << "  " << board.GetSpace(2,0).ToString() << "  |  " << board.GetSpace(2,1).ToString() << "  |  " << board.GetSpace(2,2).ToString()<< std::endl;

	std::cout << "     |     |     " << std::endl << std::endl;

	


}

bool Game::IsThereWinner()
{
	// Check all possibles win cons
	return false;
}
PlayerConfig Game::GetCurrentPlayer()
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

	return currentPlayer;
}


void Game::PlaceSymbol( int row, int column)
{
	
	PlayerConfig currentPlayer = GetCurrentPlayer();

	// Get the passed BoardSlot
	BoardSlot& slot = board.GetSpace(row, column);

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
		EndTurn();

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

void Game::AIAction()
{
	PlayerConfig turnPlayer = GetCurrentPlayer();
	
	//Only run the AI if the game is still going and the playerconfig allows AI
	if ( !IsThereWinner() && !turnPlayer.isAI)
	{
		return;
	}
	else
	{
		// AI Logic Here






		
	}

}


