/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef CATALOG_h
#define CATALOG_h

#include <map>
#include <string>
#include "Troop.h"
#include "Hero.h"

class Catalog
{
public:
    Catalog();

private:
    std::map<std::string, Hero> _hero_teplates;
    std::map<std::string, Troop> _troop_templates;
}




#endif
