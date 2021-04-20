#include "Game.h"
#include "Player.h"
#include <iostream>
#include <time.h>

	Game::Game(PlayerConfig p1, PlayerConfig p2)
	{
		// setup the rng seed 
		board.SetupBoard(3, 3);
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
	std::cout << "It is now Player_" << int(GetCurrentPlayer().playerID) << "'s turn." << std::endl;


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
	//Clear the console
	system("CLS");

	std::cout << "\n" << std::endl;
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
	// Check all possibles win cons.
	// We at the end of the game
	if (GetAllFreeSlots().size() == 0)
	{
		ChangeGameState(GameState::FINISH);
		//Print the game state again
		PrintGameState();
		PrintLine("Draw!");
		return true;
	}

	//Check win cons Across
	//TODO: Probably rework this
	// Have to do this because all slots have a default enum of "EMPTY"
	if (board.GetSpace(0,0).owner != Player::EMPTY && board.GetSpace(0, 0).owner == board.GetSpace(0, 1).owner && board.GetSpace(0, 2).owner == board.GetSpace(0, 1).owner

		|| board.GetSpace(1, 0).owner != Player::EMPTY && board.GetSpace(1, 0).owner == board.GetSpace(1, 1).owner && board.GetSpace(1, 2).owner == board.GetSpace(1, 0).owner
		|| board.GetSpace(2, 0).owner != Player::EMPTY && board.GetSpace(2, 0).owner == board.GetSpace(2, 1).owner && board.GetSpace(2, 2).owner == board.GetSpace(2, 0).owner
		)
	{
		
		return true;

	}

	//Vertical Checks
	if (board.GetSpace(0, 0).owner != Player::EMPTY && board.GetSpace(0, 0).owner == board.GetSpace(1, 0).owner && board.GetSpace(2, 0).owner == board.GetSpace(0, 0).owner

		|| board.GetSpace(0, 1).owner != Player::EMPTY && board.GetSpace(0, 1).owner == board.GetSpace(1, 1).owner && board.GetSpace(2, 1).owner == board.GetSpace(0, 1).owner
		|| board.GetSpace(0, 2).owner != Player::EMPTY && board.GetSpace(0, 2).owner == board.GetSpace(1, 2).owner && board.GetSpace(2, 2).owner == board.GetSpace(0, 2).owner

		)
	{
		return true;

	}

	//Diagonal Checks
	if (board.GetSpace(0, 0).owner != Player::EMPTY && board.GetSpace(0, 0).owner == board.GetSpace(1, 1).owner && board.GetSpace(2, 2).owner == board.GetSpace(0, 0).owner
		|| board.GetSpace(2, 0).owner != Player::EMPTY &&  board.GetSpace(2, 0).owner == board.GetSpace(1, 1).owner && board.GetSpace(0, 2).owner == board.GetSpace(2, 0).owner
		|| board.GetSpace(0, 2).owner != Player::EMPTY && board.GetSpace(0, 2).owner == board.GetSpace(1, 1).owner && board.GetSpace(2, 0).owner == board.GetSpace(0, 2).owner
		|| board.GetSpace(2, 2).owner != Player::EMPTY && board.GetSpace(2, 2).owner == board.GetSpace(1, 1).owner && board.GetSpace(0, 0).owner == board.GetSpace(2, 2).owner
		)
	{
		return true;
	}

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

void Game::ResetGame()
{
	for (int i = 0; i < board.ROWS; i++)
	{
		for (int j = 0; j < board.COLUMNS; j++)
		{
			BoardSlot& slot = board.GetSpace(j, i);

			slot.value = '-';
			slot.owner = Player::EMPTY;

		}
	}
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

		PrintGameState();

		//Check for Winner
		if (IsThereWinner())
		{
			// Do stuff


			PrintLine("Game Over!");
			ChangeGameState(GameState::FINISH);
			return;

		}
		PrintLine("");
		PrintLine("Successfully Placed ! Ending Turn...");
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
	std::cout << "Current Player : " << (int)GetCurrentPlayer().playerID << std::endl;
	
}

void Game::SetCurrentTurn(Player p)
{
	currentTurn = p;
}

void Game::AIAction()
{
	PlayerConfig turnPlayer = GetCurrentPlayer();
	std::vector<BoardSlot> freeSlots = GetAllFreeSlots();
	
	//Only run the AI if the game is still going and the playerconfig allows AI
	
	if(!IsThereWinner() && turnPlayer.isAI)
	{
		// AI Logic Here
		// For now iteratively place in the next free spot
		BoardSlot slot = freeSlots.at(0);
		PlaceSymbol(slot.row, slot.column);
		





	}


}
//TODO: Not sure if this is very inefficient
// IDK if it cleans up after each use
std::vector<BoardSlot> Game::GetAllFreeSlots()
{
	std::vector<BoardSlot> listOfSpots;
	// Loop through and only add free spots
	

	for (int i = 0; i < board.ROWS; i++)
	{
		for (int j = 0; j < board.COLUMNS; j++)
		{
			BoardSlot slot = board.GetSpace(j, i);
			
			if (slot.CanPlace())
			{
				listOfSpots.push_back(slot);
			}

		}
	}

	return listOfSpots;
}

void Game::PrintAllFreeSpots()
{
	PrintLine("Free Spots :");
	int size = GetAllFreeSlots().size();
	for (int i = 0; i < size; i++)
	{
		std::cout << "Slot " << i << std::endl;
	}
}

int Game::UserInputPromptInt(std::string promptMessage)
{
	int userResponse;
	std::cout << promptMessage;
	std::cin >> userResponse;
	return userResponse;
}

std::string Game::UserInputPromptString(std::string promptMessage)
{
	std::string userResponse;
	std::cout << promptMessage;
	std::cin >> userResponse;
	return userResponse;
}


