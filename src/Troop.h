/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TROOP_h
#define TROOP_h

#include <string>
#include "Effect.h"

class Troop
{
public:
    Troop(std::string name, int amount = 1, int health, int max_stamina, int current_stamina, int iniative);

    int getTotaltHealth();
    void updateAmount();
    void updateEffects();

private:
    std::string _name;
    int _amount;
    int _health;
    int _attack;
    int _max_stamina;
    int _current_stamina;
    int _initiative;
    int _might;
    std::vector<Effect> effects_;
    std::string _description;
}

#endif
