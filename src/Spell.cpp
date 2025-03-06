/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Spell.h"

Spell::Spell() : _name("Default Spell"), _mana_cost(0), _effect(), _description("") {}

Spell::Spell(const std::string& name, int mana_cost, const Effect& effect, const std::string& description) : _name(name), _mana_cost(mana_cost), _effect(effect), _description(description) {}

std::string Spell::getName() const
{
    return _name;
}
int Spell::getManaCost() const
{
    return _mana_cost;
}
Effect Spell::getEffect() const
{
    return _effect;
}
std::string Spell::getDescription() const
{
    return _description;
}
