// PlayerDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Database.h"

int main()
{
    bool running = true;
    std::cout << "**** Player Database ****" << std::endl;

    Database db;
    while (running)
    {

    
    switch (db.state)
    {
    case(DatabaseState::USER_INPUT):
        {
            break;
        }

    case(DatabaseState::CREATE_PROFILE):
    {
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

    }
    }
    
}


