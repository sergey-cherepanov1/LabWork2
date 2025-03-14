/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Spell.h"

Spell::Spell() : _name("Default Spell"), _cost(0), _effect(), _description("") {}

Spell::Spell(std::string name, int cost, Effect effect, std::string description) : _name(name), _cost(cost), _effect(effect), _description(description) {}

std::string Spell::getName()
{
    return _name;
}
int Spell::getCost()
{
    return _cost;
}
Effect Spell::getEffect()
{
    return _effect;
}
std::string Spell::getDescription()
{
    return _description;
}
