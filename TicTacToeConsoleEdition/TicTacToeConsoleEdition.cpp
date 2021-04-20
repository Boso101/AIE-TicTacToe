// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../TicTacToeGameFiles/PlayerConfig.h"
#include "../TicTacToeGameFiles/GameState.h"
#include "../TicTacToeGameFiles/Game.h"

/// <summary>
/// Console version of the game 
/// using the TicTacToe library just made.
/// 
/// If for whatever reasons errors occur, then make sure to 
/// set TicTacToeGame type to Static Library
/// </summary>
/// <returns></returns>
int main()
{
    //Setup players
   PlayerConfig p1
    {
       Player::PLAYER_1,
       'O',
       false


    };

    PlayerConfig p2
    {
       Player::PLAYER_2,
       'X',
       true


    };
    // Init the Main Game

    Game mainGame(p1,p2);


    // Main Loop

    while (mainGame.running)
    {
        switch (mainGame.currentState)
        {

            // On game start
        case GameState::GAME_START:
        {
            //print the current board
            mainGame.PrintLine("Game Launched");
            mainGame.SetStartingPlayer();

            

            break;
        }

        // Once we finish a game
        case GameState::FINISH:
        {
            break;
        }

        // When it is player 1's turn
        case GameState::PLAYER_1_INPUT:
        {
            mainGame.AIAction();
            // Print game state before we make a move

            mainGame.PrintGameState();

            //User Input
            mainGame.PrintLine("");
            mainGame.PrintAllFreeSpots();
            std::vector<BoardSlot> allFreeSlots = mainGame.GetAllFreeSlots();
            int choice = mainGame.UserInputPrompt("Please enter a number correlating to the grid : ");

            // + 1 so that the user doesnt start at index 0
            if (choice < allFreeSlots.size())
            {
                BoardSlot slot = allFreeSlots.at(choice);
                mainGame.PlaceSymbol(slot.row, slot.column);
            }
            else
            {
                std::cout << "Please enter a number between 0 and 8";
            }
            
            break;

         
            break;
        }

        // When it is player 2's turn
        case GameState::PLAYER_2_INPUT:
        {

            mainGame.AIAction();
            mainGame.PrintGameState();

            
            break;
        }

        }
    }


    

}




