/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "GameManager.h"

GameManager::GameManager(): _state(GameState::MENU), _mode(0), _difficulty(1), _ui() {}

void GameManager::run()
{
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
    {
        _ui.displayInfo(_state);
        std::string menu_input = _ui.handleInput(_state);
        if (menu_input == "1")
        {
            _state = GameState::PREPARE_ARMY;

        }
        else if (menu_input == "2")
        {
            _state = GameState::PREPARE_ARMY;
            _mode = 1;
        }
        else if (menu_input == "3")
        {
            _state = GameState::END;
        }
        else
        {
            std::cout << "Invalid input. Please enter 1, 2, or 3: ";
        }
        break;
    }
    case GameState::PREPARE_ARMY:
    {

        if (_mode == 1)
        {
            _ui.showHeroes();
            _state = GameState::END;
        }
        else if (_mode == 0)
        {
            break;
        }

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
