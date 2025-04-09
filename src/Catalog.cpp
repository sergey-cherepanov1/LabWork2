/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Catalog.h"
#include <iostream>

/**
 * @brief Default constructor for Catalog.
 */
Catalog::Catalog()
{
    std::array<Spell, 3> spells1
    {
        Spell("Fireball", 10, Effect(EffectType::HEALTH, -20, 0, false), "Deals instant damage."),
        Spell("Heal", 8, Effect(EffectType::HEALTH, 15, 0, false), "Restores health instantly."),
        Spell("Boost", 5, Effect(EffectType::ATTACK, 5, 3, false), "Increases attack for 3 turns.")
    };
    _hero_templates.push_back(Hero("Arion", 500, 30, spells1, "A fiery mage with destructive spells."));

    std::array<Spell, 3> spells2
    {
        Spell("Poison", 6, Effect(EffectType::HEALTH, -5, 3, true), "Deals damage each turn for 3 turns."),
        Spell("Shield", 7, Effect(EffectType::HEALTH, 10, 2, false), "Increases health for 2 turns."),
        Spell("Drain", 9, Effect(EffectType::STAMINA, -2, 2, true), "Reduces enemy stamina each turn.")
    };
    _hero_templates.push_back(Hero("Liora", 400, 25, spells2, "A cunning sorceress with subtle magic."));

    std::array<Spell, 3> spells3
    {
        Spell("Thunder", 12, Effect(EffectType::HEALTH, -25, 0, false), "Strikes with powerful lightning."),
        Spell("Regen", 10, Effect(EffectType::HEALTH, 5, 3, true), "Restores health each turn for 3 turns."),
        Spell("Haste", 8, Effect(EffectType::STAMINA, 2, 2, false), "Increases stamina for 2 turns.")
    };
    _hero_templates.push_back(Hero("Tharok", 600, 20, spells3, "A mighty warrior with storm magic."));

    _troop_templates.push_back(std::make_shared<Troop>("Peasant", 1, 5, 2, 2, 2, 2, std::vector<Effect>(), "Simple folk with pitchforks."));
    _troop_templates.push_back(std::make_shared<Troop>("Archer", 1, 7, 5, 2, 3, 5, std::vector<Effect>(), "Ranged fighters with bows."));
    _troop_templates.push_back(std::make_shared<Troop>("Swordsman", 1, 10, 7, 3, 4, 10, std::vector<Effect>(), "Skilled melee warriors."));
    _troop_templates.push_back(std::make_shared<Troop>("Cavalry", 1, 15, 10, 4, 6, 20, std::vector<Effect>(), "Fast mounted units."));
    _troop_templates.push_back(std::make_shared<Troop>("Mage", 1, 8, 12, 2, 2, 15, std::vector<Effect>(), "Spellcasters with arcane power."));
    _troop_templates.push_back(std::make_shared<Troop>("Knight", 1, 20, 15, 3, 5, 25, std::vector<Effect>(), "Heavily armored elite fighters."));
    _troop_templates.push_back(std::make_shared<Troop>("Spearman", 1, 12, 8, 3, 4, 12, std::vector<Effect>(), "Polearm wielders."));
    _troop_templates.push_back(std::make_shared<Troop>("Assassin", 1, 6, 14, 2, 7, 18, std::vector<Effect>(), "Stealthy and deadly."));
    _troop_templates.push_back(std::make_shared<Troop>("Cleric", 1, 10, 4, 2, 3, 10, std::vector<Effect>(), "Healers with minor combat ability."));
    _troop_templates.push_back(std::make_shared<Troop>("Berserker", 1, 15, 18, 3, 6, 22, std::vector<Effect>(), "Fierce and reckless warriors."));
    _troop_templates.push_back(std::make_shared<Troop>("Golem", 1, 25, 10, 2, 1, 30, std::vector<Effect>(), "Slow but durable constructs."));
    _troop_templates.push_back(std::make_shared<Troop>("Ranger", 1, 9, 8, 3, 5, 14, std::vector<Effect>(), "Versatile wilderness fighters."));
    _troop_templates.push_back(std::make_shared<Troop>("Paladin", 1, 18, 12, 3, 4, 28, std::vector<Effect>(), "Holy warriors with balanced stats."));
    _troop_templates.push_back(std::make_shared<Troop>("Dragon", 1, 30, 25, 4, 3, 50, std::vector<Effect>(), "Majestic and powerful beasts."));
    _troop_templates.push_back(std::make_shared<Troop>("Necromancer", 1, 12, 10, 2, 2, 20, std::vector<Effect>(), "Masters of dark magic."));
}

/**
 * @brief Gets the vector of hero templates.
 */
std::vector<Hero>& Catalog::getHeroTemplates()
{
    return _hero_templates;
}

/**
 * @brief Gets the vector of troop templates.
 */
std::vector<std::shared_ptr<Troop>>& Catalog::getTroopTemplates()
{
    return _troop_templates;
}
