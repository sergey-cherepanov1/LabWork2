/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef ARMY_H
#define ARMY_H

#include <array>
#include <memory>
#include "Hero.h"
#include "Troop.h"

class Army
{
public:
    Army();
    Army(Hero hero, std::array<std::unique_ptr<Troop>, 6> troops, int max_might);

    Hero& getHero();
    std::array<std::unique_ptr<Troop>, 6>& getTroops();
    bool getStatus();
    int getCurrentMight();
    int getMaxMight();

    void setMaxMight(int max_might);
    void setHero(Hero& hero);
    void setTroop(int position, std::unique_ptr<Troop>& troop);

private:
    Hero _hero;
    std::array<std::unique_ptr<Troop>, 6> _troops;
    int _max_might;
    int _current_might;
    bool _status;

    void updateCurrentMight();
};


#endif
