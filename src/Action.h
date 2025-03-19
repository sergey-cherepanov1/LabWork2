/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef ACTION_H
#define ACTION_H

#include "Troop.h"
#include <array>
#include <memory>
#include <iostream>

class Action
{
public:
    Action(std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& field);
    void move(std::shared_ptr<Troop>& troop);
    void attack(std::shared_ptr<Troop>& troop);
    void defend(std::shared_ptr<Troop>& troop);
    void castSpell(std::shared_ptr<Troop>& troop);
    void skip(std::shared_ptr<Troop>& troop);

private:
    std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& _field;
    bool canAttackTarget(std::shared_ptr<Troop>& troop);
};
#endif
