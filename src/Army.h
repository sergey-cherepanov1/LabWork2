/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef ARMY_H
#define ARMY_H

#include <array>
#include "Hero.h"
#include "Troop.h"

class Army
{
public:
    Army();
    Army(Hero hero, std::array<Troop, 6> troops);
    const Hero& getHero() const;
    const std::array<Troop, 6>& getTroops() const;
    bool getStatus() const;

private:
    Hero _hero;
    std::array<Troop, 6> _troops;
    bool _status;
};


#endif
