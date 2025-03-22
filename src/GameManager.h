/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <iostream>
#include <memory>
#include "TerminalUI.h"
#include "Player.h"
#include "AI.h"
#include "BattleManager.h"

/**
 * @enum GameState
 * @brief Defines the possible states of the game.
 */
enum class GameState
{
    MENU,           ///< Main menu state.
    CHOOSE_DIFFICULTY, ///< Difficulty selection state.
    PREPARE_ARMY,   ///< Army preparation state.
    BATTLE,         ///< Battle state.
    END             ///< Game end state.
};

/**
 * @class GameManager
 * @brief Manages the overall game flow and state transitions.
 * 
 * Coordinates the game loop, user interface, and battle management.
 */
class GameManager
{
public:
    /**
     * @brief Default constructor for GameManager.
     * 
     * Initializes the game state to MENU and sets up default parameters.
     */
    GameManager();

    /**
     * @brief Runs the main game loop.
     * 
     * Continuously updates the game state until the game ends.
     */
    void run();

    /**
     * @brief Updates the game state based on the current state.
     * 
     * Handles transitions between menu, difficulty selection, army preparation, battle, and end states.
     */
    void update();

private:
    GameState _state; ///< Current state of the game.
    bool _mode; ///< Game mode (false for single-player, true for multiplayer).
    int _difficulty; ///< Difficulty level (0 - Easy, 1 - Normal, 2 - Hard).
    TerminalUI _ui; ///< User interface object for terminal interaction.
    BattleManager _battle; ///< Battle manager object for handling battles.
    bool _status; ///< Game status (true - running, false - terminated).
};

#endif
