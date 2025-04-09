# General System Description

**Genre:** Turn-based strategy, simplified version of the HoMM3 combat system

**Concept:** The game is a turn-based strategic combat system inspired by Heroes of Might and Magic 3 (HoMM3), but with simplified mechanics for a terminal-based implementation. The focus is on tactical troop management and hero spell-casting on a battlefield, with heroes not directly influencing troop stats except through spells.

## Main System Elements:

1. **Troops:**
    * Each troop is a combat entity with specific characteristics:
        * **Attack:** Determines damage dealt (total attack = attack * amount).
        * **Health (HP):** Determines survivability (total health = health * amount).
        * **Stamina:** Limits movement and actions per turn (replaces Defense and Speed in some aspects).
        * **Initiative:** Determines turn order (replaces Speed for sequencing).
        * **Might:** Contributes to the army's total might limit (might * amount).
        * **Amount:** Number of units (1–99), scaling damage, health, and might.
    * No explicit Defense stat; damage resistance is not implemented.
    * No distinct Attack Types (Melee, Ranged, Magic) or subclasses; all troops are generic with uniform attack range (adjacent cells).
    * Effects (buffs/debuffs) can modify health, attack, or stamina via spells.

2. **Heroes:**
    * Heroes do not fight but cast spells to affect troops.
    * Characteristics:
        * **Mana:** Limits spell-casting (20–30 initial mana).
        * **Might:** Contributes to army might limit (400–600).
        * **Spells:** 3 spells per hero (damage, buffs, debuffs).
    * No passive effects influencing troop characteristics; only spells affect troops.

3. **Armies:**
    * Consist of 1 hero and up to 6 troops, limited by a might limit (1000–5500 for single-player, 3000 for AI).
    * No separate spell book; spells are tied to the hero (3 spells max).

4. **Battlefield:**
    * A 6x6 grid for troop placement and movement.
    * Troops start on opposite sides (Player 1 at y=0, Player 2/AI at y=5).

5. **Battle System:**
    * Turn-based combat on a 6x6 grid, ordered by troop initiative (highest first).
    * Actions per turn (via Action class):
        * **Move:** To any free cell within stamina range.
        * **Attack:** Targets adjacent enemy troops (1-cell range).
        * **Cast:** Uses a hero’s spell (requires mana, targets any troop).
        * **Skip:** Ends the turn.
    * No explicit Defend action; troops can attack or cast once per turn, move multiple times within stamina.
    * Damage = attack * amount; no crits or range modifiers.
    * Battle ends when one army’s troops are all defeated (amount <= 0).

6. **Artificial Intelligence (AI):**
    * Controls enemy army in single-player mode.
    * Prepares a fixed army (might = 3000) with predefined troops.
    * Moves toward nearest enemy and attacks if in range; skips if no targets.

## Game Goal:
Win the battle by destroying all enemy troops on the battlefield.
