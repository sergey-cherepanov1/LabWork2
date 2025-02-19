## System Requirements

### Core Gameplay Features:

*   **Units:** A diverse roster of unit types, each with unique stats (attack, defense, health, speed, damage type), and a "Might" value that contributes to the overall army power.
*   **Heroes:** A selection of hero characters. Each hero possesses inherent characteristics (e.g., tactics, leadership) and a "Might" value that enhances the army's combat effectiveness. The hero's characteristics directly influence the stats of the units in their army.
*   **Armies:** Armies composed of unit squads and a single hero, where the total "Might" of the army is derived from the combined "Might" values of the units and the hero.
*   **Battlefields:** A variety of battlefields with distinct grid layouts, terrain types, and strategic elements affecting unit movement and combat.
*   **Turn-Based Combat:** A functional turn-based combat system with unit movement, attack actions, and precise damage calculations based on unit stats and terrain.
*   **User Interface:** An intuitive user interface enabling seamless unit management, execution of actions, and access to essential game information.
*   **Magic System:** A system of spells that heroes can cast during battle to damage enemies, buff allies, or manipulate the battlefield, potentially influenced by the hero's characteristics.

### Artificial Intelligence (AI) and Multiplayer:

*   AI Opponent: A challenging AI opponent exhibiting strategic decision-making capabilities and adaptability to the player's tactics.
*   Local Multiplayer Mode: Allows two players to take turns controlling their armies on the same device. When one player completes all actions for their units in a turn, control passes to the other player.

### Notes:

*   These requirements define the target features of the fully developed game.

## Use Case Scenarios

1.  **Launching the Game:**
    *   The player launches the game executable.
    *   The game initializes and presents the main menu.

2.  **Starting a New Game (Single Player):**
    *   The player selects "Play" from the main menu.
    *   The player selects the difficulty level for the game (Easy, Medium, Hard). The selected difficulty level determines the maximum allowable "Might" value for the army.
    *   The player selects a hero from the available roster. The hero's characteristics will influence the stats of the player's army. The Hero contributes its "Might" value to the total army Might.
    *   The player customizes their army by selecting units. Each unit contributes its "Might" value to the total army Might.
    *   The game displays the army's total "Might" value, reflecting the combined strength of the hero and units. The player cannot proceed if the total "Might" exceeds the limit imposed by the selected difficulty level.
    *   The player selects a battlefield from available options.

3.  **Starting a New Game (Local Multiplayer):**
    *   The player selects "Local Multiplayer" from the main menu.
    *   Both players have a pre-established maximum "Might" limit for their armies.
    *   Player 1 and Player 2 each select a hero from the available roster. The hero's characteristics will influence the stats of their respective armies. Each Hero contributes its "Might" value to its army's total Might.
    *   Player 1 and Player 2 each customize their army by selecting units. Each unit contributes its "Might" value to its respective army's total Might.
    *   The game displays each player's total "Might" value, reflecting the combined strength of their hero and units. Players cannot proceed if their total "Might" exceeds the established limit.
    *   The players select a battlefield from available options.
    *   During gameplay:
        *   The turn order of units is predetermined based on their speed attributes.
        *   Players may choose to skip a turn for any unit, but the overall turn order remains predetermined.
        *   Turns alternate between players until one player's army is completely defeated.

4.  **Executing a Turn:**
    *   The player's turn begins.
    *   The player selects a unit from their army to activate.
    *   The player moves the selected unit to a valid location on the battlefield grid, constrained by its movement range.
    *   The player attacks an enemy unit within the unit's attack range. Damage calculations consider the unit's attack, the target's defense, and the "Might" of both the attacking unit and the hero influencing the army.
    *   The player may choose to skip a turn for any unit.

5.  **Winning the Game:**
    *   One player's army is entirely defeated.
    *   The winning player is declared victorious.
    *   The game displays a "Victory" screen.
    *   The player is given the option to return to the main menu or start a new game.

6.  **Losing the Game:**
    *   All units of the player's army are defeated.
    *   The game displays a "Defeat" screen.
    *   The player is given the option to return to the main menu or start a new game.

7.  **Exiting the Game:**
    *   The player selects "Exit" from the main menu.
    *   The game terminates gracefully.


---

**Note:** The lines highlighted with `<ins>` indicate features that may be developed after the initial release. Underlining is used here to emphasize these potential future enhancements.

