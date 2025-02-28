# General System Description

**Genre:** Turn-based strategy, simplified version of the HoMM3 combat system

**Concept:** The game is a turn-based strategic combat system inspired by Heroes of Might and Magic 3 (HoMM3), but with simplified mechanics to make it easier to create it as a terminal-based game. The main focus is on tactical planning and troop management on the battlefield, as well as utilizing heroes who cast spells but do not directly influence troop characteristics.

## Main System Elements:

1.  **Troops:**
    *   Each troop is a combat entity with specific characteristics:
        *   Attack: Influences the damage dealt, calculated using might and troop characteristics.
        *   Defense: Influences resistance to damage.
        *   Health (HP): Determines troop survivability.
        *   Speed: Determines the troop's turn order.
        *   Attack Type: (e.g., Melee, Ranged, Magic Attack).
        *   Might: Influences the army's total might, used as a limit (mightLimit) for army composition.
    *   The amount of units in each troop affects its overall damage and health, with might scaled accordingly.
    *   Different troop types have unique characteristics (e.g., magic resistance, defense) implemented in subclasses (Melee, Ranged, Magic, Physical), but no special abilities.

2.  **Heroes:**
    *   Heroes are unique characters who cast spells but do not directly participate in battles, manage armies, or influence troop characteristics, including might.
    *   Each hero has characteristics:
        *   Mana: Tracks available mana for casting spells, with varying amounts influencing might and spell usage.
        *   Magic: Enables casting spells (via Spell) to affect troops (damage, buffs, debuffs).
        *   Might: Influences only the hero’s contribution to the army's total might for mightLimit, without affecting troops.

3.  **Armies:**
    *   An army consists of several troops (up to 6), one hero, and a spell book (up to 5 spells), limited by mightLimit. The hero’s spells and passive effects affect troop performance during battles.

4.  **Battlefield:**
    *   A 6x6 square grid for troop placement and movement.

5.  **Battle System:**
    *   Combat occurs in turn-based mode on a 6x6 grid, determined by troop speed.
    *   During a turn, the player or AI can (via Action): Move a troop to a free cell, Attack an enemy troop, Use a hero’s spell (CAST), Defend (if not moved), or Skip the turn.
    *   Damage is calculated based on the attack, defense, crits, and range of attacking and defending troops, enhanced by spells (via CAST).
    *   The battle ends when all troops of one of the armies are destroyed.

6.  **Artificial Intelligence (AI):**
    *   The AI controls enemy armies and heroes.
    *   AI makes decisions based on predefined rules and strategies, accounting for hero spell-casting but not hero might or passive effects on troops.

## Game Goal:
Win the battle by destroying all enemy troops on the battlefield.
