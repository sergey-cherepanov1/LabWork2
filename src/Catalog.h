/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "Troop.h"
#include "Hero.h"

class Catalog
{
public:
    Catalog();
    const std::vector<Hero>& getHeroTemplates() const;
    const std::vector<Troop>& getTroopTemplates() const;

private:
    std::vector<Hero> _hero_templates;
    std::vector<Troop> _troop_templates;
};

#endif
