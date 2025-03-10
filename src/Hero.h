/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef HERO_H
#define HERO_H

#include <string>
#include <vector>
#include "Spell.h"

class Hero
{
public:
    Hero();
    Hero(std::string name, int might, int mana, std::vector<Spell> spells, std::string description);
    std::string getName();
    int getMight();
    int getMana();
    std::vector<Spell>& getSpells();
    std::string getDescription();
private:
    std::string _name;
    int _might;
    int _mana;
    std::vector<Spell> _spells;
    std::string _description;
};

#endif
