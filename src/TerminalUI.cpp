/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "TerminalUI.h"

void TerminalUI::displayInfo(GameState state)
{
    switch (state)
    {
    case GameState::MENU:
        std::cout << "=== Main Menu ===\n"
                  << "1. Start Game\n"
                  << "2. Local Multiplayer\n"
                  << "3. Exit\n"
                  << "Enter your choice: ";
        break;
    case GameState::PREPARE_ARMY:
        break;
    case GameState::BATTLE:
        break;
    case GameState::END:
        break;
    case GameState::REPLAY:
        break;
    }
}

std::string TerminalUI::handleInput(GameState state)
{
    std::string input;
    bool validInput = false;

    while (!validInput)
    {
        std::getline(std::cin, input);

        switch (state)
        {
        case GameState::MENU:
        {
            if (input == "1" || input == "2" || input == "3")
            {
                validInput = true;
            }
            else
            {
                std::cout << "Invalid input. Please enter 1, 2, or 3: ";
            }
            break;
        }
        case GameState::PREPARE_ARMY:
        {
            break;
        }
        case GameState::BATTLE:
        {
            break;
        }
        case GameState::END:
        {
            break;
        }
        case GameState::REPLAY:
        {
            break;
        }
        }
    }
    return input;
}
