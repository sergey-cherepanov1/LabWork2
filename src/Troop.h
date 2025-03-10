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
    Troop(std::string name, int amount, int health, int attack, int max_stamina, int current_stamina, int initiative, int might, std::vector<Effect> effects, std::string description);

    void update();
    void updateEffects();
    void setAmount(int amount);

    int getTotaltHealth();
    int getTotaltDamage();

    std::string getName();
    int getAmount();
    int getHealth();
    int getAttack();
    int getMaxStamina();
    int getCurrentStamina();
    int getInitiative();
    int getMight();
    std::vector<Effect> getEffects();
    std::string getDescription();
    
    int getTotalHealth();
    int getTotalAttack();
    int getTotalMight();

private:
    std::string _name;
    int _amount;
    int _health;
    int _total_health;
    int _attack;
    int _total_attck;
    int _max_stamina;
    int _current_stamina;
    int _initiative;
    int _might;
    int _total_might;
    std::vector<Effect> _effects;
    std::string _description;
};

#endif
