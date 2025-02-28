/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef GAMEMANAGER_h
#define GAMEMANAGER_h

#include "GameState.h"
#include "Info.h"

class GameManager()
{
public:
    GameManager();
    void start();



private:
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
