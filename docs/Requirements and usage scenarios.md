# System Requirements

## Functional Requirements

### 1. Game Core
* The system shall provide a terminal-based turn-based strategy game inspired by Heroes of Might and Magic 3, with simplified mechanics.
* The system shall support single-player mode (against AI); local multiplayer mode is not fully implemented (currently exits with a message).
* The system shall manage game states (MENU, CHOOSE_DIFFICULTY, PREPARE_ARMY, BATTLE, END) using `GameManager`.
* The system shall allow players to prepare armies with a maximum of 6 troops and 1 hero, limited by a might limit (5500 for Easy, 2500 for Normal, 1000 for Hard in single-player; 3000 for AI).
* The system shall calculate total army might as the sum of the hero’s might and each troop’s might (might * amount, where amount is 1–99).

### 2. Troops
* The system shall provide a roster of troop types with characteristics: attack, health, stamina, initiative, and might.
* Each troop shall represent a single entity with an amount of units (1–99), affecting total damage (attack * amount) and total health (health * amount), scaled by might * amount.
* No troop subtypes (e.g., Melee, Ranged, Magic) or unique characteristics (e.g., magic resistance) are implemented; all troops use a single `Troop` class with uniform attack range (adjacent cells).

### 3. Heroes
* The system shall provide a selection of 3 hero characters, each with mana (20–30) and 3 predefined spells (damage, buffs, debuffs).
* The system shall allow heroes to cast spells during battle via the `CAST` action, consuming mana and affecting troop stats (health, attack, stamina).
* No passive effects from heroes influence troop characteristics.

### 4. Armies
* The system shall manage armies, each consisting of 1 hero and up to 6 troops, with a total might not exceeding the might limit (1000–5500 for player, 3000 for AI).
* The system shall allow army customization during PREPARE_ARMY via a catalog (`Catalog`), respecting might-based limits.

### 5. Battlefield
* The system shall provide a 6x6 square grid for troop placement and movement, implemented in `BattleManager`.
* The system shall handle troop positioning (Player 1 at y=0, Player 2/AI at y=5) and movement within the 6x6 grid, ensuring valid coordinates (0–5 for x and y).

### 6. Battle System
* The system shall implement a turn-based combat system on the 6x6 grid, with turns ordered by troop initiative (highest first) via `BattleManager`.
* The system shall support the following actions per turn (via `Action` class):
  * **MOVE:** To any free cell within stamina range.
  * **ATTACK:** Targets an adjacent enemy troop (1-cell range).
  * **CAST:** Uses a hero’s spell on any troop, if mana is sufficient.
  * **SKIP:** Ends the turn.
* The system shall calculate damage as attack * amount, with no defense, crits, or range modifiers.
* The system shall end the battle when all troops of one army are defeated (amount <= 0), declaring the other player the winner.

### 7. User Interface
* The system shall provide a terminal-based interface (`TerminalUI`) for player interaction, using text prompts to manage troops, execute actions (MOVE, ATTACK, CAST, SKIP), and display game information.
* The system shall display the 6x6 battlefield, troop states (health, attack, stamina), hero mana, spells, and turn queue via text output in `BattleManager`.

### 8. Artificial Intelligence (AI)
* The system shall provide an AI opponent for single-player mode (`AI` class), preparing a fixed army (might = 3000) and making decisions during battle.
* The AI shall execute actions (MOVE toward nearest enemy, ATTACK if in range, SKIP otherwise) based on simple predefined rules.

### 9. Local Multiplayer
* The system shall recognize a local multiplayer option in the menu, but currently exits with a message ("Multiplayer mode is not yet implemented").

## Non-Functional Requirements

### 1. Performance
* The system shall run efficiently in a terminal environment, completing turns and calculations within 1 second on standard hardware (e.g., modern PC with C++ compiler).
* The system shall handle up to 12 troops (6 per army) and 6 spells (3 per hero) without performance degradation.

### 2. Usability
* The system shall provide clear text prompts and error messages for user input (e.g., "Invalid target", "Not enough mana") via `TerminalUI` and `Action`.
* The system shall support simple keyboard input (e.g., "1" for actions, "2 3" for coordinates) for all interactions.

### 3. Maintainability
* The system shall be implemented in C++ with modular classes (`.h` and `.cpp` files), adhering to object-oriented principles.
* The code shall include Doxygen comments for each class and method (currently implemented).

## Constraints
* The system shall operate solely in a terminal environment, using only standard C++ libraries (e.g., `<iostream>`, `<vector>`).
* The system shall limit army composition to 6 troops and 1 hero with 3 spells, with might limit constraints (1000–5500 for single-player, 3000 for AI).
* The battlefield shall be fixed at a 6x6 grid, with no terrain or strategic elements.

# Use Case Scenarios

1. **Launching the Game:**
    * The player launches the game executable.
    * The system initializes and displays the main menu via `TerminalUI`.

2. **Starting a New Game (Single Player):**
    * The player selects "Start Game" (1) from the menu.
    * The player enters their name via `TerminalUI`.
    * The player selects difficulty (1–3: Easy, Normal, Hard), setting might limit (5500, 2500, 1000).
    * The player selects a hero (1–3) from `Catalog`, contributing might (400–600).
    * The player selects up to 6 troops from `Catalog`, entering troop number (1–15) and amount (1–99), respecting might limit.
    * The system displays army might (e.g., "The Might of [name]'s army: 1200/5500").
    * The system transitions to BATTLE on a 6x6 grid.

3. **Starting a New Game (Local Multiplayer):**
    * The player selects "Local Multiplayer" (2) from the menu.
    * The system displays "Multiplayer mode is not yet implemented" and exits.

4. **Executing a Turn:**
    * The turn begins with the highest-initiative troop, displayed as "[Player]'s [Troop] turn".
    * The player selects an action via `TerminalUI`:
      * "1" to MOVE (enters "x y" coordinates, e.g., "2 3"), limited by stamina.
      * "2" to ATTACK (enters target "x y"), if adjacent.
      * "3" to CAST (selects spell 1–3, target "x y"), if mana available.
      * "4" to SKIP.
    * The system displays results (e.g., "[Troop] deals 50 damage to [Target]").

5. **Winning the Game:**
    * All enemy troops are defeated (amount <= 0).
    * The system displays "[Player] has won the battle!" and ends via `GameManager`.

6. **Losing the Game:**
    * All player troops are defeated (amount <= 0).
    * The system displays "AI Bot has won the battle!" and ends.

7. **Exiting the Game:**
    * The player selects "Exit" (3) from the menu, terminating the game.

## Notes:
* These requirements reflect the current implementation, with local multiplayer and some features (e.g., Defense, troop subtypes) not yet realized.
