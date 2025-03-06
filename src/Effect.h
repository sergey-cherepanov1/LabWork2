/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef EFFECT_H
#define EFFECT_H

enum EffectType { HEALTH, DEFENSE, ATTACK, STAMINA };

class Effect
{
public:
    Effect();
    Effect(EffectType type, int value, int duration);
    int getValue() const;
    int getDuration() const;
    EffectType getType() const;

private:
    EffectType _type;
    int _value;
    int _duration;
};

#endif
