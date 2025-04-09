/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef HERO_H
#define HERO_H

#include <string>
#include <array>
#include "Spell.h"

/**
 * @class Hero
 * @brief Represents a hero leading an army with unique abilities and spells.
 *
 * Stores the hero's name, might, mana, spells, and description.
 */
class Hero
{
public:
    /**
     * @brief Default constructor for Hero.
     *
     * Initializes a hero with default values.
     */
    Hero();

    /**
     * @brief Constructor for Hero with specific parameters.
     * @param name Name of the hero.
     * @param might Might value of the hero.
     * @param mana Mana points of the hero.
     * @param spells Array of 3 spells available to the hero.
     * @param description Description of the hero's background or abilities.
     */
    Hero(std::string name, int might, int mana, std::array<Spell, 3> spells, std::string description);

    /**
     * @brief Gets the name of the hero.
     * @return String containing the hero's name.
     */
    std::string getName();

    /**
     * @brief Gets the might value of the hero.
     * @return Integer representing the hero's might.
     */
    int getMight();

    /**
     * @brief Gets the current mana points of the hero.
     * @return Integer representing the hero's mana.
     */
    int getMana();

    /**
     * @brief Gets the array of spells available to the hero.
     * @return Reference to an array of 3 Spell objects.
     */
    std::array<Spell, 3>& getSpells();

    /**
     * @brief Gets the description of the hero.
     * @return String containing the hero's description.
     */
    std::string getDescription();

    /**
     * @brief Sets the mana points of the hero.
     * @param mana New mana value to set.
     */
    void setMana(int mana);

private:
    std::string _name; ///< Name of the hero.
    int _might; ///< Might value of the hero.
    int _mana; ///< Current mana points of the hero.
    std::array<Spell, 3> _spells; ///< Array of 3 spells the hero can cast.
    std::string _description; ///< Description of the hero.
};

#endif
