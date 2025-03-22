/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "GameManager.h"

/**
 * @brief Default constructor for GameManager.
 */
GameManager::GameManager(): _state(GameState::MENU), _mode(0), _difficulty(1), _ui(), _battle(), _status(true) {}

/**
 * @brief Runs the main game loop.
 */
void GameManager::run()
{
    while (_status)
    {
        update();
    }
}

/**
 * @brief Updates the game state based on the current state.
 */
void GameManager::update()
{
    switch (_state)
    {
    case GameState::MENU:
    {
        _ui.displayInfo(InfoState::MENU);
        std::string menu_input = _ui.handleInput(InputState::ONE_OF_THREE);

        if (menu_input =="1")
        {
            _mode = 0; /*GameMode::SINGLEPLAYER*/

            _ui.displayInfo(InfoState::ENTER_NAME_SINGLEPLAYER);
            std::string name1 = _ui.handleInput(InputState::GET_NAME);

            _battle.getPlayer1().setName(name1);
            _battle.getAI().setupArmy(_ui.getCatalog());

            _state = GameState::CHOOSE_DIFFICULTY;
        }
        else if (menu_input == "2")
        {
            _state = GameState::END;
            _mode = 1; /*GameMode::MULTIPLAYER*/
            break;
            _battle.setMode();

            _ui.displayInfo(InfoState::ENTER_NAME_MULTIPLAYER_1);
            std::string name1 = _ui.handleInput(InputState::GET_NAME);

            _battle.getPlayer1().setName(name1);

            _ui.displayInfo(InfoState::ENTER_NAME_MULTIPLAYER_2);
            std::string name2 = _ui.handleInput(InputState::GET_NAME);

            _battle.getPlayer2().setName(name2);

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
        _ui.displayInfo(InfoState::CHOOSE_DIFFICULTY);

        std::string difficulty = _ui.handleInput(InputState::ONE_OF_THREE);
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
                _battle.getPlayer1().getArmy().setMaxMight(5500);
                break;
            }
            case 1: /*Difficulty::NORMAL*/
            {
                _battle.getPlayer1().getArmy().setMaxMight(2500);
                break;
            }
            case 2: /*Difficulty::HARD*/
            {
                _battle.getPlayer1().getArmy().setMaxMight(1000);
                break;
            }
            }


            _ui.displayInfo(InfoState::HEROES);
            int hero_index = std::stoi(_ui.handleInput(InputState::ONE_OF_THREE)) - 1;
            _battle.getPlayer1().getArmy().setHero(_ui.getCatalog().getHeroTemplates()[hero_index]);
            _battle.getPlayer1().showMightLeft();

            _ui.displayInfo(InfoState::TROOPS);
            for (int position = 0; position < 6; ++position)
            {
                int current_might = _battle.getPlayer1().getArmy().getCurrentMight();
                int max_might = _battle.getPlayer1().getArmy().getMaxMight();
                int remaining_might = max_might - current_might;

                std::cout << "\nSelecting troop for position " << (position + 1) << " (Top to Bottom):\n";
                std::cout << "Enter the chosen troop number (1-15): ";

                bool should_end = false;
                std::shared_ptr<Troop> selected_troop = _ui.selectTroop(remaining_might, should_end);

                if (should_end)
                {
                    break;
                }

                _battle.getPlayer1().getArmy().setTroop(position, selected_troop);
                _battle.getPlayer1().showMightLeft();
            }
            _ui.showArmy(_battle.getPlayer1());
            _state = GameState::BATTLE;
            break;
        }
        case 1: /*GameMode::MULTIPLAYER*/
        {
            break;
        }

        break;
        }
    }
    case GameState::BATTLE:
    {
        _battle.run();
        _state = GameState::END;
        break;
    }
    case GameState::END:
    {
        if (_mode)
        {
            std::cout << "\n=== Game Over ===\n";
            std::cout << "Multiplayer mode is not yet implemented. Game terminated.\n";
            std::cout << "====================\n";
        }
        else
        {
            std::cout << "\n=== Battle Ended ===\n";
            Player& player1 = _battle.getPlayer1();
            Player& ai = _battle.getAI();

            if (player1.getArmy().getStatus() && !ai.getArmy().getStatus())
            {
                std::cout << player1.getName() << " has won the battle!\n";
            }
            else if (!player1.getArmy().getStatus() && ai.getArmy().getStatus())
            {
                std::cout << ai.getName() << " has won the battle!\n";
            }

            std::cout << "====================\n";
        }
        _status = false;
        break;
    }
    }
}

GameState GameManager::getState()
{
    return _state;
}

bool GameManager::getStatus()
{
    return _status;
}

void GameManager::setState(GameState state)
{
    _state = state;
}

int GameManager::getDifficulty()
{
    return _difficulty;
}

void GameManager::setDifficulty(int difficulty)
{
    _difficulty = difficulty;
}

bool GameManager::getMode()
{
    return _mode;
}

void GameManager::setMode(bool mode)
{
    _mode = mode;
}

BattleManager& GameManager::getBattle()
{
    return _battle;
}
