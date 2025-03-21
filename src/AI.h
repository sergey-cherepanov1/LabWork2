/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Catalog.h"
#include "Troop.h"
#include <array>
#include <memory>
#include <iostream>

class Action;

class AI : public Player
{
public:
    AI();
    void setupArmy(Catalog& catalog);
    void makeTurn(std::shared_ptr<Troop>& troop, std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& field, Action& action, bool& battle_status);
};

#endif
