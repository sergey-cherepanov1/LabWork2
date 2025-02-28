/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef GAMEMANAGER_h
#define GAMEMANAGER_h

#include "Info.h"

class GameManager()
{
public:
    GameManager();
    void run();



private:
    enum class GameState { MENU, SELECT_MODE, PREPARE_ARMY, BATTLE, END, REPLAY };
    GameState _state;
    bool _mode;
    Player _player1;
    Player _player2;
    Catalog _catalog;
    bool _status;
    int _difficulty;
    Info _info;
}


#endif
