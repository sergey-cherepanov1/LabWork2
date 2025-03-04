/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef HERO_h
#define HERO_h

#include <string>
#include <vector>
#include "Spell.h"

class Hero
{
public:

private:
    std::string _name;
    int _might;
    int _mana;
    std::vector<Spell> _spell_book;
    std::string _description;
}


#endif
