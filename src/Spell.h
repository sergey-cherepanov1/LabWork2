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
    Spell(const std::string& name, int mana_cost, const Effect& effect, const std::string& description);
    std::string getName() const;
    int getManaCost() const;
    Effect getEffect() const;
    std::string getDescription() const;
private:
    std::string _name;
    int _mana_cost;
    Effect _effect;
    std::string _description;
};

#endif
