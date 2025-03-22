/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/
#include <gtest/gtest.h>
#include <memory>
#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include "../src/Troop.h"
#include "../src/Hero.h"
#include "../src/Spell.h"
#include "../src/Effect.h"
#include "../src/Army.h"
#include "../src/Catalog.h"
#include "../src/Action.h"
#include "../src/BattleManager.h"
#include "../src/AI.h"
#include "../src/TerminalUI.h"
#include "../src/GameManager.h"
#include "../src/Player.h"

TEST(Troop, AttackDamage)
{
    Troop attacker("Soldier", 10, 10, 5, 3, 5, 10, std::vector<Effect>(), "Test troop");
    auto target = std::make_shared<Troop>("Enemy", 10, 10, 3, 2, 3, 10, std::vector<Effect>(), "Target");
    attacker.attack(target);
    EXPECT_EQ(target->getTotalHealth(), 50); // 100 - (5 * 10)
    EXPECT_EQ(target->getAmount(), 5);       // 50 / 10
}

TEST(Troop, EffectApplication)
{
    Troop troop("Soldier", 10, 10, 5, 3, 5, 10, std::vector<Effect>(), "Test troop");
    Effect effect(EffectType::HEALTH, -5, 2, true);
    troop.addEffect(effect);
    troop.applyEffects();
    EXPECT_EQ(troop.getTotalHealth(), 95);
    EXPECT_EQ(troop.getEffects()[0].getDuration(), 1);
    troop.applyEffects();
    EXPECT_EQ(troop.getTotalHealth(), 90);
    EXPECT_EQ(troop.getEffects().size(), 0); // Effect expires
}

TEST(Troop, StaminaLimits)
{
    Troop troop("Soldier", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "Test troop");
    troop.setCurrentStamina(2);
    troop.setPosition(0, 0);
    troop.setCurrentStamina(troop.getCurrentStamina() - 2); // Simulate move
    EXPECT_EQ(troop.getCurrentStamina(), 0);
    EXPECT_FALSE(troop.getCurrentStamina() > 0); // Cannot move again
}

TEST(Troop, TotalMight)
{
    Troop troop("Soldier", 10, 10, 5, 3, 5, 10, std::vector<Effect>(), "Test troop");
    EXPECT_EQ(troop.getTotalMight(), 100); // 10 * 10
}

TEST(Hero, ManaReduction)
{
    std::array<Spell, 3> spells =
    {
        Spell("Fireball", 10, Effect(EffectType::HEALTH, -20, 0, false), "Damage"),
        Spell("Heal", 8, Effect(EffectType::HEALTH, 15, 0, false), "Heal"),
        Spell("Boost", 5, Effect(EffectType::ATTACK, 5, 3, false), "Boost")
    };
    Hero hero("TestHero", 500, 20, spells, "Test hero");
    hero.setMana(20 - spells[0].getCost()); // Simulate casting Fireball
    EXPECT_EQ(hero.getMana(), 10);
}

TEST(Hero, SpellAccess)
{
    std::array<Spell, 3> spells =
    {
        Spell("Fireball", 10, Effect(EffectType::HEALTH, -20, 0, false), "Damage"),
        Spell("Heal", 8, Effect(EffectType::HEALTH, 15, 0, false), "Heal"),
        Spell("Boost", 5, Effect(EffectType::ATTACK, 5, 3, false), "Boost")
    };
    Hero hero("TestHero", 500, 20, spells, "Test hero");
    auto& heroSpells = hero.getSpells();
    EXPECT_EQ(heroSpells.size(), 3);
    EXPECT_EQ(heroSpells[0].getName(), "Fireball");
    EXPECT_EQ(heroSpells[1].getName(), "Heal");
    EXPECT_EQ(heroSpells[2].getName(), "Boost");
}

TEST(Hero, InitialMana)
{
    std::array<Spell, 3> spells =
    {
        Spell("Fireball", 10, Effect(EffectType::HEALTH, -20, 0, false), "Damage"),
        Spell("Heal", 8, Effect(EffectType::HEALTH, 15, 0, false), "Heal"),
        Spell("Boost", 5, Effect(EffectType::ATTACK, 5, 3, false), "Boost")
    };
    Hero hero("TestHero", 500, 20, spells, "Test hero");
    EXPECT_EQ(hero.getMana(), 20);
}

TEST(Hero, MightValue)
{
    std::array<Spell, 3> spells =
    {
        Spell("Fireball", 10, Effect(EffectType::HEALTH, -20, 0, false), "Damage"),
        Spell("Heal", 8, Effect(EffectType::HEALTH, 15, 0, false), "Heal"),
        Spell("Boost", 5, Effect(EffectType::ATTACK, 5, 3, false), "Boost")
    };
    Hero hero("TestHero", 500, 20, spells, "Test hero");
    EXPECT_EQ(hero.getMight(), 500);
}

TEST(Hero, NameAndDescription)
{
    std::array<Spell, 3> spells =
    {
        Spell("Fireball", 10, Effect(EffectType::HEALTH, -20, 0, false), "Damage"),
        Spell("Heal", 8, Effect(EffectType::HEALTH, 15, 0, false), "Heal"),
        Spell("Boost", 5, Effect(EffectType::ATTACK, 5, 3, false), "Boost")
    };
    Hero hero("TestHero", 500, 20, spells, "Test hero description");
    EXPECT_EQ(hero.getName(), "TestHero");
    EXPECT_EQ(hero.getDescription(), "Test hero description");
}

TEST(Spell, EffectRetrieval)
{
    Effect effect(EffectType::HEALTH, -20, 0, false);
    Spell spell("Fireball", 10, effect, "Deals instant damage");
    Effect retrievedEffect = spell.getEffect();
    EXPECT_EQ(retrievedEffect.getType(), EffectType::HEALTH);
    EXPECT_EQ(retrievedEffect.getValue(), -20);
    EXPECT_EQ(retrievedEffect.getDuration(), 0);
    EXPECT_FALSE(retrievedEffect.applyEachTurn());
}

TEST(Spell, CostValidation)
{
    Effect effect(EffectType::HEALTH, -20, 0, false);
    Spell spell("Fireball", 10, effect, "Deals instant damage");
    EXPECT_EQ(spell.getCost(), 10);
}

TEST(Spell, NameValidation)
{
    Effect effect(EffectType::HEALTH, -20, 0, false);
    Spell spell("Fireball", 10, effect, "Deals instant damage");
    EXPECT_EQ(spell.getName(), "Fireball");
}

TEST(Spell, DescriptionValidation)
{
    Effect effect(EffectType::HEALTH, -20, 0, false);
    Spell spell("Fireball", 10, effect, "Deals instant damage");
    EXPECT_EQ(spell.getDescription(), "Deals instant damage");
}

TEST(Spell, DefaultConstructor)
{
    Spell spell;
    EXPECT_EQ(spell.getName(), "Default Spell");
    EXPECT_EQ(spell.getCost(), 0);
    EXPECT_EQ(spell.getEffect().getType(), EffectType::HEALTH);
    EXPECT_EQ(spell.getEffect().getValue(), 0);
    EXPECT_EQ(spell.getDescription(), "");
}

TEST(Effect, DurationDecrease)
{
    Effect effect(EffectType::HEALTH, -5, 3, true);
    effect.decreaseDuration();
    EXPECT_EQ(effect.getDuration(), 2);
    effect.decreaseDuration();
    EXPECT_EQ(effect.getDuration(), 1);
    effect.decreaseDuration();
    EXPECT_EQ(effect.getDuration(), 0);
}

TEST(BattleManager, Initialization) {
    BattleManager bm;
    auto t1 = std::make_shared<Troop>("Soldier", 1, 10, 5, 2, 10, 10, std::vector<Effect>(), "Player troop");
    bm.getPlayer1().getArmy().setTroop(0, t1);
    bm.fillTheField();
    std::cout << "After fillTheField: t1 at (" << t1->getX() << ", " << t1->getY() << ")\n"; // Debug position
    EXPECT_EQ(t1->getX(), 0);
    EXPECT_EQ(t1->getY(), 0);
}

TEST(BattleManager, QueueSetup) {
    BattleManager bm;
    auto t1 = std::make_shared<Troop>("Fast", 1, 10, 5, 2, 10, 10, std::vector<Effect>(), "Player fast");
    auto t2 = std::make_shared<Troop>("Slow", 1, 10, 5, 2, 5, 5, std::vector<Effect>(), "AI slow");
    bm.getPlayer1().getArmy().setTroop(0, t1);
    bm.getAI().getArmy().setTroop(0, t2);
    bm.fillTheField();
    std::cout << "After fillTheField: t1 at (" << t1->getX() << ", " << t1->getY() << "), t2 at (" << t2->getX() << ", " << t2->getY() << ")\n";
    bm.makeQueue();
    EXPECT_EQ(bm.getQueue().size(), 2);
}

TEST(Performance, BasicSetupSpeed) {
    BattleManager bm;
    auto t1 = std::make_shared<Troop>("Soldier", 1, 10, 5, 2, 5, 5, std::vector<Effect>(), "Player troop");
    auto t2 = std::make_shared<Troop>("Enemy", 1, 10, 5, 2, 5, 5, std::vector<Effect>(), "AI troop");
    auto t3 = std::make_shared<Troop>("Soldier2", 1, 10, 5, 2, 5, 5, std::vector<Effect>(), "Player troop");
    auto t4 = std::make_shared<Troop>("Enemy2", 1, 10, 5, 2, 5, 5, std::vector<Effect>(), "AI troop");
    auto t5 = std::make_shared<Troop>("Soldier3", 1, 10, 5, 2, 5, 5, std::vector<Effect>(), "Player troop");
    auto t6 = std::make_shared<Troop>("Enemy3", 1, 10, 5, 2, 5, 5, std::vector<Effect>(), "AI troop");
    bm.getPlayer1().getArmy().setTroop(0, t1);
    bm.getPlayer1().getArmy().setTroop(1, t3);
    bm.getPlayer1().getArmy().setTroop(2, t5);
    bm.getAI().getArmy().setTroop(0, t2);
    bm.getAI().getArmy().setTroop(1, t4);
    bm.getAI().getArmy().setTroop(2, t6);
    
    auto start = std::chrono::high_resolution_clock::now();
    bm.fillTheField();
    bm.makeQueue();
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "After fillTheField: t1 at (" << t1->getX() << ", " << t1->getY() << ")\n";
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    EXPECT_LT(duration, 1000);
}

TEST(Effect, ApplyEachTurn)
{
    Effect effect(EffectType::HEALTH, -5, 2, true);
    EXPECT_TRUE(effect.applyEachTurn());
    Effect instantEffect(EffectType::ATTACK, 5, 3, false);
    EXPECT_FALSE(instantEffect.applyEachTurn());
}

TEST(Effect, ValueRetrieval)
{
    Effect effect(EffectType::HEALTH, -5, 2, true);
    EXPECT_EQ(effect.getValue(), -5);
    Effect positiveEffect(EffectType::STAMINA, 2, 1, false);
    EXPECT_EQ(positiveEffect.getValue(), 2);
}

TEST(Effect, TypeRetrieval)
{
    Effect healthEffect(EffectType::HEALTH, -5, 2, true);
    EXPECT_EQ(healthEffect.getType(), EffectType::HEALTH);
    Effect attackEffect(EffectType::ATTACK, 5, 3, false);
    EXPECT_EQ(attackEffect.getType(), EffectType::ATTACK);
    Effect staminaEffect(EffectType::STAMINA, -2, 2, true);
    EXPECT_EQ(staminaEffect.getType(), EffectType::STAMINA);
}

TEST(Effect, DefaultConstructor)
{
    Effect effect;
    EXPECT_EQ(effect.getType(), EffectType::HEALTH);
    EXPECT_EQ(effect.getValue(), 0);
    EXPECT_EQ(effect.getDuration(), 0);
    EXPECT_FALSE(effect.applyEachTurn());
}

TEST(Army, MightCalculation)
{
    Army army;
    Hero hero("TestHero", 500, 20, {}, "Test hero");
    army.setHero(hero);
    auto troop1 = std::make_shared<Troop>("Soldier", 10, 10, 5, 3, 5, 10, std::vector<Effect>(), "Test troop");
    auto troop2 = std::make_shared<Troop>("Archer", 5, 7, 5, 2, 3, 5, std::vector<Effect>(), "Test troop");
    army.setTroop(0, troop1);
    army.setTroop(1, troop2);
    army.updateCurrentMight();
    EXPECT_EQ(army.getCurrentMight(), 625); // 500 (hero) + 100 (10*10) + 25 (5*5)
}

TEST(Army, MaxMight)
{
    Army army;
    army.setMaxMight(1000);
    EXPECT_EQ(army.getMaxMight(), 1000);
}

TEST(Army, TroopAssignment)
{
    Army army;
    auto troop = std::make_shared<Troop>("Soldier", 1, 10, 5, 3, 5, 10, std::vector<Effect>(), "Test troop");
    army.setTroop(2, troop);
    EXPECT_EQ(army.getTroops()[2]->getName(), "Soldier");
    EXPECT_EQ(army.getTroops()[0], nullptr); // Other slots remain empty
}

TEST(Army, HeroAssignment)
{
    Army army;
    Hero hero("TestHero", 500, 20, {}, "Test hero");
    army.setHero(hero);
    EXPECT_EQ(army.getHero().getName(), "TestHero");
    EXPECT_EQ(army.getHero().getMight(), 500);
}

TEST(Catalog, HeroTemplates)
{
    Catalog catalog;
    auto& heroes = catalog.getHeroTemplates();
    EXPECT_EQ(heroes.size(), 3); // 3 heroes in catalog
    EXPECT_EQ(heroes[0].getName(), "Arion");
    EXPECT_EQ(heroes[0].getMight(), 500);
    EXPECT_EQ(heroes[0].getMana(), 30);
    EXPECT_EQ(heroes[1].getName(), "Liora");
    EXPECT_EQ(heroes[1].getMight(), 400);
    EXPECT_EQ(heroes[1].getMana(), 25);
    EXPECT_EQ(heroes[2].getName(), "Tharok");
    EXPECT_EQ(heroes[2].getMight(), 600);
    EXPECT_EQ(heroes[2].getMana(), 20);
}

TEST(Catalog, HeroSpells)
{
    Catalog catalog;
    auto& heroes = catalog.getHeroTemplates();
    auto& spells1 = heroes[0].getSpells();
    EXPECT_EQ(spells1[0].getName(), "Fireball");
    EXPECT_EQ(spells1[1].getName(), "Heal");
    EXPECT_EQ(spells1[2].getName(), "Boost");
    auto& spells2 = heroes[1].getSpells();
    EXPECT_EQ(spells2[0].getName(), "Poison");
    EXPECT_EQ(spells2[1].getName(), "Shield");
    EXPECT_EQ(spells2[2].getName(), "Drain");
    auto& spells3 = heroes[2].getSpells();
    EXPECT_EQ(spells3[0].getName(), "Thunder");
    EXPECT_EQ(spells3[1].getName(), "Regen");
    EXPECT_EQ(spells3[2].getName(), "Haste");
}

TEST(Catalog, TroopTemplates)
{
    Catalog catalog;
    auto& troops = catalog.getTroopTemplates();
    EXPECT_EQ(troops.size(), 15); // 15 troops in catalog
    EXPECT_EQ(troops[0]->getName(), "Peasant");
    EXPECT_EQ(troops[0]->getMight(), 2);
    EXPECT_EQ(troops[1]->getName(), "Archer");
    EXPECT_EQ(troops[1]->getMight(), 5);
    EXPECT_EQ(troops[14]->getName(), "Necromancer");
    EXPECT_EQ(troops[14]->getMight(), 20);
}

TEST(Catalog, TroopStats)
{
    Catalog catalog;
    auto& troops = catalog.getTroopTemplates();
    EXPECT_EQ(troops[0]->getHealth(), 5);   // Peasant
    EXPECT_EQ(troops[0]->getAttack(), 2);
    EXPECT_EQ(troops[0]->getMaxStamina(), 2);
    EXPECT_EQ(troops[0]->getInitiative(), 2);
    EXPECT_EQ(troops[13]->getHealth(), 30); // Dragon
    EXPECT_EQ(troops[13]->getAttack(), 25);
    EXPECT_EQ(troops[13]->getMaxStamina(), 4);
    EXPECT_EQ(troops[13]->getInitiative(), 3);
}

TEST(Catalog, DefaultInitialization)
{
    Catalog catalog;
    EXPECT_GE(catalog.getHeroTemplates().size(), 1);
    EXPECT_GE(catalog.getTroopTemplates().size(), 1);
}



TEST(Action, MoveInvalidStamina) {
    std::array<std::array<std::shared_ptr<Troop>, 6>, 6> field{};
    auto troop = std::make_shared<Troop>("Soldier", 1, 10, 5, 0, 5, 10, std::vector<Effect>(), "Test troop");
    field[0][0] = troop;
    troop->setPosition(0, 0);
    Player p1, p2;
    AI ai;
    Action action(field, p1, p2, ai);
    std::stringstream input("1\n1\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    int result = action.move(troop);
    std::cin.rdbuf(oldCin);
    EXPECT_EQ(result, 1); // Fails due to no stamina
    EXPECT_EQ(troop->getX(), 0);
    EXPECT_EQ(troop->getY(), 0);
}

TEST(AI, ArmySetup)
{
    AI ai;
    Catalog catalog;
    ai.setupArmy(catalog);
    EXPECT_EQ(ai.getArmy().getCurrentMight(), 5685); // Fixed might for AI army
    EXPECT_EQ(ai.getArmy().getTroops().size(), 6);   // 6 troops
    EXPECT_EQ(ai.getArmy().getTroops()[0]->getName(), "Archer");
    EXPECT_EQ(ai.getArmy().getTroops()[0]->getAmount(), 99);
    EXPECT_EQ(ai.getArmy().getTroops()[5]->getName(), "Necromancer");
    EXPECT_EQ(ai.getArmy().getTroops()[5]->getAmount(), 37);
    EXPECT_EQ(ai.getArmy().getHero().getName(), "Liora");
}

TEST(AI, MoveToEnemy) {
    std::array<std::array<std::shared_ptr<Troop>, 6>, 6> field{};
    auto aiTroop = std::make_shared<Troop>("Soldier", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "AI troop");
    auto enemy = std::make_shared<Troop>("Enemy", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "Enemy");
    aiTroop->setOwner();
    aiTroop->setPosition(0, 5);
    enemy->setPosition(2, 0);
    field[0][5] = aiTroop;
    field[2][0] = enemy;
    Player p1, p2;
    AI ai;
    Action action(field, p1, p2, ai);
    bool battleStatus = true;
    ai.makeTurn(aiTroop, field, action, battleStatus);
    std::cout << "Final position: (" << aiTroop->getX() << ", " << aiTroop->getY() << ")\n";
    EXPECT_EQ(aiTroop->getX(), 2);
    EXPECT_EQ(aiTroop->getY(), 3);
    EXPECT_EQ(aiTroop->getCurrentStamina(), 0);
    EXPECT_TRUE(aiTroop->hasAttacked());
}

TEST(AI, SkipNoTargets) {
    std::array<std::array<std::shared_ptr<Troop>, 6>, 6> field{};
    auto aiTroop = std::make_shared<Troop>("Soldier", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "AI troop");
    aiTroop->setOwner();
    aiTroop->setPosition(0, 0); 
    field[0][0] = aiTroop;
    Player p1, p2;
    AI ai;
    Action action(field, p1, p2, ai);
    bool battleStatus = true;
    ai.makeTurn(aiTroop, field, action, battleStatus);
    EXPECT_TRUE(aiTroop->hasAttacked());
    EXPECT_EQ(aiTroop->getCurrentStamina(), 0);
}

TEST(AI, NameDefault)
{
    AI ai;
    EXPECT_EQ(ai.getName(), "AI Bot");
}

TEST(TerminalUI, InputValidationOneOfThree)
{
    TerminalUI ui;
    std::stringstream input("4\n1\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::string result = ui.handleInput(InputState::ONE_OF_THREE);
    std::cin.rdbuf(oldCin);
    EXPECT_EQ(result, "1"); // Rejects "4", accepts "1"
}

TEST(TerminalUI, InputValidationGetName)
{
    TerminalUI ui;
    std::stringstream input("\nTestName\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::string result = ui.handleInput(InputState::GET_NAME);
    std::cin.rdbuf(oldCin);
    EXPECT_EQ(result, "TestName"); // Rejects empty input, accepts valid name
}

TEST(TerminalUI, InputValidationTroops)
{
    TerminalUI ui;
    std::stringstream input("16\n5\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::string result = ui.handleInput(InputState::TROOPS);
    std::cin.rdbuf(oldCin);
    EXPECT_EQ(result, "5"); // Rejects "16" (out of 1-15), accepts "5"
}

TEST(TerminalUI, InputValidationAmount)
{
    TerminalUI ui;
    std::stringstream input("100\n50\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::string result = ui.handleInput(InputState::AMOUNT);
    std::cin.rdbuf(oldCin);
    EXPECT_EQ(result, "50"); // Rejects "100" (out of 1-99), accepts "50"
}

TEST(TerminalUI, TroopSelectionWithinMight)
{
    TerminalUI ui;
    std::stringstream input("1\n10\n"); // Troop 1 (Peasant, might=2), amount=10
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    bool shouldEnd = false;
    auto troop = ui.selectTroop(50, shouldEnd);
    std::cin.rdbuf(oldCin);
    EXPECT_EQ(troop->getName(), "Peasant");
    EXPECT_EQ(troop->getAmount(), 10);
    EXPECT_EQ(troop->getTotalMight(), 20); // 2 * 10
    EXPECT_FALSE(shouldEnd);
}

TEST(TerminalUI, TroopSelectionNoMightLeft)
{
    TerminalUI ui;
    std::stringstream input("1\n1\n"); // Troop 1 (Peasant, might=2)
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    bool shouldEnd = false;
    auto troop = ui.selectTroop(1, shouldEnd); // Only 1 might available
    std::cin.rdbuf(oldCin);
    EXPECT_EQ(troop, nullptr); // No troop fits within 1 might
    EXPECT_TRUE(shouldEnd);
}

TEST(BattleManager, FieldSetup)
{
    BattleManager bm;
    auto t1 = std::make_shared<Troop>("Soldier", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "Player troop");
    auto t2 = std::make_shared<Troop>("Enemy", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "AI troop");
    bm.getPlayer1().getArmy().setTroop(0, t1);
    bm.getAI().getArmy().setTroop(0, t2);
    bm.fillTheField();
    EXPECT_EQ(bm.getField()[0][0], t1);  // Player troop at y=0
    EXPECT_EQ(t1->getX(), 0);
    EXPECT_EQ(t1->getY(), 0);
    EXPECT_EQ(bm.getField()[0][5], t2);  // AI troop at y=5
    EXPECT_EQ(t2->getX(), 0);
    EXPECT_EQ(t2->getY(), 5);
}

TEST(BattleManager, FieldSetupIntegration) {
    BattleManager bm;
    auto t1 = std::make_shared<Troop>("Soldier", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "Player troop");
    auto t2 = std::make_shared<Troop>("Enemy", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "AI troop");
    bm.getPlayer1().getArmy().setTroop(0, t1);
    bm.getAI().getArmy().setTroop(0, t2);
    t2->setOwner();
    bm.fillTheField();
    std::cout << "t1 at (" << t1->getX() << ", " << t1->getY() << "), owner: " << t1->getOwner() << "\n";
    std::cout << "t2 at (" << t2->getX() << ", " << t2->getY() << "), owner: " << t2->getOwner() << "\n";
    EXPECT_EQ(bm.getField()[0][0], t1);
    EXPECT_EQ(bm.getField()[0][5], t2);
    EXPECT_EQ(t1->getOwner(), false);
    EXPECT_EQ(t2->getOwner(), true);
}

TEST(Performance, DisplaySpeed)
{
    BattleManager bm;
    auto t1 = std::make_shared<Troop>("Soldier", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "Player troop");
    auto t2 = std::make_shared<Troop>("Enemy", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "AI troop");
    auto t3 = std::make_shared<Troop>("Soldier2", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "Player troop");
    auto t4 = std::make_shared<Troop>("Enemy2", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "AI troop");
    auto t5 = std::make_shared<Troop>("Soldier3", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "Player troop");
    auto t6 = std::make_shared<Troop>("Enemy3", 1, 10, 5, 2, 5, 10, std::vector<Effect>(), "AI troop");
    bm.getPlayer1().getArmy().setTroop(0, t1);
    bm.getPlayer1().getArmy().setTroop(1, t3);
    bm.getPlayer1().getArmy().setTroop(2, t5);
    bm.getAI().getArmy().setTroop(0, t2);
    bm.getAI().getArmy().setTroop(1, t4);
    bm.getAI().getArmy().setTroop(2, t6);
    bm.fillTheField();

    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    auto start = std::chrono::high_resolution_clock::now();
    bm.displayField();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout.rdbuf(oldCout);

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    EXPECT_LT(duration, 1000); // Less than 1 second
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
