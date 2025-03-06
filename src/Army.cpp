/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Army.h"

Army::Army() : _hero(), _troops() {}

Army::Army(const Hero& hero, const std::array<Troop, 6>& troops) : _hero(hero), _troops(troops) {}

const Hero& Army::getHero() const
{
    return _hero;
}
const std::array<Troop, 6>& Army::getTroops() const
{
    return _troops;
}
