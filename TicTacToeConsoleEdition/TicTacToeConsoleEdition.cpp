// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../TicTacToeGameFiles/PlayerConfig.h"
#include "../TicTacToeGameFiles/GameState.h"
#include "../TicTacToeGameFiles/Game.h"
#include <algorithm>

/// <summary>
/// Console version of the game 
/// using the TicTacToe library just made.
/// 
/// If for whatever reasons errors occur, then make sure to 
/// set TicTacToeGame type to Static Library
/// </summary>
/// <returns></returns>
/// 



static void  PlayerInputPrompt(Game& mainGame)
{
    // Print game state before we make a move

    mainGame.PrintGameState();

    //User Input
    mainGame.PrintLine("");
    mainGame.PrintAllFreeSpots();
    if (!mainGame.GetCurrentPlayer().isAI)
    {


        std::vector<BoardSlot> allFreeSlots = mainGame.GetAllFreeSlots();
        mainGame.PrintLine("Each slot is printed as {ROW,COLUMN}");
        unsigned int choice = mainGame.UserInputPromptInt("Please enter a number correlating to the grid : ");

        //Dont let us continue
        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            choice = mainGame.UserInputPromptInt("Please enter a number correlating to the grid : ");
        }
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
    }

}

static void HelpPrompt()
{
    std::cout << "======== COORDINATES ========" << std::endl;
    std::cout << "{0,0} TOP LEFT " << std::endl;
    std::cout << "{0,1} TOP CENTER " << std::endl;
    std::cout << "{0,2} TOP RIGHT " << std::endl;

    std::cout << "{1,0} MIDDLE LEFT " << std::endl;
    std::cout << "{1,1} MIDDLE CENTER " << std::endl;
    std::cout << "{1,2} MIDDLE RIGHT " << std::endl;

    std::cout << "{2,0} BOTTOM LEFT " << std::endl;
    std::cout << "{2,1} BOTTOM CENTER " << std::endl;
    std::cout << "{2,2} BOTTOM RIGHT " << std::endl;






}

int main()
{
    //Setup players
   PlayerConfig p1
    {
       Player::PLAYER_1,
       'o',
       false


    };

    PlayerConfig p2
    {
       Player::PLAYER_2,
       'x',
       false


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
            std::string userInput = mainGame.UserInputPromptString("Play again? : ");

            // Make it so the user cant accidentally put in something uppercased
            std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
            if (userInput == "y" || userInput == "yes")
            {
                //Reset
                mainGame.ChangeGameState(GameState::GAME_START);
                mainGame.ResetGame();
            }
            else
            {
                mainGame.PrintLine("Bye bye!");
                mainGame.running = false;
            }
        }

        // When it is player 1's turn
        case GameState::PLAYER_1_INPUT:
        {
            HelpPrompt();

            mainGame.AIAction();
            PlayerInputPrompt(mainGame);
            break;

         
            
        }

        // When it is player 2's turn
        case GameState::PLAYER_2_INPUT:
        {
            HelpPrompt();

            mainGame.AIAction();
            PlayerInputPrompt(mainGame);


            
            break;
        }

        }
    }


    
   
}




