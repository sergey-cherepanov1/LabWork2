/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Effect.h"

Effect::Effect() : _type(EffectType::HEALTH), _value(0), _duration(0) {}

Effect::Effect(EffectType type, int value, int duration) : _type(type), _value(value), _duration(duration) {}

int Effect::getValue() const
{
    return _value;
}

int Effect::getDuration() const
{
    return _duration;
}

EffectType Effect::getType() const
{
    return _type;
}
