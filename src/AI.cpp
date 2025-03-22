/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "AI.h"
#include "Action.h"

/**
 * @brief Default constructor for AI.
 */
AI::AI() : Player()
{
    setName("AI Bot");
}

/**
 * @brief Sets up the AI's army using predefined templates.
 */
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

/**
 * @brief Executes the AI's turn for a specific troop.
 */
void AI::makeTurn(std::shared_ptr<Troop>& troop, std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& field, Action& action, bool& battle_status)
{
    int x = troop->getX();
    int y = troop->getY();

    std::shared_ptr<Troop> nearest_target = nullptr;
    int min_distance = 100;
    int target_x = -1, target_y = -1;

    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (field[i][j] && !field[i][j]->getOwner())
            {
                int distance = std::abs(i - x) + std::abs(j - y);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    nearest_target = field[i][j];
                    target_x = i;
                    target_y = j;
                }
            }
        }
    }

    if (!nearest_target)
    {
        std::cout << troop->getName() << " (AI) skips its turn (no enemies found).\n";
        action.skip(troop);
        return;
    }

    while (troop->getCurrentStamina() > 0 && !action.canAttackTarget(troop))
    {
        int new_x = x + (target_x > x ? 1 : (target_x < x ? -1 : 0));
        int new_y = y + (target_y > y ? 1 : (target_y < y ? -1 : 0));

        if (new_x >= 0 && new_x < 6 && new_y >= 0 && new_y < 6 && !field[new_x][new_y])
        {
            std::cout << troop->getName() << " (AI) moves from (" << x << ", " << y << ") to (" 
                      << new_x << ", " << new_y << ").\n";
            field[x][y] = nullptr;
            field[new_x][new_y] = troop;
            troop->setPosition(new_x, new_y);
            troop->setCurrentStamina(troop->getCurrentStamina() - 1);
            x = new_x;
            y = new_y;
        }
        else
        {
            std::cout << troop->getName() << " (AI) skips its turn (cannot move further).\n";
            action.skip(troop);
            return;
        }
    }

    if (nearest_target && !troop->hasAttacked() && action.canAttackTarget(troop))
    {
        std::cout << troop->getName() << " (AI) attacks " << nearest_target->getName() << " at (" 
                  << target_x << ", " << target_y << ").\n";
        int result = action.attack(troop, target_x, target_y);
        if (result == 2)
        {
            battle_status = false;
        }
    }
    else if (troop->getCurrentStamina() <= 0)
    {
        std::cout << troop->getName() << " (AI) skips its turn (out of stamina).\n";
        action.skip(troop);
    }
}
