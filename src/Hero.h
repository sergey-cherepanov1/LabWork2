/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef HERO_H
#define HERO_H

#include <string>
#include <array>
#include "Spell.h"

class Hero
{
public:
    Hero();
    Hero(std::string name, int might, int mana, std::array<Spell, 3> spells, std::string description);
    std::string getName();
    int getMight();
    int getMana();
    std::array<Spell, 3>& getSpells();
    std::string getDescription();
    
    void setMana(int mana);
private:
    std::string _name;
    int _might;
    int _mana;
    std::array<Spell, 3> _spells;
    std::string _description;
};

#endif
