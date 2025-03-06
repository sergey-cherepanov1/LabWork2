/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "GameManager.h"

GameManager::GameManager(): _state(GameState::MENU), _mode(GameMode::SINGLEPLAYER), _player1(), _player2(), _difficulty(1), _ui() {}

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
        _ui.displayInfo(_state, _mode);
        std::string menu_input = _ui.handleInput(_state, _mode);
        if (menu_input == "1")
        {
            _mode = GameMode::SINGLEPLAYER;
            std::cout << "=== Enter Player Name ===\n"
            << "Enter name for Player (max 20 characters, must not be empty): ";
            std::string name = getPlayerName();
            _player1.setName(name);
            _state = GameState::END;
        
        }
        else if (menu_input == "2")
        {
            _mode = GameMode::MULTIPLAYER;
            std::cout << "=== Enter Player Names ===\n"
            << "Enter name for Player 1 (max 20 characters, must not be empty): ";
            std::string name1 = getPlayerName();
            _player1.setName(name1);
            std::cout << "Enter name for Player 2 (max 20 characters, must not be empty): ";
            std::string name2 = getPlayerName();
            _player2.setName(name2);
            _state = GameState::PREPARE_ARMY;
        }
        else if (menu_input == "3")
        {
            _state = GameState::END;
        }
        break;
    }
    case GameState::PREPARE_ARMY:
    {
        if (_mode == GameMode::SINGLEPLAYER)
        {
            
            _state = GameState::END;
            break;
        }
        else if (_mode == GameMode::MULTIPLAYER)
        {
            _ui.displayInfo(_state, _mode);
            _ui.handleInput();
            _state = GameState::END;
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

std::string GameManager::getPlayerName()
{
    std::string name;
    bool validInput = false;

    while (!validInput)
    {
        std::getline(std::cin, name);

        if (name.empty())
        {
            std::cout << "Name cannot be empty. Please enter a valid name: ";
            continue;
        }

        if (name.length() > 20)
        {
            std::cout << "Name is too long (max 20 characters). Please enter a shorter name: ";
            continue;
        }

        validInput = true;
    }
    return name;
}
