// PlayerDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Database.h"
#include <thread>

int main()
{
    bool running = true;
    std::cout << "**************************" << std::endl;
    std::cout << "**** Player Database ****" << std::endl;
    std::cout << "**************************" << std::endl;


    Database db(16);

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
        std::cout << "clear - Clear all Player Profiles from the database." << std::endl;
        std::cout << "modify - Modify an existing Player Profile " << std::endl;
        std::cout << "save - Save all Player Profiles to a file. " << std::endl;
        std::cout << "load - Load all Player Profiles from a file. " << std::endl;
        std::cout << "view - View all Player Profiles" << std::endl;
        std::cout << "binary-s - Binary search for a player with a specified score" << std::endl;
        std::cout << "bsort - Bubble Sorts the Player Profiles" << std::endl;

        std::cin >> choice;

        //if statements dependent on user choice

        // Add a profile
        if (choice == "add")
        {
            db.state = DatabaseState::CREATE_PROFILE;

        }

        else if (choice == "bsort")
        {
            std::string comparison;
            std::string type;
            char comp = '>';

            //keep user in here if the user doesnt give asc or desc
            while (comparison != "asc" && comparison != "desc")
            {


                std::cout << "Please enter how you want to sort this player profiles (asc or desc)" << std::endl;
                std::cin >> comparison;
            }
                std::cout << "Sort by highscore or name?" << std::endl;
                std::cin >> type;
            
            //convert comparison
            if (comparison == "asc")
            {
                comp = '<';
            }
            else
            {
                comp = '>';
            }

       
            //highscore sort
            if (type == "highscore")
            {
                db.BubbleSortPlayersByScore(db.loadedPlayers, comp);
            }
            //name sort
            else if (type == "name")
            {
                db.BubbleSortPlayersByName(db.loadedPlayers, comp);

           
            }
            else
            {
                std::cout << "Incorrect sort type given" << std::endl;
            }


            db.state = DatabaseState::USER_INPUT;
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

        else if (choice == "clear")
        {
            db.state = DatabaseState::REMOVE_PROFILES;
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

        //TODO: Make sure it is a number
        std::cout << "Player Score: ";
        std::cin >> highScore;

        // Then add them to the database
        db.AddPlayer(playerName, highScore);



        db.state = DatabaseState::USER_INPUT;
        break;
    }

    case(DatabaseState::MODIFY_PROFILE):
    {
        system("CLS");
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
        system("CLS");
        unsigned int element = 0;
        std::string targ;
        std::cout << "What is the name of the person your are looking for?\n" << std::endl;
        std::cin >> targ;
        if (db.BinarySearchPlayer(targ, element))
        {
            std::cout << "Found Player sucessfully!\n" << std::endl;

            db.loadedPlayers[element].PrintInformation();
        }
        else
        {
            std::cout << "Could not find player with the given name" << std::endl;
        }

        db.state = DatabaseState::USER_INPUT;

        break;
    }

    case(DatabaseState::SAVE_PROFILES):
    {
        db.WriteFile(db.FILE_NAME);

        std::cout << "Saved Sucessfully..." << std::endl;
        db.state = DatabaseState::USER_INPUT;
        break;
    }

    case(DatabaseState::LOAD_PROFILES):
    {
        db.ReadFile(db.FILE_NAME);
        db.state = DatabaseState::USER_INPUT;
        break;
    }
    case(DatabaseState::REMOVE_PROFILES):
    {
        std::string usrInp;
        db.PrintAllPlayers();
        std::cout << "Are you sure you wish to clear all the player profiles?\ny = yes | n = no" << std::endl;
        std::cin >> usrInp;


        if (usrInp == "y" || usrInp == "yes")
        {
            // This logic should probably be in the Database class but low on time so just leave it here for now


            //Flush the cmd
            system("CLS");
            std::cout << "Clearing all players..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));

            //"Clear Players"

            // this works for now
            db.loadedPlayerCount = 0;


            //Save File
            db.WriteFile(db.FILE_NAME);
        }
    


        db.state = DatabaseState::USER_INPUT;

        break;
    }
    case (DatabaseState::SHOW_ALL_PROFILES):
    {
        system("CLS");
        db.PrintAllPlayers();
        db.state = DatabaseState::USER_INPUT;
        break;
    }

    }
    }
    
}


