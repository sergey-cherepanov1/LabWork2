/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <iostream>
#include <memory>
#include "TerminalUI.h"
#include "Player.h"
#include "AI.h"
#include "BattleManager.h"

enum class GameState
{
    MENU,
    CHOOSE_DIFFICULTY,
    PREPARE_ARMY,
    BATTLE,
    END
};


class GameManager
{
public:
    GameManager();
    void run();
    void update();

private:
    GameState _state;
    bool _mode;
    std::unique_ptr<Player> _player1;
    std::unique_ptr<Player> _player2;
    int _difficulty;
    TerminalUI _ui;
    BattleManager _battle;
};


#endif
