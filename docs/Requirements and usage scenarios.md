# System Requirements

## Functional Requirements

### 1. Game Core
*   The system shall provide a terminal-based turn-based strategy game inspired by Heroes of Might and Magic 3, with simplified mechanics.
*   The system shall support two game modes: single-player (against AI) and local multiplayer (two players on the same device).
*   The system shall manage game states (MENU, SELECT_MODE, PREPARE_ARMY, BATTLE, END, REPLAY) using a state management mechanism.
*   The system shall allow players to prepare armies with a maximum of 6 troops, 1 hero, and up to 5 spells, limited by a mightLimit (15,000 for multiplayer, 5,000–15,000 for single-player based on difficulty: Easy, Medium, Hard).
*   The system shall calculate the total army might as the sum of each troop’s might (might * amount, where amount is 1–99) and hero’s might.

### 2. Troops
*   The system shall provide a diverse roster of troop types (Melee, Ranged, Magic, Physical) with characteristics: attack, defense, health, speed and might.
*   Each troop shall represent a single entity with an amount of units (1–99), affecting overall damage and health, scaled by might * amount.
*   The system shall support troop subtypes (MeleeTroop, RangeTroop, MeleeMagicTroop, MeleePhysicalTroop, RangeMagicTroop, RangePhysicalTroop) through inheritance, with unique characteristics (e.g., magic resistance, defense).

### 3. Heroes
*   The system shall provide a selection of hero characters, each with mana (for spell-casting) and a passive effect that influences troop characteristics.
*   The system shall allow heroes to cast spells during battle to affect troops (damage, buffs, debuffs) via the CAST action.

### 4. Armies
*   The system shall manage armies, each consisting of up to 6 troops, 1 hero, and up to 5 spells, with a total might not exceeding mightLimit.
*   The system shall ensure army composition is customizable via a catalog during PREPARE_ARMY, with might-based limitations.

### 5. Battlefield
*   The system shall provide a 6x6 square grid for troop placement and movement.
*   The system shall handle troop positioning and movement within the 6x6 grid, ensuring valid coordinates (0–5 for x and y).

### 6. Battle System
*   The system shall implement a turn-based combat system on the 6x6 grid, with turns determined by troop speed.
*   The system shall support the following actions per turn (via Action class): MOVE (to a free cell), ATTACK (enemy troop within range), DEFEND (if not moved), SKIP (always available), and CAST (hero’s spell).
*   The system shall calculate damage based on troop stats (attack, defense, range, speed), enhanced by spells.
*   The system shall end the battle when all troops of one army are destroyed, declaring the other player the winner.

### 7. User Interface
*   The system shall provide a terminal-based interface for player interaction, using text prompts to manage troops, execute actions (MOVE, ATTACK, DEFEND, SKIP, CAST), and display game information.
*   The system shall display the 6x6 battlefield, troop states, and game status (e.g., current might, turn order) via text output.

### 8. Artificial Intelligence (AI)
*   The system shall provide an AI opponent for single-player mode, making strategic decisions for enemy armies and heroes based on predefined rules (e.g., random or difficulty-based choices).
*   The AI shall prepare armies during PREPARE_ARMY and execute actions (MOVE, ATTACK, DEFEND, SKIP, CAST) during BATTLE, respecting mightLimit and troop limits.

### 9. Local Multiplayer
*   The system shall support local multiplayer mode, allowing two players to take turns controlling their armies on the same device, alternating turns until one army is defeated.

## Non-Functional Requirements

### 1. Performance
*   The system shall run efficiently in a terminal environment, completing turns and calculations within 1 second on standard hardware (e.g., modern PC with C++ compiler).
*   The system shall handle up to 12 troops (6 per army) and 10 spells (5 per army) without performance degradation.

### 2. Usability
*   The system shall provide clear, concise text prompts and error messages for user input, ensuring intuitive navigation for players familiar with terminal interfaces.
*   The system shall support simple keyboard input (e.g., numbers, commands like "move 1 2") for all actions.

### 3. Maintainability
*   The system shall be implemented in C++ with modular classes (e.g., .h and .cpp files), adhering to object-oriented principles for ease of maintenance and extension.
*   The code shall include comments and documentation for each class and method.

### 4. Portability
*   The system shall be portable across standard C++ compilers (e.g., g++, clang++) on Unix-like or Windows systems, requiring no GUI libraries.

## Constraints

*   The system shall operate solely in a terminal environment, without graphical user interface (GUI) or external dependencies beyond standard C++ libraries.
*   The system shall limit army composition to 6 troops, 1 hero, and 5 spells per army, with mightLimit constraints (15,000 for multiplayer, 5,000–15,000 for single-player).
*   The battlefield shall be fixed at a 6x6 grid, with no terrain or strategic elements.

# Use Case Scenarios

1.  **Launching the Game:**
    *   The player launches the game executable.
    *   The game initializes and presents the main menu via terminal text.

2.  **Starting a New Game (Single Player):**
    *   The player selects "Play" from the main menu by entering "1".
    *   The player selects the difficulty level for the game (Easy, Medium, Hard) by entering "1", "2", or "3". The selected difficulty level determines the maximum allowable "might" value for the army (e.g. 5,000 for Easy, 10,000 for Medium, 15,000 for Hard).
    *   The player selects a hero from the available roster by entering "hero <number>". The Hero contributes its "might" value to the total army might.
    *   The player customizes their army by selecting troops. Each troop contributes its might value (might * amount) to the total army might, entered as "troop <number> <amount>" (where amount is 1–99).
    *   The game displays the army's total "might" value via terminal, reflecting the combined strength of the hero and troops (e.g., "Current army might: 1200/15000"). The player cannot proceed if the total "might" exceeds the limit imposed by the selected difficulty level, prompting "Might limit exceeded, choose another troop or reduce amount."
    *   The game automatically selects a 6x6 battlefield and transitions to BATTLE.

3.  **Starting a New Game (Local Multiplayer):**
    *   The player selects "Local Multiplayer" from the main menu by entering "2".
    *   Both players have a pre-established maximum "might" limit for their armies (e.g. 15,000).
    *   Player 1 and Player 2 each select a hero from the available roster by entering "hero <number>". Each Hero contributes its "might" value to its army's total might.
    *   Player 1 and Player 2 each customize their army by selecting troops. Each troop contributes its might value (might * amount) to its respective army’s total might, entered as "troop <number> <amount>" (where amount is 1–99).
    *   The game displays each player's total "might" value via terminal, reflecting the combined strength of their hero and troops (e.g., "Player 1 army might: 1200/15000"). Players cannot proceed if their total "might" exceeds the established limit, prompting "Might limit exceeded, choose another troop or reduce amount."
    *   The game automatically selects a 6x6 battlefield and transitions to BATTLE.
    *   During gameplay:
        *   The turn order of troops is predetermined based on their speed attributes, displayed via terminal (e.g., "Turn order: Troop1, Troop2...").
        *   Players may choose to skip a turn for any troop by entering "skip", but the overall turn order remains predetermined.
        *   Turns alternate between players until one player's army is completely defeated, with the terminal displaying "Player 1’s turn" or "Player 2’s turn."

4.  **Executing a Turn:**
    *   The player's turn begins, with the terminal displaying "It’s your turn. Select a troop and action."
    *   The player selects a troop from their army to activate by entering the troop number (e.g., "1" for first troop).
    *   The player moves the selected troop to a valid location on the 6x6 battlefield grid by entering "move x y" (e.g., "move 2 3"), constrained by its movement range (based on speed).
    *   The player attacks an enemy troop within the troop's attack range by entering "attack <target_number>". Damage calculations consider the troop's attack, the target's defense, displayed as "Troop1 deals 50 damage to Troop2."
    *   The player may use a spell (CAST) by entering "cast <spell_number> <target_number>" (e.g., "cast 1 2" to cast Spell 1 on Troop 2), if spells are available in the army’s spell book.
    *   The player may defend by entering "defend" if the troop has not moved, increasing defense temporarily, displayed as "Troop1 defends (+10 defense)."
    *   The player may choose to skip a turn for any troop by entering "skip", with no action taken.

5.  **Winning the Game:**
    *   One player's army is entirely defeated, with the terminal displaying "All enemy troops destroyed."
    *   The winning player is declared victorious via terminal output, e.g., "Player 1 wins!"
    *   The game displays a "Victory" screen via terminal, prompting "Victory! Return to menu (1) or start new game (2)."
    *   The player is given the option to return to the main menu or start a new game by entering "1" or "2."

6.  **Losing the Game:**
    *   All troops of the player's army are defeated, with the terminal displaying "All your troops destroyed."
    *   The game displays a "Defeat" screen via terminal, prompting "Defeat! Return to menu (1) or start new game (2)."
    *   The player is given the option to return to the main menu or start a new game by entering "1" or "2."

7.  **Exiting the Game:**
    *   The player selects "Exit" from the main menu by entering "3".

## Notes:

*   These requirements define the target features of the fully developed game.
