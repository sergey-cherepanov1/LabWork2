/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef GAMEMANAGER_h
#define GAMEMANAGER_h

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
    Player _player2;
    Catalog _catalog;*/
    int _difficulty;
    TerminalUI _ui;
};


#endif
