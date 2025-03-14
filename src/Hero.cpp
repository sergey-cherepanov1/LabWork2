/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Hero.h"

Hero::Hero() : _name("Default Hero"), _might(0), _mana(0), _spells(), _description("") {}

Hero::Hero(std::string name, int might, int mana, std::array<Spell, 3> spells, std::string description)
    : _name(name), _might(might), _mana(mana), _spells(spells), _description(description) {}

std::string Hero::getName()
{
    return _name;
}
int Hero::getMight()
{
    return _might;
}
int Hero::getMana()
{
    return _mana;
}
std::array<Spell, 3>& Hero::getSpells()
{
    return _spells;
}
std::string Hero::getDescription()
{
    return _description;
}
