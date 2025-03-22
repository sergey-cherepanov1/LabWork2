/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Catalog.h"
#include "Troop.h"
#include <array>
#include <memory>
#include <iostream>

class Action; // Forward declaration

/**
 * @class AI
 * @brief Represents an artificial intelligence opponent inheriting from Player.
 * 
 * Manages the AI's army setup and turn-based actions during the battle.
 */
class AI : public Player
{
public:
    /**
     * @brief Default constructor for AI.
     * 
     * Initializes the AI with a default name and inherits Player properties.
     */
    AI();

    /**
     * @brief Sets up the AI's army using predefined templates.
     * @param catalog Reference to the Catalog containing hero and troop templates.
     */
    void setupArmy(Catalog& catalog);

    /**
     * @brief Executes the AI's turn for a specific troop.
     * @param troop Shared pointer to the troop making the turn.
     * @param field Reference to the 6x6 battlefield array.
     * @param action Reference to the Action object for performing actions.
     * @param battle_status Reference to the battle status flag.
     */
    void makeTurn(std::shared_ptr<Troop>& troop, std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& field, Action& action, bool& battle_status);
};

#endif
