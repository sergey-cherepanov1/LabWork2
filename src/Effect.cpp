/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Effect.h"

Effect::Effect() : _type(EffectType::HEALTH), _value(0), _duration(0), _applyEachTurn(0) {}

Effect::Effect(EffectType type, int value, int duration, bool applyEachTurn) : _type(type), _value(value), _duration(duration), _applyEachTurn(applyEachTurn) {}

bool Effect::applyEachTurn()
{
    return _applyEachTurn;
}

int Effect::getValue()
{
    return _value;
}

int Effect::getDuration()
{
    return _duration;
}

EffectType Effect::getType()
{
    return _type;
}

void Effect::decreaseDuration()
{
    _duration -= 1;
}
