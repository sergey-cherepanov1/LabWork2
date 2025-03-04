/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef EFFECT_h
#define EFFECT_h

class Effect
{
public:
    Effect();

private:
    enum EffectType { HEALTH, MIGHT, DEFENSE, ATTACK };
    EffectType _type;
    int _value;
    int _duration;
};

#endif
