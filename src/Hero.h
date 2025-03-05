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
    Hero(const std::string& name, int might, int mana, const std::vector<Spell>& spells, const std::string& description);
    std::string getName() const;
    int getMight() const;
    int getMana() const;
    std::vector<Spell> getSpells() const;
    std::string getDescription() const;
private:
    std::string _name;
    int _might;
    int _mana;
    std::vector<Spell> _spells;
    std::string _description;
};

#endif
