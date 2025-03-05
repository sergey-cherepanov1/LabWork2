/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Troop.h"

Troop::Troop(const std::string& name, int amount, int health, int attack, int max_stamina, int current_stamina,
             int initiative, int might, const std::vector<Effect>& effects, const std::string& description)
    : _name(name), _amount(amount), _health(health), _attack(attack), _max_stamina(max_stamina),
      _current_stamina(current_stamina), _initiative(initiative), _might(might), _effects(effects),
      _description(description) {}

std::string Troop::getName() const
{
    return _name;
}
int Troop::getAmount() const
{
    return _amount;
}
int Troop::getHealth() const
{
    return _health;
}
int Troop::getAttack() const
{
    return _attack;
}
int Troop::getMaxStamina() const
{
    return _max_stamina;
}
int Troop::getCurrentStamina() const
{
    return _current_stamina;
}
int Troop::getInitiative() const
{
    return _initiative;
}
int Troop::getMight() const
{
    return _might;
}
std::vector<Effect> Troop::getEffects() const
{
    return _effects;
}
std::string Troop::getDescription() const
{
    return _description;
}
