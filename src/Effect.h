/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef EFFECT_H
#define EFFECT_H

enum EffectType { HEALTH, ATTACK, STAMINA };

class Effect
{
public:
    Effect();
    Effect(EffectType type, int value, int duration, bool applyEachTurn);
    int getValue();
    int getDuration();
    EffectType getType();
    void decreaseDuration();
    bool applyEachTurn();

private:
    EffectType _type;
    int _value;
    int _duration;
    bool _applyEachTurn;
};

#endif
