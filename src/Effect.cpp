/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Effect.h"

/**
 * @brief Default constructor for Effect.
 */
Effect::Effect() : _type(EffectType::HEALTH), _value(0), _duration(0), _applyEachTurn(0) {}

/**
 * @brief Constructor for Effect with specific parameters.
 */
Effect::Effect(EffectType type, int value, int duration, bool applyEachTurn) : _type(type), _value(value), _duration(duration), _applyEachTurn(applyEachTurn) {}

/**
 * @brief Checks if the effect applies each turn.
 */
bool Effect::applyEachTurn()
{
    return _applyEachTurn;
}

/**
 * @brief Gets the value of the effect.
 */
int Effect::getValue()
{
    return _value;
}

/**
 * @brief Gets the remaining duration of the effect.
 */
int Effect::getDuration()
{
    return _duration;
}

/**
 * @brief Gets the type of the effect.
 */
EffectType Effect::getType()
{
    return _type;
}

/**
 * @brief Decreases the duration of the effect by 1.
 */
void Effect::decreaseDuration()
{
    _duration -= 1;
}
