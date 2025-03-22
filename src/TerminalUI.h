/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TERMINALUI_H
#define TERMINALUI_H

#include <iostream>
#include <array>
#include <memory>
#include "Catalog.h"
#include "Player.h"

/**
 * @enum InfoState
 * @brief Defines the types of information to display in the terminal UI.
 */
enum class InfoState
{
    MENU,                   ///< Main menu display.
    ENTER_NAME_SINGLEPLAYER, ///< Prompt for single-player name input.
    ENTER_NAME_MULTIPLAYER_1, ///< Prompt for first multiplayer name input.
    ENTER_NAME_MULTIPLAYER_2, ///< Prompt for second multiplayer name input.
    CHOOSE_DIFFICULTY,      ///< Difficulty selection display.
    HEROES,                 ///< Hero selection display.
    TROOPS,                 ///< Troop selection display.
    AMOUNT                  ///< Troop amount input prompt.
};

/**
 * @enum InputState
 * @brief Defines the types of input expected from the user.
 */
enum class InputState
{
    ONE_OF_THREE, ///< Input restricted to 1, 2, or 3.
    GET_NAME,     ///< Input for a player's name.
    TROOPS,       ///< Input for selecting a troop (1-15).
    AMOUNT        ///< Input for specifying troop amount (1-99).
};

/**
 * @class TerminalUI
 * @brief Manages the terminal-based user interface for the game.
 * 
 * Handles displaying information, processing user input, and army selection.
 */
class TerminalUI
{
public:
    /**
     * @brief Displays information based on the specified state.
     * @param info_state The type of information to display (e.g., menu, prompts).
     */
    void displayInfo(InfoState info_state);

    /**
     * @brief Handles user input based on the expected input type.
     * @param input_state The type of input expected from the user.
     * @return String containing the validated user input.
     */
    std::string handleInput(InputState input_state);

    /**
     * @brief Displays the player's army composition.
     * @param player Reference to the Player whose army is to be displayed.
     */
    void showArmy(Player& player);

    /**
     * @brief Selects a troop for the player's army based on remaining might.
     * @param remaining_might Remaining might available for troop selection.
     * @param should_end Reference to a flag indicating if selection should end.
     * @return Shared pointer to the selected Troop object, or nullptr if selection ends.
     */
    std::shared_ptr<Troop> selectTroop(int remaining_might, bool& should_end);

    /**
     * @brief Gets the catalog of available heroes and troops.
     * @return Reference to the Catalog object.
     */
    Catalog& getCatalog();

private:
    /**
     * @brief Displays the list of available heroes.
     */
    void showHeroes();

    /**
     * @brief Displays the list of available troops.
     */
    void showTroops();

    /**
     * @brief Selects the amount of units for a chosen troop.
     * @param troop Shared pointer to the Troop object being configured.
     * @param remaining_might Remaining might available for the troop.
     * @return Integer representing the selected amount of units.
     */
    int selectTroopAmount(std::shared_ptr<Troop>& troop, int remaining_might);

    Catalog _catalog; ///< Catalog of available heroes and troops.
};

#endif
