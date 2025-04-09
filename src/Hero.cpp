/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Hero.h"

/**
 * @brief Default constructor for Hero.
 */
Hero::Hero() : _name("Default Hero"), _might(0), _mana(0), _spells(), _description("") {}

/**
 * @brief Constructor for Hero with specific parameters.
 */
Hero::Hero(std::string name, int might, int mana, std::array<Spell, 3> spells, std::string description)
    : _name(name), _might(might), _mana(mana), _spells(spells), _description(description) {}

/**
 * @brief Gets the name of the hero.
 */
std::string Hero::getName()
{
    return _name;
}

/**
 * @brief Gets the might value of the hero.
 */
int Hero::getMight()
{
    return _might;
}

/**
 * @brief Gets the current mana points of the hero.
 */
int Hero::getMana()
{
    return _mana;
}

/**
 * @brief Gets the array of spells available to the hero.
 */
std::array<Spell, 3>& Hero::getSpells()
{
    return _spells;
}

/**
 * @brief Gets the description of the hero.
 */
std::string Hero::getDescription()
{
    return _description;
}

/**
 * @brief Sets the mana points of the hero.
 */
void Hero::setMana(int mana)
{
    _mana = mana;
}
