/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef ACTION_H
#define ACTION_H

#include "Troop.h"
#include "Player.h"
#include <array>
#include <memory>
#include <iostream>

class Action
{
public:
    Action(std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& field, Player* player1, Player* player2);
    int move(std::shared_ptr<Troop>& troop);
    int attack(std::shared_ptr<Troop>& troop);
    int castSpell(std::shared_ptr<Troop>& troop);
    void skip(std::shared_ptr<Troop>& troop);

    bool canAttackTarget(std::shared_ptr<Troop>& troop);

private:
    std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& _field;
    Player* _player1;
    Player* _player2;
};
#endif
