/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "Effect.h"

/**
 * @class Spell
 * @brief Represents a magical spell that can be cast by a hero.
 * 
 * Stores the spell's name, mana cost, associated effect, and description.
 */
class Spell
{
public:
    /**
     * @brief Default constructor for Spell.
     * 
     * Initializes a spell with default values.
     */
    Spell();

    /**
     * @brief Constructor for Spell with specific parameters.
     * @param name Name of the spell.
     * @param cost Mana cost to cast the spell.
     * @param effect Effect applied by the spell.
     * @param description Description of the spell's effect.
     */
    Spell(std::string name, int cost, Effect effect, std::string description);

    /**
     * @brief Gets the name of the spell.
     * @return String containing the spell's name.
     */
    std::string getName();

    /**
     * @brief Gets the mana cost of the spell.
     * @return Integer representing the mana cost.
     */
    int getCost();

    /**
     * @brief Gets the effect associated with the spell.
     * @return Effect object representing the spell's effect.
     */
    Effect getEffect();

    /**
     * @brief Gets the description of the spell.
     * @return String containing the spell's description.
     */
    std::string getDescription();

private:
    std::string _name; ///< Name of the spell.
    int _cost; ///< Mana cost to cast the spell.
    Effect _effect; ///< Effect applied by the spell.
    std::string _description; ///< Description of the spell.
};

#endif
