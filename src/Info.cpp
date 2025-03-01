/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Info.h"

void Info::displayInfo(GameState state) {
    switch (state) {
        case GameState::MENU:
            std::cout << "=== Main Menu ===\n"
                      << "1. Start Game\n"
                      << "2. Local Multiplayer\n"
                      << "3. Exit\n"
                      << "Enter your choice: ";
            break;
        /*case GameState::SELECT_MODE:
        case GameState::PREPARE_ARMY:
        case GameState::BATTLE:
        case GameState::END:
        case GameState::REPLAY:*/
        default:
            std::cout << "Unknown game state. Please check the game logic.\n";
            break;
    }
}
