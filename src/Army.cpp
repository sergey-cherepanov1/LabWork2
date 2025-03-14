/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Army.h"

Army::Army() : _hero(), _troops{}, _max_might(5500), _current_might(0), _status(1) {}

Army::Army(Hero hero, std::array<std::shared_ptr<Troop>, 6> troops, int max_might) : _hero(hero), _troops{}, _max_might(max_might), _status(0) {}

Hero& Army::getHero()
{
    return _hero;
}

std::array<std::shared_ptr<Troop>, 6>& Army::getTroops()
{
    return _troops;
}

bool Army::getStatus()
{
    return _status;
}

int Army::getMaxMight()
{
    return _max_might;
}

int Army::getCurrentMight()
{
    updateCurrentMight();
    return _current_might;
}

void Army::setHero(Hero& hero)
{
    _hero = hero;
}

void Army::setTroop(int position, std::shared_ptr<Troop> troop)
{
    _troops[position] = troop;
}


void Army::setMaxMight(int max_might)
{
    _max_might = max_might;
}

void Army::updateCurrentMight()
{
    int hero_might = _hero.getMight();
    int troops_might = 0;
    for (auto& troop: _troops)
    {
        if (troop)
        {
            troops_might += troop->getTotalMight();
        }
    }
    _current_might = hero_might + troops_might;
}

