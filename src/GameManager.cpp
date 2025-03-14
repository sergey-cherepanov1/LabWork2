/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "GameManager.h"

GameManager::GameManager(): _state(GameState::MENU), _mode(0), _difficulty(1), _ui(), _battle() {}

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
        _ui.displayInfo(InfoState::MENU);
        std::string menu_input = _ui.handleInput(InputState::ONE_OF_THREE);

        if (menu_input =="1")
        {
            _mode = 0; /*GameMode::SINGLEPLAYER*/

            _ui.displayInfo(InfoState::ENTER_NAME_SINGLEPLAYER);
            std::string name1 = _ui.handleInput(InputState::GET_NAME);

            _battle.getPlayer1()->setName(name1);

            _state = GameState::CHOOSE_DIFFICULTY;
        }
        else if (menu_input == "2")
        {
            _mode = 1; /*GameMode::MULTIPLAYER*/

            _ui.displayInfo(InfoState::ENTER_NAME_MULTIPLAYER_1);
            std::string name1 = _ui.handleInput(InputState::GET_NAME);

            _battle.getPlayer1()->setName(name1);

            _ui.displayInfo(InfoState::ENTER_NAME_MULTIPLAYER_2);
            std::string name2 = _ui.handleInput(InputState::GET_NAME);

            _battle.getPlayer2() = std::make_unique<Player>(name2, Army());
            _battle.getPlayer2()->setName(name2);

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
                _battle.getPlayer1()->getArmy().setMaxMight(5500);
                break;
            }
            case 1: /*Difficulty::NORMAL*/
            {
                _battle.getPlayer1()->getArmy().setMaxMight(2500);
                break;
            }
            case 2: /*Difficulty::HARD*/
            {
                _battle.getPlayer1()->getArmy().setMaxMight(1000);
                break;
            }
            }


            _ui.displayInfo(InfoState::HEROES);
            int hero_index = std::stoi(_ui.handleInput(InputState::ONE_OF_THREE)) - 1;
            _battle.getPlayer1()->getArmy().setHero(_ui.getCatalog().getHeroTemplates()[hero_index]);
            _battle.getPlayer1()->showMightLeft();

            for (int position = 0; position < 6; ++position)
            {
                int current_might = _battle.getPlayer1()->getArmy().getCurrentMight();
                int max_might = _battle.getPlayer1()->getArmy().getMaxMight();
                int remaining_might = max_might - current_might;

                bool should_end = false;
                std::shared_ptr<Troop> selected_troop = _ui.selectTroop(remaining_might, should_end);

                if (should_end)
                {
                    break;
                }

                _battle.getPlayer1()->getArmy().setTroop(position, selected_troop);
                _battle.getPlayer1()->showMightLeft();
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
        switch (_mode)
        {
        case 0:
        {

            _battle.run();
            break;
        }
        case 1:
        {
            _battle.run();
            break;
        }
        }

        _state = GameState::END;
        break;
    }
    case GameState::END:
    {

        break;
    }
    }
}

