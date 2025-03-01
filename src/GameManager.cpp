/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "GameManager.h"

GameManager::GameManager(): _state(GameState::MENU), _mode(1), _status(0), _difficulty(1) {}

void GameManager::run() 
{
    Info info;
    while (_state != GameState::END)
    {
       update();
    }
}

void GameManager::update()
{
    switch (_state)
    {
        case GameState::MENU:
            
        /*case GameState::SELECT_MODE:
        case GameState::PREPARE_ARMY:
        case GameState::BATTLE:
        case GameState::END:
        case GameState::REPLAY:*/
        
    }
}
