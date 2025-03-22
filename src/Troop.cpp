/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Troop.h"

/**
 * @brief Default constructor for Troop.
 */
Troop::Troop() : _name("Unknown"), _amount(1), _health(0), _total_health(0), _attack(0), _base_attack(0), _max_stamina(1), _current_stamina(1), _initiative(0), _might(0), _effects(), _description(""), _x(-1), _y(-1), _hasAttacked(false), _hasCasted(false), _owner(false) {}

/**
 * @brief Constructor for Troop with specific parameters.
 */
Troop::Troop(std::string name, int amount, int health, int attack, int max_stamina, int initiative, int might, std::vector<Effect> effects, std::string description) : _name(name), _amount(amount), _health(health), _total_health(_health * _amount), _attack(attack), _base_attack(_attack), _max_stamina(max_stamina), _current_stamina(max_stamina), _initiative(initiative), _might(might), _effects(effects), _description(description), _x(-1), _y(-1), _hasAttacked(false), _hasCasted(false), _owner(false) {}

/**
 * @brief Performs an attack on a target troop.
 */
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

/**
 * @brief Applies all active effects to the troop.
 */
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

/**
 * @brief Adds a new effect to the troop.
 */
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

/**
 * @brief Resets an effect when it expires.
 */
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

/**
 * @brief Gets the name of the troop.
 */
std::string Troop::getName()
{
    return _name;
}

/**
 * @brief Gets the current number of units in the troop.
 */
int Troop::getAmount()
{
    return (_total_health + _health - 1) / _health;
}

/**
 * @brief Gets the health per unit of the troop.
 */
int Troop::getHealth()
{
    return _health;
}

/**
 * @brief Gets the current attack value per unit.
 */
int Troop::getAttack()
{
    return _attack;
}

/**
 * @brief Gets the maximum stamina of the troop.
 */
int Troop::getMaxStamina()
{
    return _max_stamina;
}

/**
 * @brief Gets the current stamina of the troop.
 */
int Troop::getCurrentStamina()
{
    return _current_stamina;
}

/**
 * @brief Gets the initiative value of the troop.
 */
int Troop::getInitiative()
{
    return _initiative;
}

/**
 * @brief Gets the might value per unit.
 */
int Troop::getMight()
{
    return _might;
}

/**
 * @brief Gets the vector of effects applied to the troop.
 */
std::vector<Effect>& Troop::getEffects()
{
    return _effects;
}

/**
 * @brief Gets the description of the troop.
 */
std::string Troop::getDescription()
{
    return _description;
}

/**
 * @brief Sets the number of units in the troop.
 */
void Troop::setAmount(int amount)
{
    _amount = amount;
    _total_health = _health * _amount;
}

/**
 * @brief Gets the total health of the troop.
 */
int Troop::getTotalHealth()
{
    return _total_health;
}

/**
 * @brief Gets the total attack of the troop.
 */
int Troop::getTotalAttack()
{
    return _attack * _amount;
}

/**
 * @brief Gets the total might of the troop.
 */
int Troop::getTotalMight()
{
    return _might * _amount;
}

/**
 * @brief Gets the X-coordinate of the troop on the battlefield.
 */
int Troop::getX()
{
    return _x;
}

/**
 * @brief Gets the Y-coordinate of the troop on the battlefield.
 */
int Troop::getY()
{
    return _y;
}

/**
 * @brief Gets the owner of the troop.
 */
bool Troop::getOwner()
{
    return _owner;
}

/**
 * @brief Checks if the troop has attacked this turn.
 */
bool Troop::hasAttacked()
{
    return _hasAttacked;
}

/**
 * @brief Checks if the troop has cast a spell this turn.
 */
bool Troop::hasCasted()
{
    return _hasCasted;
}

/**
 * @brief Sets the position of the troop on the battlefield.
 */
void Troop::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

/**
 * @brief Sets whether the troop has attacked this turn.
 */
void Troop::setHasAttacked(bool attacked)
{
    _hasAttacked = attacked;
}

/**
 * @brief Sets the current stamina of the troop.
 */
void Troop::setCurrentStamina(int stamina)
{
    _current_stamina = stamina;
}

/**
 * @brief Toggles the owner of the troop.
 */
void Troop::setOwner()
{
    _owner = !_owner;
}

/**
 * @brief Sets whether the troop has cast a spell this turn.
 */
void Troop::setHasCasted(bool casted)
{
    _hasCasted = casted;
}
