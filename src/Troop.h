/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TROOP_H
#define TROOP_H

#include <string>
#include <vector>
#include "Effect.h"

class Troop
{
public:
    Troop();
    Troop(const std::string& name, int amount, int health, int attack, int max_stamina, int current_stamina, int initiative, int might, const std::vector<Effect>& effects, const std::string& description);

    void updateAmount();
    void updateEffects();
    
    int getTotaltHealth() const;
    int getTotaltDamage() const;    
    
    std::string getName() const;
    int getAmount() const;
    int getHealth() const;
    int getAttack() const;
    int getMaxStamina() const;
    int getCurrentStamina() const;
    int getInitiative() const;
    int getMight() const;
    std::vector<Effect> getEffects() const;
    std::string getDescription() const;

private:
    std::string _name;
    int _amount;
    int _health;
    int _attack;
    int _max_stamina;
    int _current_stamina;
    int _initiative;
    int _might;
    std::vector<Effect> _effects;
    std::string _description;
};

#endif
