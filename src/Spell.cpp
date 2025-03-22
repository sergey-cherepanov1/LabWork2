/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Spell.h"

/**
 * @brief Default constructor for Spell.
 */
Spell::Spell() : _name("Default Spell"), _cost(0), _effect(), _description("") {}

/**
 * @brief Constructor for Spell with specific parameters.
 */
Spell::Spell(std::string name, int cost, Effect effect, std::string description) : _name(name), _cost(cost), _effect(effect), _description(description) {}

/**
 * @brief Gets the name of the spell.
 */
std::string Spell::getName()
{
    return _name;
}

/**
 * @brief Gets the mana cost of the spell.
 */
int Spell::getCost()
{
    return _cost;
}

/**
 * @brief Gets the effect associated with the spell.
 */
Effect Spell::getEffect()
{
    return _effect;
}

/**
 * @brief Gets the description of the spell.
 */
std::string Spell::getDescription()
{
    return _description;
}
