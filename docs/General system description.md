# General System Description

**Genre:** Turn-based strategy, simplified version of the HoMM3 combat system

**Concept:** The game is a turn-based strategic combat system inspired by Heroes of Might and Magic 3 (HoMM3), but with simplified mechanics to make it easier to create it. The main focus is on tactical planning and unit management on the battlefield, as well as utilizing heroes who influence battles with their characteristics and skills.

## Main System Elements:

1.  **Units:**
    *   Each unit is a combat entity with specific characteristics:
        *   Attack: Influences the damage dealt.
        *   Defense: Influences resistance to damage.
        *   Health (HP): Determines unit survivability.
        *   Speed: Determines the unit's turn order.
        *   Damage: Minimum and maximum damage values dealt.
        *   Attack Type: (e.g., Melee, Ranged, Magic Attack).
        *   Might: Influences the army's total power.
    *   Units are organized into squads (stacks) with a specific number of units in each. The quantity affects the squad's overall damage and health.
    *   <ins>Different unit types have unique abilities or bonuses (e.g., magic resistance, double attack).</ins>

2.  **Heroes:**
    *   <ins>Heroes are unique characters who manage armies but do not directly participate in battles.</ins>
    *   <ins>Each hero has their own characteristics:</ins>
        *   <ins>Mana: Used to cast spells.</ins>
        *   <ins>Skills: For example:</ins>
            *   <ins>Magic: Allows the use of spells to damage enemies or support allies.</ins>
            *   <ins>Tactics: Increases the movement speed of units on the battlefield or allows better positioning before the start of battle.</ins>
            *   <ins>Leadership: Increases army morale or provides bonuses to unit characteristics.</ins>
        *   Might: Influences the army's total power.

3.  **Armies:**
    *   An army consists of several unit squads and one hero.
    *   Before the battle, the player selects units for their army <ins>and assigns a hero.</ins>

4.  **Battlefield:**
    *   A grid (hexagonal or square) with a specific number of cells.
    *   <ins>Cells may contain obstacles, bonuses, or special zones.</ins>
    *   <ins>The battlefield determines the placement and movement of units.</ins>

5.  **Battle System:**
    *   Combat occurs in turn-based mode.
    *   The turn order is determined by the speed of the units <ins>and the hero's skills.</ins>
    *   During a turn, the player can:
        *   Move a unit to a free cell.
        *   Attack an enemy unit.
        *   <ins>Use a unit's ability or hero's spell (if available).</ins>
        *   Skip the turn.
    *   Damage is calculated based on the characteristics of the attacking and defending units<ins>, as well as the hero's skills.</ins>
    *   The battle ends when all units of one of the armies are destroyed.

6.  **Artificial Intelligence (AI):**
    *   The AI controls enemy armies and heroes.
    *   AI makes decisions based on predefined rules and strategies.

## Game Goal:

Win the battle by destroying all enemy units on the battlefield.

---

**Note:** The lines highlighted with underlining (`<ins>`) indicate features that may be developed after the main part of the game.


