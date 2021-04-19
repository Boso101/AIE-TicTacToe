// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

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

    Game::Game mainGame;
    mainGame.player1 = p1;
    mainGame.player2 = p2;

    // Main Loop

    while (mainGame.running)
    {
        switch (mainGame.currentState)
        {
            // On game start
        case Game::GameState::GAME_START:
        {
            //print the current board
            mainGame.PrintGameState();

            //Decide who goes first

            //Set that to the current player
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
            break;
        }

        // When it is player 2's turn
        case Game::GameState::PLAYER_2_INPUT:
        {
            break;
        }
      
        }
    }

}

