/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Hero.h"

Hero::Hero(const std::string& name, int might, int mana, const std::vector<Spell>& spells, const std::string& description)
    : _name(name), _might(might), _mana(mana), _spells(spells), _description(description) {}

std::string Hero::getName() const
{
    return _name;
}
int Hero::getMight() const
{
    return _might;
}
int Hero::getMana() const
{
    return _mana;
}
std::vector<Spell> Hero::getSpells() const
{
    return _spells;
}
std::string Hero::getDescription() const
{
    return _description;
}
