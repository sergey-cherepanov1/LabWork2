/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "BattleManager.h"

BattleManager::BattleManager() : _player1(std::make_unique<Player>()), _player2(std::make_unique<AI>()), _field(), _queue(), _action(_field) {}

void BattleManager::run()
{
    fillTheField();
    while (_player1->getArmy().getStatus() && _player2->getArmy().getStatus())
    {
        makeQueue();
        displayField();
        turn();
        break;
    }
}

void BattleManager::turn()
{
    for (auto& troop : _queue)
    {
        int owner = troop->getOwner();
        std::string player_name = (owner == 0) ? _player1->getName() : _player2->getName();

        troop->setHasAttacked(false);
        troop->setCurrentStamina(troop->getMaxStamina());

        while (troop->getCurrentStamina() > 0)
        {
            std::cout << "\n=== Turn Start ===\n";
            std::cout << "This is the turn of " << player_name << "'s " << troop->getName() << ".\n";
            std::cout << "Remaining stamina: " << troop->getCurrentStamina() << "\n";
            std::cout << "You can:\n";
            std::cout << "1. Move\n";
            std::cout << "2. Attack\n";
            std::cout << "3. Defend\n";
            std::cout << "4. Cast Spell\n";
            std::cout << "5. Skip\n";
            std::cout << "Enter 1, 2, 3, 4 or 5: ";
            std::string action;
            std::getline(std::cin, action);
            try
            {
                int action_num = std::stoi(action);
                if (1 <= action_num && action_num <= 5)
                {
                    switch (action_num)
                    {
                    case 1:
                        _action.move(troop);
                        break;
                    }
                }
                else
                {
                    std::cout << "Invalid input. Please enter 1, 2, 3, 4 or 5.\n";
                }
            }
            catch (std::exception& e)
            {
                std::cout << "Invalid input. Please enter 1, 2, 3, 4 or 5.\n";
            }
            std::cout << "==================\n";
            displayField();
        }
    }
}

void BattleManager::makeQueue()
{

    for (int i = 0; i < 6; ++i)
    {
        std::shared_ptr troop1 = _player1->getArmy().getTroops()[i];
        std::shared_ptr troop2 = _player2->getArmy().getTroops()[i];
        if (troop1)
        {
            _queue.push_back(troop1);
        }
        if (troop2)
        {
            _queue.push_back(troop2);
        }
    }

    std::sort(_queue.begin(), _queue.end(),
              [](std::shared_ptr<Troop>& a, std::shared_ptr<Troop>& b)
    {
        if (a->getInitiative() == b->getInitiative())
        {
            return a->getTotalMight() > b->getTotalMight();
        }
        return a->getInitiative() > b->getInitiative();
    });
}

void BattleManager::fillTheField()
{
    for (int i = 0; i < 6; ++i)
    {
        std::shared_ptr troop1 = _player1->getArmy().getTroops()[i];
        std::shared_ptr troop2 = _player2->getArmy().getTroops()[i];
        if (troop1)
        {
            _field[i][0] = troop1;
            troop1->setPosition(i, 0);
        }
        if (troop2)
        {
            _field[i][5] = troop2;
            troop2->setPosition(i, 5);
        }
    }
}

void BattleManager::printCenteredLine(std::string str)
{
    int total_spaces = 15 - str.length();
    int spaces_before = 0;
    int spaces_after = 0;

    if (total_spaces > 0)
    {
        spaces_before = total_spaces / 2;
        spaces_after = total_spaces - spaces_before;
    }

    std::string padded_str = std::string(spaces_before, ' ') + str + std::string(spaces_after, ' ');
    std::cout << padded_str;
}


void BattleManager::displayField()
{
    std::cout << "\n=== Battle Field ===\n\n";

    int spaces_between = 45;
    int width = 25;

    Hero& hero1 = _player1->getArmy().getHero();
    Hero& hero2 = _player2->getArmy().getHero();

    std::cout << std::left << std::setw(width) << ("[P1]" + _player1->getName() + "'s Hero: " + hero1.getName()) << std::string(spaces_between, ' ') << std::setw(width) << ("[P2]" + _player2->getName() + "'s Hero: " + hero2.getName()) << "\n";

    std::cout << std::setw(width) << ("Mana: " + std::to_string(hero1.getMana())) << std::string(spaces_between, ' ') << std::setw(width) << ("Mana: " + std::to_string(hero2.getMana())) << "\n";

    std::array<Spell, 3>& spells1 = hero1.getSpells();
    std::array<Spell, 3>& spells2 = hero2.getSpells();

    for(int i = 0; i < 3; ++i)
    {
        std::string spell1 = std::to_string(i + 1) + ": " + spells1[i].getName() + ", Cost: " +  std::to_string(spells1[i].getCost());

        std::string spell2 = std::to_string(i + 1) + ": " + spells2[i].getName() + ", Cost: " + std::to_string(spells2[i].getCost());

        std::cout << std::setw(width) << spell1 << std::string(spaces_between, ' ') << std::setw(width) << spell2 << "\n";
    }
    std::cout << "\n";

    std::cout << "      ";
    for (int col = 0; col < 6; ++col)
    {
        std::cout << "     Col " << col << "     ";
    }
    std::cout << "\n";

    for (int row = 0; row < 6; ++row)
    {
        std::cout << "Row " << row << "|";

        for (int col = 0; col < 6; ++col)
        {
            if (_field[row][col])
            {
                std::string name = _field[row][col]->getName();
                std::string owner;
                if (!_field[row][col]->getOwner())
                {
                    owner = "[P1]";
                } else 
                {
                    owner = "[P2]";
                }

                name = owner + name;
                if (name.length() > 11)
                {
                    name = name.substr(0, 7) + "...";
                }
                printCenteredLine(name);

            }
            else
            {
                std::cout << " " + std::string(13, '-') + " ";
            }
        }
        std::cout << "\n";

        std::cout << "     |";
        for (int col = 0; col < 6; ++col)
        {
            if (_field[row][col])
            {
                int attack = _field[row][col]->getTotalAttack();
                printCenteredLine("ATK: " + std::to_string(attack));
            }
            else
            {
                std::cout << " " + std::string(13, '-') + " ";
            }
        }
        std::cout << "\n";

        std::cout << "     |";
        for (int col = 0; col < 6; ++col)
        {
            if (_field[row][col])
            {
                int health = _field[row][col]->getTotalHealth();
                printCenteredLine("HP: " + std::to_string(health));
            }
            else
            {
                std::cout << " " + std::string(13, '-') + " ";
            }
        }
        std::cout << "\n\n";
    }
    std::cout << "====================\n";

    std::cout << "Queue:\n";
    size_t t = 0;
    for (auto& troop : _queue)
    {
        ++t;
        std::string owner;
        for (int i = 0; i < 6; ++i)
        {
            if (!troop->getOwner())
                {
                    owner = "[P1]";
                } else 
                {
                    owner = "[P2]";
                }
        }
        if (t == _queue.size())
        {
            std::cout << owner + troop->getName() << "\n";
        }
        else
        {
            std::cout << owner + troop->getName() << " | ";
        }
    }
}


std::unique_ptr<Player>& BattleManager::getPlayer1()
{
    return _player1;
}

std::unique_ptr<Player>& BattleManager::getPlayer2()
{
    return _player2;
}
