# Test Plan

## Test Objectives
* Verify that the terminal-based turn-based strategy game functions correctly using automated tests with Google Test, ensuring tactical combat on a 6x6 grid.
* Ensure single-player mode (against AI) operates as expected through unit and integration tests.
* Validate core mechanics, including troop management, hero spell-casting, and battle actions, using Google Test.

## Test Scope

### 1. Functional Testing
* Test the initialization and navigation of game states (MENU, CHOOSE_DIFFICULTY, PREPARE_ARMY, BATTLE, END) using unit tests for `GameManager`.
* Verify army preparation in PREPARE_ARMY, ensuring might limit constraints (5500 for Easy, 2500 for Normal, 1000 for Hard for player; 3000 for AI) with unit tests for `GameManager`, `Catalog`, `Army`, and `Troop`.
* Validate turn-based combat on the 6x6 grid, including actions (MOVE, ATTACK, CAST, SKIP) and damage calculations, using unit and integration tests for `BattleManager`, `Action`, and `Troop`.
* Ensure correct troop behavior with characteristics (attack, health, stamina, initiative, might, amount) through unit tests for `Troop`.
* Confirm hero functionality, including mana-based spell-casting (3 spells per hero) using unit tests for `Hero`, `Spell`, and `Effect`.
* Test AI behavior in single-player mode for army preparation and battle actions with unit tests for `AI`.
* Validate battlefield initialization and troop placement (Player 1 at y=0, AI at y=5) using unit tests for `BattleManager`.

### 2. Non-Functional Testing
* Verify terminal interface performance, ensuring turns complete within 1 second on standard hardware, using performance tests in Google Test for `BattleManager` and `Action`.
* Test usability, confirming clear text prompts and readable output (6x6 grid, troop stats) via mock terminal outputs in `TerminalUI` and `BattleManager`.

### 3. Boundary and Edge Cases
* Test army composition with minimum (1 troop, 1 unit) and maximum (6 troops, 99 units each) might, ensuring might limit compliance, using unit tests for `GameManager`, `Army`, and `Troop`.
* Verify battlefield edge cases (troops at x=0, x=5, y=0, y=5) for MOVE and ATTACK actions with unit tests for `Action`.
* Check invalid inputs (e.g., "move 6 6", "attack -1 0", non-numeric input) and ensure proper error handling with unit tests for `TerminalUI` and `Action`.
* Test spell-casting (CAST) with insufficient mana, invalid targets, and edge cases (max/min effect values) using unit tests for `Hero`, `Spell`, `Effect`, and `Action`.

## Test Cases

### Unit Tests
1. **GameManager**
   * `TEST(GameManager, StateTransitions)`: Verify MENU transitions to CHOOSE_DIFFICULTY on "1", END on "3".
   * `TEST(GameManager, DifficultySelection)`: Test might limits (5500, 2500, 1000) for inputs "1", "2", "3".
   * `TEST(GameManager, ArmyPrepToBattle)`: Ensure PREPARE_ARMY transitions to BATTLE after army setup.

2. **Troop**
   * `TEST(Troop, AttackDamage)`: Troop (attack=5, amount=10) deals 50 damage, reducing target health accordingly.
   * `TEST(Troop, AmountCalculation)`: Health=10, total_health=55 reduces amount to 6.
   * `TEST(Troop, EffectApplication)`: Apply health effect (-5, duration=2), verify total health decrease.
   * `TEST(Troop, StaminaLimits)`: Move reduces stamina correctly; zero stamina blocks further moves.

3. **Hero**
   * `TEST(Hero, ManaReduction)`: Casting spell (cost=10) reduces mana from 20 to 10.
   * `TEST(Hero, SpellAccess)`: Verify 3 spells are accessible and match catalog data.

4. **Spell**
   * `TEST(Spell, EffectRetrieval)`: Spell returns correct effect (type, value, duration).
   * `TEST(Spell, CostValidation)`: Verify cost matches initialized value.

5. **Effect**
   * `TEST(Effect, DurationDecrease)`: Decrease duration from 3 to 2 after one turn.
   * `TEST(Effect, ApplyEachTurn)`: Verify applyEachTurn flag affects application logic.

6. **Army**
   * `TEST(Army, MightCalculation)`: Hero (might=500) + 2 troops (might=10, amount=10 each) = 700.
   * `TEST(Army, StatusCheck)`: Army with 1 troop alive returns true; all null returns false.

7. **Catalog**
   * `TEST(Catalog, HeroTemplates)`: Verify 3 heroes with correct might, mana, and spells.
   * `TEST(Catalog, TroopTemplates)`: Verify 15 troops with correct stats.

8. **Action**
   * `TEST(Action, MoveValid)`: Move from (0,0) to (1,1) succeeds with stamina=2.
   * `TEST(Action, MoveInvalid)`: Move to occupied cell or beyond stamina fails.
   * `TEST(Action, AttackRange)`: Attack succeeds only on adjacent cells.
   * `TEST(Action, CastSpell)`: Spell applies effect and reduces mana; fails if mana insufficient.
   * `TEST(Action, SkipTurn)`: Sets hasAttacked and stamina to 0.

9. **AI**
   * `TEST(AI, ArmySetup)`: Verify AI army might equals 3000 with 6 troops.
   * `TEST(AI, MoveToEnemy)`: Moves toward nearest enemy within stamina.
   * `TEST(AI, AttackDecision)`: Attacks adjacent enemy; skips if no targets.

10. **TerminalUI**
    * `TEST(TerminalUI, InputValidation)`: "1" accepted for ONE_OF_THREE; "4" rejected.
    * `TEST(TerminalUI, TroopSelection)`: Select troop within might limit; reject if exceeds.

### Integration Tests
1. **BattleManager**
   * `TEST(BattleManager, FullBattle)`: Simulate battle with 1 troop per side; ends when one defeated.
   * `TEST(BattleManager, TurnOrder)`: Verify queue sorts by initiative descending.
   * `TEST(BattleManager, FieldSetup)`: Player 1 troops at y=0, AI at y=5.

2. **GameManager + TerminalUI + BattleManager**
   * `TEST(EndToEnd, SinglePlayerFlow)`: From MENU to BATTLE, setup army, fight, and end with winner.

## Performance Tests
* `TEST(Performance, TurnSpeed)`: Ensure `BattleManager::turn` completes in <1s with 12 troops.
* `TEST(Performance, DisplaySpeed)`: Verify `BattleManager::displayField` executes in <1s.
