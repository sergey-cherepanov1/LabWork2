/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <memory>
#include "Troop.h"
#include "Hero.h"

/**
 * @class Catalog
 * @brief Stores templates for heroes and troops available in the game.
 * 
 * Provides access to predefined hero and troop configurations for army setup.
 */
class Catalog
{
public:
    /**
     * @brief Default constructor for Catalog.
     * 
     * Initializes the catalog with predefined hero and troop templates.
     */
    Catalog();

    /**
     * @brief Gets the vector of hero templates.
     * @return Reference to the vector of Hero objects.
     */
    std::vector<Hero>& getHeroTemplates();

    /**
     * @brief Gets the vector of troop templates.
     * @return Reference to the vector of shared pointers to Troop objects.
     */
    std::vector<std::shared_ptr<Troop>>& getTroopTemplates();

private:
    std::vector<Hero> _hero_templates; ///< Vector of predefined hero templates.
    std::vector<std::shared_ptr<Troop>> _troop_templates; ///< Vector of predefined troop templates.
};

#endif
