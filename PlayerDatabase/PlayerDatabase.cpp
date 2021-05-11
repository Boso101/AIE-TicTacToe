// PlayerDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Database.h"

int main()
{
    bool running = true;
    std::cout << "**************************" << std::endl;
    std::cout << "**** Player Database ****" << std::endl;
    std::cout << "**************************" << std::endl;


    Database db(4);

    while (running)
    {

    
    switch (db.state)
    {
    case(DatabaseState::USER_INPUT):
    {
        std::string choice;
        std::cout << "Please decide on an action with the following commands.\n" << std::endl;
        std::cout << "== Commands == " << std::endl;
        std::cout << "add - Create a new Player Profile " << std::endl;
        std::cout << "remove - Remove a Player Profile" << std::endl;
        std::cout << "modify - Modify an existing Player Profile " << std::endl;
        std::cout << "save - Save all Player Profiles to a file. " << std::endl;
        std::cout << "load - Load all Player Profiles from a file. " << std::endl;
        std::cout << "view - View all Player Profiles" << std::endl;
        std::cout << "binary-s - Binary search for a player with a specified score" << std::endl;

        std::cin >> choice;

        //if statements dependent on user choice

        // Add a profile
        if (choice == "add")
        {
            db.state = DatabaseState::CREATE_PROFILE;

        }

        // Save all the profiles
        else if (choice == "save")
        {
            db.state = DatabaseState::SAVE_PROFILES;
        }


        // view all profiles 

        else if (choice == "view")
        {
            db.state = DatabaseState::SHOW_ALL_PROFILES;

        }

        // For modifying a profile
        else if (choice == "modify")
        {

            db.state = DatabaseState::MODIFY_PROFILE;


        }

        else if (choice == "binary-s")
        {
            db.state = DatabaseState::SEARCH_PROFILE;
        }

        else if (choice == "remove")
        {
            db.state = DatabaseState::REMOVE_PROFILE;
        }

        else if (choice == "load")
        {
            db.state = DatabaseState::LOAD_PROFILES;
        }

            break;
    }

    case(DatabaseState::CREATE_PROFILE):
    {
        std::string playerName;
        unsigned int highScore = 0;

        // Prompt user to input name
        std::cout << "Player Name: ";
        std::cin >> playerName;

        // Then prompt user to input highscore
        std::cout << "Player Score: ";
        std::cin >> highScore;

        // Then add them to the database
        db.AddPlayer(playerName, highScore);



        db.state = DatabaseState::USER_INPUT;
        break;
    }

    case(DatabaseState::MODIFY_PROFILE):
    {
        unsigned int element;

        db.PrintAllPlayers();
        std::cout << "Please enter player element to modify." << std::endl;

        std::cin >> element;
        Player& currentP = db.loadedPlayers[element];

        // A way to check if the player has been initialized
        if (element <= db.loadedPlayerCount)
        {
            //Begin modifiying
            // Special case for when both are 0
            if (element == 0 && db.loadedPlayerCount == 0)
            {


                std::cout << "Empty list of player profiles." << std::endl;
                db.state = DatabaseState::USER_INPUT;
                break;
            }
            db.ModifyPlayerPrompt(currentP);

        }
        else
        {
            // Not valid
            std::cout << "Not a valid element." << std::endl;
        }

        db.state = DatabaseState::USER_INPUT;

        break;
    }

    case(DatabaseState::SEARCH_PROFILE):
    {
        unsigned int scr;
        std::cout << "What highscore value are you searching for?\n" << std::endl;
        std::cin >> scr;
        db.BinarySearchPlayer(scr);

        db.state = DatabaseState::USER_INPUT;

        break;
    }

    case(DatabaseState::SAVE_PROFILES):
    {
        db.WriteFile("PlayerList.bin");

        std::cout << "Saved Sucessfully..." << std::endl;
        db.state = DatabaseState::USER_INPUT;
        break;
    }

    case(DatabaseState::LOAD_PROFILES):
    {
        db.ReadFile("PlayerList.bin");
        db.state = DatabaseState::USER_INPUT;
        break;
    }
    case(DatabaseState::REMOVE_PROFILE):
    {
        unsigned int scr;
        db.PrintAllPlayers();
        std::cout << "Please input the element for the player you wish to remove.\n" << std::endl;
        std::cin >> scr;

        //Deletus 
        if (scr <= db.loadedPlayerCount)
        {
           // db.loadedPlayers[scr] = *nullptr;

        }
        else
        {
            std::cout << "The given element does not exist in the loaded player list..." << std::endl;

        }


        db.state = DatabaseState::USER_INPUT;

        break;
    }
    case (DatabaseState::SHOW_ALL_PROFILES):
    {
        db.PrintAllPlayers();
        db.state = DatabaseState::USER_INPUT;
        break;
    }

    }
    }
    
}


