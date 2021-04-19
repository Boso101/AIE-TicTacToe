// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../PlayerConfig.h"
#include "../Game.h"

/// <summary>
/// Console version of the game 
/// using the TicTacToe library just made
/// </summary>
/// <returns></returns>
int main()
{
    //Setup players
    Game::PlayerConfig p1
    {
       Game::Player::PLAYER_1,
       'O'


    };

    Game::PlayerConfig p2
    {
       Game::Player::PLAYER_2,
       'X'


    };
    // Init the Main Game

    Game::Game mainGame(p1,p2);
    mainGame.player1 = p1;
    mainGame.player2 = p2;

    // Main Loop

    while (mainGame.running)
    {
        switch (mainGame.currentState)
        {
        case Game::GameState::DECIDE_START_PLAYER:
            {
            mainGame.SetStartingPlayer();

            //Concat current turn player I guess
        
            break;
            }
            // On game start
        case Game::GameState::GAME_START:
        {
            //print the current board
            mainGame.PrintGameState();

            //Decide who goes first

            //Set that to the current player

            //Change Start
            mainGame.ChangeGameState(Game::GameState::DECIDE_START_PLAYER);
            break;
        }

        // Once we finish a game
        case Game::GameState::FINISH:
        {
            break;
        }

        // When it is player 1's turn
        case Game::GameState::PLAYER_1_INPUT:
        {
            // Trap in here while we give input
            while (true)
            {

            }
            mainGame.EndTurn();
            break;
        }

        // When it is player 2's turn
        case Game::GameState::PLAYER_2_INPUT:
        {


            mainGame.EndTurn();
            break;
        }

        }
    }

}

