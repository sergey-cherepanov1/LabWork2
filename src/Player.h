/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Army.h"
#include "Catalog.h"

/**
 * @class Player
 * @brief Represents a player in the game with a name and an army.
 * 
 * Base class for human players and AI, managing player-specific data and actions.
 */
class Player
{
public:
    /**
     * @brief Default constructor for Player.
     * 
     * Initializes a player with an empty name and an empty army.
     */
    Player();

    /**
     * @brief Gets the name of the player.
     * @return String containing the player's name.
     */
    std::string getName();

    /**
     * @brief Gets the player's army.
     * @return Reference to the Army object owned by the player.
     */
    Army& getArmy();

    /**
     * @brief Sets the name of the player.
     * @param name New name to set for the player.
     */
    void setName(std::string name);

    /**
     * @brief Displays the remaining might of the player's army.
     */
    void showMightLeft();

    /**
     * @brief Virtual method to set up the player's army.
     * @param catalog Reference to the Catalog containing hero and troop templates.
     * 
     * Override this method in derived classes (e.g., AI) to define army setup behavior.
     */
    virtual void setupArmy(Catalog& catalog) {}

private:
    std::string _name; ///< Name of the player.
    Army _army; ///< Army owned by the player.
};

#endif
