/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef ARMY_H
#define ARMY_H

#include <array>
#include <memory>
#include "Hero.h"
#include "Troop.h"

/**
 * @class Army
 * @brief Represents a player's army, consisting of a hero and up to 6 troops.
 * 
 * Manages the composition, might, and status of the army during the game.
 */
class Army
{
public:
    /**
     * @brief Default constructor for Army.
     * 
     * Initializes an empty army with default values.
     */
    Army();

    /**
     * @brief Constructor for Army with specific parameters.
     * @param hero The hero leading the army.
     * @param troops Array of up to 6 troops in the army.
     * @param max_might Maximum might allowed for the army.
     */
    Army(Hero hero, std::array<std::shared_ptr<Troop>, 6> troops, int max_might);

    /**
     * @brief Gets the hero leading the army.
     * @return Reference to the Hero object.
     */
    Hero& getHero();

    /**
     * @brief Gets the array of troops in the army.
     * @return Reference to the array of shared pointers to Troop objects.
     */
    std::array<std::shared_ptr<Troop>, 6>& getTroops();

    /**
     * @brief Checks the status of the army.
     * @return True if the army has at least one troop remaining, false otherwise.
     */
    bool getStatus();

    /**
     * @brief Gets the current total might of the army.
     * @return Current might value, calculated from the hero and troops.
     */
    int getCurrentMight();

    /**
     * @brief Gets the maximum allowed might for the army.
     * @return Maximum might value.
     */
    int getMaxMight();

    /**
     * @brief Sets the maximum might for the army.
     * @param max_might New maximum might value.
     */
    void setMaxMight(int max_might);

    /**
     * @brief Sets the hero leading the army.
     * @param hero Reference to the Hero object to set.
     */
    void setHero(Hero& hero);

    /**
     * @brief Sets a troop at a specific position in the army.
     * @param position Index (0-5) where the troop will be placed.
     * @param troop Shared pointer to the Troop object to set.
     */
    void setTroop(int position, std::shared_ptr<Troop> troop);

private:
    Hero _hero; ///< The hero leading the army.
    std::array<std::shared_ptr<Troop>, 6> _troops; ///< Array of up to 6 troops.
    int _max_might; ///< Maximum might allowed for the army.
    int _current_might; ///< Current total might of the army.
    bool _status; ///< Status of the army (true if active, false if defeated).

    /**
     * @brief Updates the current might of the army.
     * 
     * Recalculates the total might based on the hero and remaining troops.
     */
    void updateCurrentMight();
};

#endif
