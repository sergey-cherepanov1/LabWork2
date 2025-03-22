/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include <iomanip>
#include <array>
#include <vector>
#include <memory>
#include <algorithm>
#include "Hero.h"
#include "Spell.h"
#include "Troop.h"
#include "Player.h"
#include "AI.h"
#include "Action.h"

/**
 * @class BattleManager
 * @brief Manages the flow of battle between players or a player and AI.
 * 
 * Responsible for initializing the battlefield, managing turn order, displaying the battle state,
 * and updating effects on units.
 */
class BattleManager
{
public:
    /**
     * @brief Default constructor for BattleManager.
     * 
     * Initializes players, battlefield, and basic parameters.
     */
    BattleManager();

    /**
     * @brief Runs the main battle loop.
     * 
     * Fills the field, manages turn order, and updates the battle state until completion.
     */
    void run();

    /**
     * @brief Sets the game mode (single-player or multiplayer).
     * 
     * Switches between PvP and PvE modes.
     */
    void setMode();

    /**
     * @brief Gets a reference to the first player.
     * @return Reference to the Player object for the first player.
     */
    Player& getPlayer1();

    /**
     * @brief Gets a reference to the second player.
     * @return Reference to the Player object for the second player.
     */
    Player& getPlayer2();

    /**
     * @brief Gets a reference to the artificial intelligence.
     * @return Reference to the AI object.
     */
    AI& getAI();

private:
    Player _player1; ///< First player.
    Player _player2; ///< Second player (used in multiplayer mode).
    AI _ai; ///< Artificial intelligence (used in single-player mode).
    std::array<std::array<std::shared_ptr<Troop>, 6>, 6> _field; ///< 2D array representing the battlefield (6x6).
    std::vector<std::shared_ptr<Troop>> _queue; ///< Queue of units for turns.
    Action _action; ///< Object for managing unit actions.
    bool _battle_status; ///< Battle status (true - ongoing, false - finished).
    bool _mode; ///< Game mode (false - PvE, true - PvP).

    /**
     * @brief Prints a centered line to the console.
     * @param str String to be printed.
     */
    void printCenteredLine(std::string str);

    /**
     * @brief Fills the battlefield with units from the players' armies.
     */
    void fillTheField();

    /**
     * @brief Displays the current state of the battlefield in the console.
     */
    void displayField();

    /**
     * @brief Creates the turn queue based on unit initiative.
     */
    void makeQueue();

    /**
     * @brief Executes one turn for all units in the queue.
     */
    void turn();

    /**
     * @brief Updates effects applied to units.
     */
    void updateEffects();
};

#endif
