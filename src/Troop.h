/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TROOP_H
#define TROOP_H

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include "Effect.h"

class Troop
{
public:
    Troop();
    Troop(std::string name, int amount, int health, int attack, int max_stamina, int initiative, int might, std::vector<Effect> effects, std::string description);

    void update();
    void updateEffects();
    void setAmount(int amount);
    void setPosition(int x, int y);
    void setHasAttacked(bool attacked);
    void setCurrentStamina(int stamina);
    void setOwner();
    void setHasCasted(bool casted);

    std::string getName();
    int getAmount();
    int getHealth();
    int getAttack();
    int getMaxStamina();
    int getCurrentStamina();
    int getInitiative();
    int getMight();
    std::vector<Effect>& getEffects();
    std::string getDescription();
    int getX();
    int getY();
    bool getOwner();
    bool hasAttacked();
    bool hasCasted();

    int getTotalHealth();
    int getTotalAttack();
    int getTotalMight();

    void attack(std::shared_ptr<Troop>& target);
    void applyEffects();
    void addEffect(Effect& effect);
    void resetEffect(Effect& effect);

private:
    std::string _name;
    int _amount;
    int _health;
    int _total_health;
    int _attack;
    int _base_attack;
    int _max_stamina;
    int _current_stamina;
    int _initiative;
    int _might;
    int _total_might;
    std::vector<Effect> _effects;
    std::string _description;
    int _x;
    int _y;
    bool _hasAttacked;
    bool _hasCasted;
    bool _owner;
};

#endif
