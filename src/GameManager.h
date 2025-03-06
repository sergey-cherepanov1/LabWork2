/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include "TerminalUI.h"
#include "GameState.h"
#include "GameMode.h"
#include "Player.h"

class GameManager
{
public:
    GameManager();
    void run();
    void update();

private:
    GameState _state;
    GameMode _mode;
    Player _player1;
    Player _player2;
    int _difficulty;
    TerminalUI _ui;
    
    std::string getPlayerName();
};


#endif
