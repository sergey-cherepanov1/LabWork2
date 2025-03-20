/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "AI.h"
#include <iostream>

AI::AI() : Player()
{
    setName("AI Bot");
}

void AI::setupArmy(Catalog& catalog)
{
    getArmy().setMaxMight(3000);

    std::vector<std::shared_ptr<Troop>>& troop_templates = catalog.getTroopTemplates();
    std::vector<Hero>& hero_templates = catalog.getHeroTemplates();

    getArmy().setHero(hero_templates[1]);

    getArmy().setTroop(0, std::make_shared<Troop>(*troop_templates[1]));
    getArmy().getTroops()[0]->setAmount(99);
    getArmy().getTroops()[0]->setOwner();

    getArmy().setTroop(1, std::make_shared<Troop>(*troop_templates[2]));
    getArmy().getTroops()[1]->setAmount(80);
    getArmy().getTroops()[1]->setOwner();

    getArmy().setTroop(2, std::make_shared<Troop>(*troop_templates[5]));
    getArmy().getTroops()[2]->setAmount(60);
    getArmy().getTroops()[2]->setOwner();

    getArmy().setTroop(3, std::make_shared<Troop>(*troop_templates[4]));
    getArmy().getTroops()[3]->setAmount(70);
    getArmy().getTroops()[3]->setOwner();

    getArmy().setTroop(4, std::make_shared<Troop>(*troop_templates[11]));
    getArmy().getTroops()[4]->setAmount(50);
    getArmy().getTroops()[4]->setOwner();

    getArmy().setTroop(5, std::make_shared<Troop>(*troop_templates[14]));
    getArmy().getTroops()[5]->setAmount(37);
    getArmy().getTroops()[5]->setOwner();

    std::cout << "AI Bot army might: " << 3000 << "\n";
    std::cout << "Hero: " << getArmy().getHero().getName() << " (Might: "
              << getArmy().getHero().getMight() << ")\n";
    std::cout << "Troops:\n";
    for (auto& troop : getArmy().getTroops())
    {
        if (troop)
        {
            std::cout << "- " << troop->getName() << " x" << troop->getAmount()
                      << " (Total Might: " << troop->getTotalMight() << ")\n";
        }
    }
}
