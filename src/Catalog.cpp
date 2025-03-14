/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Catalog.h"

Catalog::Catalog()
{
    _hero_templates =
    {
        Hero("Roland", 150, 50,
        {
            Spell("Magic Arrow", 4, Effect(EffectType::HEALTH, -10, 0), "Deals 10 magical damage to the enemy."),
            Spell("Bless", 6, Effect(EffectType::ATTACK, 2, 2), "Increases the attack of an allied unit by 2 for 2 turns."),
            Spell("Cure", 5, Effect(EffectType::HEALTH, 8, 0), "Restores 8 health to an allied unit.")
        },
        "King of the Castle, specializes in archers and light magic."),
        Hero("Gelu", 120, 40,
        {
            Spell("Fire Arrow", 5, Effect(EffectType::HEALTH, -12, 0), "Deals fire damage to an enemy."),
            Spell("Regeneration", 7, Effect(EffectType::HEALTH, 5, 2), "Restores 5 health to an allied unit every turn for 2 turns."),
            Spell("Sharpshooter", 4, Effect(EffectType::ATTACK, 1, 2), "Increases the attack of an allied unit by 1 for 2 turns.")
        },
        "Leader of Rampart, master of ranged attacks and nature."),
        Hero("Xeron", 170, 60,
        {
            Spell("Fireball", 8, Effect(EffectType::HEALTH, -15, 0), "Deals fire damage to a group of enemies."),
            Spell("Curse", 5, Effect(EffectType::ATTACK, -1, 2), "Reduces the attack of an enemy unit by 1 for 2 turns."),
            Spell("Haste", 6, Effect(EffectType::STAMINA, 2, 2), "Increases allied unit's stamina by 2 for 2 turns.")
        },
        "Leader of Inferno, master of dark magic and destruction.")
    };


    _troop_templates.push_back(std::make_unique<Troop>("Pikeman", 1, 10, 3, 10, 10, 5, 2, std::vector<Effect>(), "Basic infantry unit with high defense."));
    _troop_templates.push_back(std::make_unique<Troop>("Archer", 1, 10, 4, 10, 10, 6, 5, std::vector<Effect>(), "Ranged unit with moderate damage and speed."));
    _troop_templates.push_back(std::make_unique<Troop>("Griffin", 1, 25, 6, 15, 15, 8, 8, std::vector<Effect>(), "Flying unit with strong attack and defense."));

    _troop_templates.push_back(std::make_unique<Troop>("Centaur", 1, 8, 3, 8, 8, 7, 3, std::vector<Effect>(), "Fast skirmisher with low health."));
    _troop_templates.push_back(std::make_unique<Troop>("Dwarf", 1, 20, 4, 12, 12, 4, 7, std::vector<Effect>(), "Sturdy unit with high defense."));
    _troop_templates.push_back(std::make_unique<Troop>("Unicorn", 1, 30, 7, 15, 15, 7, 10, std::vector<Effect>(), "Magical unit with strong attack and speed."));

    _troop_templates.push_back(std::make_unique<Troop>("Gog", 1, 6, 3, 8, 8, 6, 2, std::vector<Effect>(), "Weak fire-based unit with low health."));
    _troop_templates.push_back(std::make_unique<Troop>("Hell Hound", 1, 15, 5, 12, 12, 9, 5, std::vector<Effect>(), "Fast unit with moderate attack."));
    _troop_templates.push_back(std::make_unique<Troop>("Demon", 1, 40, 9, 20, 20, 6, 15, std::vector<Effect>(), "Powerful demon unit with high health and attack."));

    _troop_templates.push_back(std::make_unique<Troop>("Gremlin", 1, 4, 2, 6, 6, 5, 1, std::vector<Effect>(), "Weak unit with low stats."));
    _troop_templates.push_back(std::make_unique<Troop>("Stone Golem", 1, 30, 5, 15, 15, 3, 6, std::vector<Effect>(), "Durable unit with high defense."));
    _troop_templates.push_back(std::make_unique<Troop>("Mage", 1, 12, 6, 10, 10, 6, 4, std::vector<Effect>(), "Ranged magical unit with moderate health."));

    _troop_templates.push_back(std::make_unique<Troop>("Skeleton", 1, 6, 2, 8, 8, 5, 2, std::vector<Effect>(), "Weak undead unit with low stats."));
    _troop_templates.push_back(std::make_unique<Troop>("Zombie", 1, 15, 3, 12, 12, 4, 3, std::vector<Effect>(), "Slow unit with moderate health."));
    _troop_templates.push_back(std::make_unique<Troop>("Vampire", 1, 30, 7, 15, 15, 7, 12, std::vector<Effect>(), "Powerful undead unit with regeneration potential."));

}

std::vector<Hero>& Catalog::getHeroTemplates()
{
    return _hero_templates;
}

std::vector<std::shared_ptr<Troop>>& Catalog::getTroopTemplates()
{
    return _troop_templates;
}
