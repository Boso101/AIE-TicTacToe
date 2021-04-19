// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../TicTacToeGameFiles/PlayerConfig.h"
#include "../TicTacToeGameFiles/GameState.h"
#include "../TicTacToeGameFiles/Game.h"

/// <summary>
/// Console version of the game 
/// using the TicTacToe library just made
/// </summary>
/// <returns></returns>
int main()
{
    //Setup players
   PlayerConfig p1
    {
       Player::PLAYER_1,
       'O'


    };

    PlayerConfig p2
    {
       Player::PLAYER_2,
       'X'


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

            //Decide who goes first

            //Set that to the current player

            //Change Start
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
            // Print game state before we make a move

            mainGame.PrintGameState();

            // Trap in here while we give input
            while (true)
            {
                // if statement that holds whatever the user types
                mainGame.PlaceSymbol( 0, 0);

            }
            break;
        }

        // When it is player 2's turn
        case GameState::PLAYER_2_INPUT:
        {


            mainGame.EndTurn();
            break;
        }

        }
    }

}

