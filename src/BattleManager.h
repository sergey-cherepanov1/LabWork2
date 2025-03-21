/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include <iomanip>
#include <array>
#include <vector>
#include <memory>
#include <algorithm>
#include "Hero.h"
#include "Spell.h"
#include "Troop.h"
#include "Player.h"
#include "AI.h"
#include "Action.h"

class BattleManager
{
public:
    BattleManager();

    void run();
    void setMode();

    Player& getPlayer1();
    Player& getPlayer2();
    AI& getAI();
private:
    Player _player1;
    Player _player2;
    AI _ai;
    std::array<std::array<std::shared_ptr<Troop>,6>, 6> _field;
    std::vector<std::shared_ptr<Troop>> _queue;
    Action _action;
    bool _battle_status;
    bool _mode;

    void printCenteredLine(std::string str);
    void fillTheField();
    void displayField();
    void makeQueue();
    void turn();
    void updateEffects();
};


#endif
