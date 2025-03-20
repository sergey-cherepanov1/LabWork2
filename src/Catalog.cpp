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
            Spell("Magic Arrow", 5, Effect(EffectType::HEALTH, -150, 0, false), "Deals 150 magical damage to the enemy."),
            Spell("Bless", 8, Effect(EffectType::ATTACK, 3, 3, false),"Increases the attack of an allied unit by 3 for 3 turns."),
            Spell("Cure", 6, Effect(EffectType::HEALTH, 120, 0, false), "Restores 120 health to an allied unit.")
        },"King of the Castle, specializes in archers and light magic."),

        Hero("Gelu", 120, 40,
        {
            Spell("Fire Arrow", 6, Effect(EffectType::HEALTH, -180, 0, false), "Deals 180 fire damage to an enemy."),
            Spell("Regeneration", 8, Effect(EffectType::HEALTH, 60, 3, true), "Restores 60 health to an allied unit every turn for 3 turns."),
            Spell("Sharpshooter", 5, Effect(EffectType::ATTACK, 2, 3, false), "Increases the attack of an allied unit by 2 for 3 turns.")
        }, "Leader of Rampart, master of ranged attacks and nature."),

        Hero("Xeron", 170, 60,
        {
            Spell("Fireball", 10, Effect(EffectType::HEALTH, -240, 0, false), "Deals 240 fire damage to a group of enemies."),
            Spell("Curse", 6, Effect(EffectType::ATTACK, -2, 3, false), "Reduces the attack of an enemy unit by 2 for 3 turns."),
            Spell("Haste", 7, Effect(EffectType::STAMINA, 3, 3, false), "Increases allied unit's stamina by 3 for 3 turns.")
        }, "Leader of Inferno, master of dark magic and destruction.")
    };


    _troop_templates.push_back(std::make_unique<Troop>("Pikeman", 2, 10, 1, 4, 3, 10, std::vector<Effect>(), "Basic infantry unit with high defense."));
    _troop_templates.push_back(std::make_unique<Troop>("Archer", 5, 10, 1, 5, 4, 10, std::vector<Effect>(), "Ranged unit with moderate damage and speed."));
    _troop_templates.push_back(std::make_unique<Troop>("Griffin", 8, 25, 1, 7, 6, 15, std::vector<Effect>(), "Flying unit with strong attack and defense."));

    _troop_templates.push_back(std::make_unique<Troop>("Centaur", 3, 8, 1, 6, 3, 8, std::vector<Effect>(), "Fast skirmisher with low health."));
    _troop_templates.push_back(std::make_unique<Troop>("Dwarf", 7, 20, 1, 3, 4, 12, std::vector<Effect>(), "Sturdy unit with high defense."));
    _troop_templates.push_back(std::make_unique<Troop>("Unicorn", 10, 30, 1, 7, 7, 15, std::vector<Effect>(), "Magical unit with strong attack and speed."));

    _troop_templates.push_back(std::make_unique<Troop>("Gog", 2, 6, 1, 4, 3, 8, std::vector<Effect>(), "Weak fire-based unit with low health."));
    _troop_templates.push_back(std::make_unique<Troop>("Hell Hound", 5, 15, 1, 6, 5, 12, std::vector<Effect>(), "Fast unit with moderate attack."));
    _troop_templates.push_back(std::make_unique<Troop>("Demon", 15, 40, 1, 5, 9, 20, std::vector<Effect>(), "Powerful demon unit with high health and attack."));

    _troop_templates.push_back(std::make_unique<Troop>("Gremlin", 1, 4, 1, 3, 2, 6, std::vector<Effect>(), "Weak unit with low stats."));
    _troop_templates.push_back(std::make_unique<Troop>("Stone Golem", 6, 30, 1, 2, 5, 15, std::vector<Effect>(), "Durable unit with high defense."));
    _troop_templates.push_back(std::make_unique<Troop>("Mage", 4, 12, 1, 4, 6, 10, std::vector<Effect>(), "Ranged magical unit with moderate health."));

    _troop_templates.push_back(std::make_unique<Troop>("Skeleton", 2, 6, 1, 3, 2, 8, std::vector<Effect>(), "Weak undead unit with low stats."));
    _troop_templates.push_back(std::make_unique<Troop>("Zombie", 3, 15, 1, 2, 3, 12, std::vector<Effect>(), "Slow unit with moderate health."));
    _troop_templates.push_back(std::make_unique<Troop>("Vampire", 12, 30, 1, 7, 7, 15, std::vector<Effect>(), "Powerful undead unit with regeneration potential."));

}

std::vector<Hero>& Catalog::getHeroTemplates()
{
    return _hero_templates;
}

std::vector<std::shared_ptr<Troop>>& Catalog::getTroopTemplates()
{
    return _troop_templates;
}
