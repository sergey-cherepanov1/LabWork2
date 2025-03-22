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

    /**
     * @brief Gets the current state of the game.
     * @return The current GameState value.
     */
    GameState getState();

    /**
     * @brief Gets the current status of the game or entity.
     * @return True if the status is active or alive, false otherwise.
     */
    bool getStatus();

    /**
     * @brief Sets the current state of the game.
     * @param state The new GameState value to set.
     */
    void setState(GameState state);

    /**
     * @brief Gets the current difficulty level of the game.
     * @return The difficulty level (e.g., 0 for Easy, 1 for Normal, 2 for Hard).
     */
    int getDifficulty();

    /**
     * @brief Sets the difficulty level of the game.
     * @param difficulty The new difficulty level to set (e.g., 0 for Easy, 1 for Normal, 2 for Hard).
     */
    void setDifficulty(int difficulty);

    /**
     * @brief Gets the current game mode.
     * @return True if multiplayer mode is active, false if single-player mode is active.
     */
    bool getMode();

    /**
     * @brief Sets the game mode.
     * @param mode The new game mode to set (true for multiplayer, false for single-player).
     */
    void setMode(bool mode);

    /**
     * @brief Gets a reference to the battle manager.
     * @return Reference to the BattleManager object.
     */
    BattleManager& getBattle();

private:
    GameState _state; ///< Current state of the game.
    bool _mode; ///< Game mode (false for single-player, true for multiplayer).
    int _difficulty; ///< Difficulty level (0 - Easy, 1 - Normal, 2 - Hard).
    TerminalUI _ui; ///< User interface object for terminal interaction.
    BattleManager _battle; ///< Battle manager object for handling battles.
    bool _status; ///< Game status (true - running, false - terminated).
};

#endif
