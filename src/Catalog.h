/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <memory>
#include "Troop.h"
#include "Hero.h"

class Catalog
{
public:
    Catalog();
    std::vector<Hero>& getHeroTemplates();
    std::vector<std::unique_ptr<Troop>>& getTroopTemplates();

private:
    std::vector<Hero> _hero_templates;
    std::vector<std::unique_ptr<Troop>> _troop_templates;
};

#endif
