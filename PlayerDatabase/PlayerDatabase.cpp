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
        std::cout << "modify <playername> - Modify an existing player " << std::endl;
        std::cout << "save - Save all Players to file. " << std::endl;
        std::cout << "view - View all players" << std::endl;

        std::cin >> choice;

        //if statements dependent on user choice

        // Add a profile
        if (choice == "add")
        {

        }

        // Save all the profiles
        else if (choice == "save")
        {

        }


        // view all profiles in alphabetical order

        else if (choice == "view")
        {
            for (int i = 0; i < db.playerInUse; i++)
            {
                db.loadedPlayers[i].PrintInformation();
            }
        }

        // For modifying a profile
        else if (choice == "TODO")
        {

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
        break;
    }

    case(DatabaseState::SEARCH_PROFILE):
    {
        
        break;
    }

    case(DatabaseState::SAVE_PROFILES):
    {
        break;
    }

    case(DatabaseState::LOAD_PROFILES):
    {
        db.ReadFile("PlayerList.bin");
        db.state = DatabaseState::USER_INPUT;
        break;
    }

    }
    }
    
}


