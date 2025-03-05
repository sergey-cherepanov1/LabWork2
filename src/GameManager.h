/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include "TerminalUI.h"

class GameManager
{
public:
    GameManager();
    void run();
    void update();



private:
    GameState _state;
    bool _mode;
    /*Player _player1;
    Player _player2;*/
    int _difficulty;
    TerminalUI _ui;
};


#endif
