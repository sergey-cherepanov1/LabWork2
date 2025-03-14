/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "BattleManager.h"

BattleManager::BattleManager() : _player1(std::make_unique<Player>()), _player2(std::make_unique<AI>()), _field(), _queue() {}

void BattleManager::run()
{
    fillTheField();
    while (_player1->getArmy().getStatus() && _player2->getArmy().getStatus())
    {

        displayField();
        break;
    }
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
        }
        if (troop2)
        {
            _field[i][5] = troop2;
        }
    }
}

void BattleManager::printCenteredLine(std::string str)
{
    int total_spaces = 13 - str.length();
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

    int spaces_between = 30;
    int width = 25;

    Hero& hero1 = _player1->getArmy().getHero();
    Hero& hero2 = _player2->getArmy().getHero();

    std::cout << std::left << std::setw(width) << (_player1->getName() + "'s Hero: " + hero1.getName()) << std::string(spaces_between, ' ') << std::setw(width) << (_player2->getName() + "'s Hero: " + hero2.getName()) << "\n";

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
        std::cout << "    Col " << col << "    ";
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
                if (name.length() > 13)
                {
                    name = name.substr(0, 9) + "...";
                }
                printCenteredLine(name);

            }
            else
            {
                std::cout << " " + std::string(11, '-') + " ";
            }
        }
        std::cout << "\n";

        std::cout << "     |";
        for (int col = 0; col < 6; ++col)
        {
            if (_field[row][col])
            {
                int attack = _field[row][col]->getAttack();
                printCenteredLine("ATK: " + std::to_string(attack));
            }
            else
            {
                std::cout << " " + std::string(11, '-') + " ";
            }
        }
        std::cout << "\n";

        std::cout << "     |";
        for (int col = 0; col < 6; ++col)
        {
            if (_field[row][col])
            {
                int health = _field[row][col]->getHealth();
                printCenteredLine("HP: " + std::to_string(health));
            }
            else
            {
                std::cout << " " + std::string(11, '-') + " ";
            }
        }
        std::cout << "\n\n";
    }
    std::cout << "====================\n";
}


std::unique_ptr<Player>& BattleManager::getPlayer1()
{
    return _player1;
}

std::unique_ptr<Player>& BattleManager::getPlayer2()
{
    return _player2;
}
