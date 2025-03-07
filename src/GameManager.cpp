/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "GameManager.h"

GameManager::GameManager(): _state(GameState::MENU), _info_state(0), _input_state(0), _mode(0), _player1(), _player2(), _difficulty(1), _ui() {}

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
        _info_state = 0; /*InfoState::MENU*/
        _input_state = 0; /*InputState::MENU*/

        _ui.displayInfo(_info_state);
        std::string menu_input = _ui.handleInput(_input_state);

        if (menu_input =="1")
        {
            _mode = 0; /*GameMode::SINGLEPLAYER*/
            _info_state = 1; /*InfoState::ENTER_NAME_SINGLEPLAYER*/
            _input_state = 1; /*InputState::GET_NAME*/

            _ui.displayInfo(_info_state);
            std::string name1 = _ui.handleInput(_input_state);

            _player1.setName(name1);

            _state = GameState::CHOOSE_DIFFICULTY;
        }
        else if (menu_input == "2")
        {
            _mode = 1; /*GameMode::MULTIPLAYER*/
            _info_state = 2; /*InfoState::ENTER_NAME_MULTIPLAYER_1*/
            _input_state = 1; /*InputState::GET_NAME*/

            _ui.displayInfo(_info_state);
            std::string name1 = _ui.handleInput(_input_state);

            _player1.setName(name1);

            _info_state = 3; /*InfoState::ENTER_NAME_MULTIPLAYER_2*/
            _ui.displayInfo(_info_state);
            std::string name2 = _ui.handleInput(_input_state);

            _player2.setName(name2);

            _state = GameState::PREPARE_ARMY;
        }
        else if (menu_input == "3")
        {
            _state = GameState::END;
        }
        break;
    }
    case GameState::CHOOSE_DIFFICULTY:
    {
        _info_state = 4; /*InfoState::CHOOSE_DIFFICULTY*/
        _input_state = 0; /*InputState::MENU(ONE_OF_THREE)*/
        _ui.displayInfo(_info_state);

        std::string difficulty = _ui.handleInput(_input_state);
        if (difficulty == "1")
        {
            _difficulty = 0; /*Difficulty::EASY*/
        }
        else if (difficulty == "2")
        {
            _difficulty = 1; /*Difficulty::NORMAL*/
        }
        else if (difficulty == "3")
        {
            _difficulty = 2; /*Difficulty::HARD*/
        }

        _state = GameState::PREPARE_ARMY;
        break;
    }
    case GameState::PREPARE_ARMY:
    {
        switch (_mode)
        {
        case 0: /*GameMode::SINGLEPLAYER*/
        {
            switch (_difficulty)
            {
            case 0: /*Difficulty::EASY*/
            {   
                
                break;
            }
            case 1: /*Difficulty::NORMAL*/
            {

                break;
            }
            case 2: /*Difficulty::HARD*/
            {

                break;
            }
            }

            break;
        }
        case 1: /*GameMode::MULTIPLAYER*/
        {
            break;
        }
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

