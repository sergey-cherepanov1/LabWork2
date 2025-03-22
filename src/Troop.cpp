/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Troop.h"

Troop::Troop() : _name("Unknown"), _amount(1), _health(0), _total_health(0), _attack(0), _base_attack(0), _max_stamina(1), _current_stamina(1), _initiative(0), _might(0), _effects(), _description(""), _x(-1), _y(-1), _hasAttacked(false), _hasCasted(false), _owner(false) {}

Troop::Troop(std::string name, int amount, int health, int attack, int max_stamina, int initiative, int might, std::vector<Effect> effects, std::string description) : _name(name), _amount(amount), _health(health), _total_health(_health * _amount), _attack(attack), _base_attack(_attack), _max_stamina(max_stamina), _current_stamina(max_stamina), _initiative(initiative), _might(might), _effects(effects), _description(description), _x(-1), _y(-1), _hasAttacked(false), _hasCasted(false), _owner(false) {}

void Troop::attack(std::shared_ptr<Troop>& target)
{
    if (!target)
    {
        return;
    }
    int damage = getTotalAttack();
    int target_total_health = target->getTotalHealth();
    int new_total_health = std::max(0, target_total_health - damage);
    target->_total_health = new_total_health;
    std::cout << _name << " deals " << damage << " damage to " << target->getName()
              << ". " << target->getName() << " now has " << target->getTotalHealth()
              << " total health and " << target->getAmount() << " units remaining.\n";
}

void Troop::applyEffects()
{
    std::string effect_name;
    for (size_t i = 0; i < _effects.size(); ++i)
    {
        Effect& effect = _effects[i];
        if (effect.applyEachTurn())
        {
            switch (effect.getType())
            {
            case EffectType::HEALTH:
            {
                _total_health = std::max(0, getTotalHealth() + effect.getValue());
                effect_name = "health";
                break;
            }
            case EffectType::ATTACK:
                _attack = std::max(0, _attack + effect.getValue());
                effect_name = "attack";
                break;
            case EffectType::STAMINA:
                _current_stamina = std::max(0, _current_stamina + effect.getValue());
                effect_name = "stamina";
                break;
            }
            std::cout << _name << " affected by " << effect_name << ": " << (effect.getValue() > 0 ? "+" : "") << effect.getValue() << " (duration: " << effect.getDuration() << ")\n";
        }

        effect.decreaseDuration();
        if (effect.getDuration() == 0)
        {
            resetEffect(effect);
            _effects.erase(_effects.begin() + i);
            --i;
        }
    }
}

void Troop::addEffect(Effect& effect)
{
    std::string effect_name;
    if (effect.getDuration() == 0)
    {
        switch (effect.getType())
        {
        case EffectType::HEALTH:
        {
            _total_health = std::max(0, getTotalHealth() + effect.getValue());
            effect_name = "health";
            break;
        }
        case EffectType::ATTACK:
            _attack = std::max(0, _attack + effect.getValue());
            effect_name = "attack";
            break;
        case EffectType::STAMINA:
            _current_stamina = std::max(0, _current_stamina + effect.getValue());
            effect_name = "stamina";
            break;
        }
        std::cout << _name << " affected by instant " << effect_name << ": "
                  << (effect.getValue() > 0 ? "+" : "") << effect.getValue() << "\n";
    }
    else
    {
        _effects.push_back(effect);
        if (!effect.applyEachTurn())
        {
            switch (effect.getType())
            {
            case EffectType::HEALTH:
            {
                _total_health = std::max(0, getTotalHealth() + effect.getValue());
                effect_name = "health";
                break;
            }
            case EffectType::ATTACK:
                _attack = std::max(0, _attack + effect.getValue());
                effect_name = "attack";
                break;
            case EffectType::STAMINA:
                _current_stamina = std::max(0, _current_stamina + effect.getValue());
                effect_name = "stamina";
                break;
            }
            std::cout << _name << " gained effect: " << effect_name << ": " << (effect.getValue() > 0 ? "+" : "") << effect.getValue() << " (duration: " << effect.getDuration() << ")\n";
        }
        else
        {
            switch (effect.getType())
            {
            case EffectType::HEALTH:
                effect_name = "health";
                break;
            case EffectType::ATTACK:
                effect_name = "attack";
                break;
            case EffectType::STAMINA:
                effect_name = "stamina";
                break;
            }
            std::cout << _name << " gained effect (each turn): " << effect_name << ": " << (effect.getValue() > 0 ? "+" : "") << effect.getValue() << " (duration: " << effect.getDuration() << ")\n";
        }
    }
}

void Troop::resetEffect(Effect& effect)
{
    std::string effect_name;
    switch (effect.getType())
    {
    case EffectType::HEALTH:
        effect_name = "health";
        break;
    case EffectType::ATTACK:
        if (!effect.applyEachTurn())
        {
            _attack = _base_attack;
            for (auto& effect: _effects)
            {
                if (effect.getType() == EffectType::ATTACK && effect.getDuration() > 0 && !effect.applyEachTurn())
                {
                    _attack = std::max(0, _attack + effect.getValue());
                }
            }
        }
        effect_name = "attack";
        break;
    case EffectType::STAMINA:
        effect_name = "stamina";
        break;
    }
    std::cout << _name << " effect " << effect_name << " expired.\n";
}

std::string Troop::getName()
{
    return _name;
}

int Troop::getAmount()
{
    return (_total_health + _health - 1) / _health;
}

int Troop::getHealth()
{
    return _health;
}

int Troop::getAttack()
{
    return _attack;
}

int Troop::getMaxStamina()
{
    return _max_stamina;
}

int Troop::getCurrentStamina()
{
    return _current_stamina;
}

int Troop::getInitiative()
{
    return _initiative;
}

int Troop::getMight()
{
    return _might;
}

std::vector<Effect>& Troop::getEffects()
{
    return _effects;
}

std::string Troop::getDescription()
{
    return _description;
}

void Troop::setAmount(int amount)
{
    _amount = amount;
    _total_health = _health * _amount;
}

int Troop::getTotalHealth()
{
    return _total_health;
}
int Troop::getTotalAttack()
{
    return _attack * _amount;
}
int Troop::getTotalMight()
{
    return _might * _amount;
}

int Troop::getX()
{
    return _x;
}

int Troop::getY()
{
    return _y;
}

bool Troop::getOwner()
{
    return _owner;
}

bool Troop::hasAttacked()
{
    return _hasAttacked;
}

bool Troop::hasCasted()
{
    return _hasCasted;
}

void Troop::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void Troop::setHasAttacked(bool attacked)
{
    _hasAttacked = attacked;
}

void Troop::setCurrentStamina(int stamina)
{
    _current_stamina = stamina;
}

void Troop::setOwner()
{
    _owner = !_owner;
}

void Troop::setHasCasted(bool casted)
{
    _hasCasted = casted;
}
