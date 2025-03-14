/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "Effect.h"

class Spell
{
public:
    Spell();
    Spell(std::string name, int cost, Effect effect, std::string description);
    std::string getName();
    int getCost();
    Effect getEffect();
    std::string getDescription();
private:
    std::string _name;
    int _cost;
    Effect _effect;
    std::string _description;
};

#endif
