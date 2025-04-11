# Testing Report for LabWork2

## Overall Statistics
- **Total Tests:** 45
- **Passed:** 45
- **Failed:** 0
- **Total Execution Time:** 1 ms

## Test Suites and Results

### 1. Troop (4 tests)
- **AttackDamage:** Verifies damage dealt by a unit. Passed (target health 50, amount 5 after attack).
- **EffectApplication:** Verifies effect application with health reduction and expiration. Passed (health reduced from 100 to 90, effect expired).
- **StaminaLimits:** Verifies stamina limits during movement. Passed (`stamina = 0` after two moves).
- **TotalMight:** Verifies total might calculation. Passed (`totalMight = 100`).

### 2. Hero (5 tests)
- **ManaReduction:** Verifies mana reduction when casting a spell. Passed (mana reduced from 20 to 10).
- **SpellAccess:** Verifies access to a hero’s spell list. Passed (3 spells with correct names).
- **InitialMana:** Verifies initial mana value. Passed (`mana = 20`).
- **MightValue:** Verifies hero might value. Passed (`might = 500`).
- **NameAndDescription:** Verifies hero name and description. Passed.

### 3. Spell (5 tests)
- **EffectRetrieval:** Verifies retrieval of a spell’s effect. Passed (correct type, value, duration).
- **CostValidation:** Verifies spell cost. Passed (`cost = 10`).
- **NameValidation:** Verifies spell name. Passed (`name = "Fireball"`).
- **DescriptionValidation:** Verifies spell description. Passed.
- **DefaultConstructor:** Verifies default constructor. Passed.

### 4. Effect (5 tests)
- **DurationDecrease:** Verifies effect duration decrease. Passed (duration reduced from 3 to 0).
- **ApplyEachTurn:** Verifies apply-each-turn flag. Passed.
- **ValueRetrieval:** Verifies effect value retrieval. Passed.
- **TypeRetrieval:** Verifies effect type retrieval. Passed.
- **DefaultConstructor:** Verifies default constructor. Passed.

### 5. BattleManager (4 tests)
- **Initialization:** Verifies battle field initialization. Passed (player unit at `(0, 0)`).
- **QueueSetup:** Verifies turn queue creation. Passed (2 units in queue).
- **FieldSetup:** Verifies unit placement on the field. Passed (player at `(0, 0)`, AI at `(0, 5)`).
- **FieldSetupIntegration:** Verifies field setup with ownership integration. Passed (correct `owner` values).

### 6. Performance (2 tests)
- **BasicSetupSpeed:** Verifies field setup speed with 6 units. Passed (< 1000 ms).
- **DisplaySpeed:** Verifies field display speed. Passed (< 1000 ms).

### 7. Army (4 tests)
- **MightCalculation:** Verifies army might calculation. Passed (`currentMight = 625`).
- **MaxMight:** Verifies maximum might setting. Passed (`maxMight = 1000`).
- **TroopAssignment:** Verifies troop assignment. Passed.
- **HeroAssignment:** Verifies hero assignment. Passed.

### 8. Catalog (5 tests)
- **HeroTemplates:** Verifies hero templates. Passed (3 heroes with correct parameters).
- **HeroSpells:** Verifies hero spells. Passed.
- **TroopTemplates:** Verifies troop templates. Passed (15 troops).
- **TroopStats:** Verifies troop stats. Passed.
- **DefaultInitialization:** Verifies catalog initialization. Passed.

### 9. Action (1 test)
- **MoveInvalidStamina:** Verifies inability to move without stamina. Passed (position unchanged).

### 10. AI (4 tests)
- **ArmySetup:** Verifies AI army setup. Passed (`currentMight = 5685`, 6 troops).
- **MoveToEnemy:** Verifies AI movement toward an enemy. Passed (moved to `(2, 3)`, attacked).
- **SkipNoTargets:** Verifies turn skip with no enemies. Passed (`hasAttacked = true` due to skip behavior).
- **NameDefault:** Verifies AI name. Passed (`name = "AI Bot"`).

### 11. TerminalUI (6 tests)
- **InputValidationOneOfThree:** Verifies input validation for 1-3 range. Passed.
- **InputValidationGetName:** Verifies name input validation. Passed.
- **InputValidationTroops:** Verifies troop selection validation (1-15). Passed.
- **InputValidationAmount:** Verifies amount validation (1-99). Passed.
- **TroopSelectionWithinMight:** Verifies troop selection within might limit. Passed.
- **TroopSelectionNoMightLeft:** Verifies selection with insufficient might. Passed.

## Conclusion
All 45 tests across 11 test suites were successfully passed. The system demonstrates correct functionality for unit mechanics, hero management, spell and effect handling, army operations, catalog initialization, action execution, battle management, AI behavior, and terminal interface input processing. Performance tests confirm that field setup and display operations complete within acceptable time limits (< 1000 ms).
