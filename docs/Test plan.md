# Test Plan

## Test Objectives

*   Verify that the terminal-based turn-based strategy game functions correctly using automated tests, ensuring tactical combat on a 6x6 grid.
*   Ensure all game modes (single-player vs. AI, local multiplayer) operate as expected through unit and integration tests.
*   Validate core mechanics, including troop management, hero spell-casting, and battle actions, using Google Test.

## Test Scope

### 1. Functional Testing
*   Test the initialization and navigation of game states (MENU, SELECT_MODE, PREPARE_ARMY, BATTLE, END, REPLAY) using unit tests for `GameManager` and `GameStateManager`.
*   Verify army preparation in PREPARE_ARMY, ensuring mightLimit constraints (15,000 for multiplayer, 5,000–15,000 for single-player based on difficulty) with unit tests for `GameManager`, `Catalog`, and `Troop`.
*   Validate turn-based combat on the 6x6 grid, including actions (MOVE, ATTACK, DEFEND, SKIP, CAST) and damage calculations, using unit and integration tests for `BattleManager`, `Battlefield`, `Action`, and `Troop`.
*   Ensure correct troop behavior (MeleeTroop, RangeTroop, MeleeMagicTroop, MeleePhysicalTroop, RangeMagicTroop, RangePhysicalTroop) with characteristics (attack, defense, health, speed, might, amount) through unit tests for `Troop` and its subclasses.
*   Confirm hero functionality, including mana-based spell-casting (via Spell) using unit tests for `Hero` and `Spell`.
*   Test AI behavior in single-player mode for army preparation and battle actions with unit tests for `AI`.
*   Validate local multiplayer mode, ensuring turn alternation and army limits, using integration tests for `GameManager` and `BattleManager`.

### 2. Non-Functional Testing
*   Verify terminal interface performance, ensuring clear text prompts and quick response times (<1 second per turn) through performance tests in Google Test.
*   Test usability, confirming intuitive input (e.g., "move 2 3", "attack 1") and readable output (6x6 grid, troop states) via mock terminal outputs.

### 3. Boundary and Edge Cases
*   Test army composition with minimum (1 troop, 1 unit) and maximum (6 troops, 99 units each) might, ensuring mightLimit compliance, using unit tests for `GameManager` and `Troop`.
*   Verify battlefield edge cases (troops at x=0, x=5, y=0, y=5) for MOVE and ATTACK actions with unit tests for `Battlefield` and `Action`.
*   Check invalid inputs (e.g., "move 6 6", negative numbers) and ensure proper error handling with unit tests for `TerminalUI` and `BattleManager`.
*   Test spell-casting (CAST) with empty spell book, invalid targets, and mana limits using unit tests for `Hero`, `Spell`, and `Action`.
