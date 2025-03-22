/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef ACTION_H
#define ACTION_H

#include "Troop.h"
#include "Player.h"
#include "AI.h"
#include <array>
#include <memory>
#include <iostream>

/**
 * @class Action
 * @brief Handles actions that a troop can perform during a battle.
 * 
 * Manages movement, attacks, spell casting, and skipping turns for troops on the battlefield.
 */
class Action
{
public:
    /**
     * @brief Constructor for Action.
     * @param field Reference to the 6x6 battlefield array.
     * @param player1 Reference to the first player.
     * @param player2 Reference to the second player.
     * @param ai Reference to the AI opponent.
     */
    Action(std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& field, Player& player1, Player& player2, AI& ai);

    /**
     * @brief Moves a troop to a new position on the battlefield.
     * @param troop Shared pointer to the troop to move.
     * @return 0 on success, 1 if move is invalid or stamina is insufficient.
     */
    int move(std::shared_ptr<Troop>& troop);
    
    /**
     * @brief Performs an attack by a troop on a player-selected target.
     * @param troop Shared pointer to the attacking troop.
     * @return 0 on success, 1 if attack fails, 2 if battle ends due to defeat.
     */
    int attack(std::shared_ptr<Troop>& troop);

    /**
     * @brief Performs an attack by a troop on a specific target (used by AI).
     * @param troop Shared pointer to the attacking troop.
     * @param target_x X-coordinate of the target.
     * @param target_y Y-coordinate of the target.
     * @return 0 on success, 1 if attack fails, 2 if battle ends due to defeat.
     */
    int attack(std::shared_ptr<Troop>& troop, int target_x, int target_y);
    
    /**
     * @brief Casts a spell by a troop using the hero's abilities.
     * @param troop Shared pointer to the troop casting the spell.
     * @return 0 on success, 1 if spell casting fails, 2 if battle ends due to defeat.
     */
    int castSpell(std::shared_ptr<Troop>& troop);

    /**
     * @brief Skips the turn for a troop.
     * @param troop Shared pointer to the troop skipping its turn.
     */
    void skip(std::shared_ptr<Troop>& troop);

    /**
     * @brief Checks if there are valid attack targets within range of a troop.
     * @param troop Shared pointer to the troop to check.
     * @return True if there are valid targets, false otherwise.
     */
    bool canAttackTarget(std::shared_ptr<Troop>& troop);

    /**
     * @brief Removes a defeated troop from the battlefield.
     * @param target Shared pointer to the defeated troop.
     * @param target_x X-coordinate of the defeated troop.
     * @param target_y Y-coordinate of the defeated troop.
     * @return 0 if troop is removed, 2 if battle ends due to army defeat.
     */
    int removeDefeatedTroop(std::shared_ptr<Troop>& target, int target_x, int target_y);

private:
    std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& _field; ///< Reference to the battlefield.
    Player& _player1; ///< Reference to the first player.
    Player& _player2; ///< Reference to the second player.
    AI& _ai; ///< Reference to the AI opponent.
};

#endif
