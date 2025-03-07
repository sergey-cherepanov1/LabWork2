/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Army.h"

Army::Army() : _hero(), _troops(), _status(0) {}

Army::Army(Hero hero, std::array<Troop, 6> troops) : _hero(hero), _troops(troops), _status(0) {}

const Hero& Army::getHero() const
{
    return _hero;
}
const std::array<Troop, 6>& Army::getTroops() const
{
    return _troops;
}

bool Army::getStatus() const
{
    return _status;
}
