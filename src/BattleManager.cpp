/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "BattleManager.h"

BattleManager::BattleManager() : _player1(), _player2(), _ai(), _field(), _queue(), _action(_field, _player1, _player2, _ai), _battle_status(true), _mode(false) {}

void BattleManager::run()
{
    fillTheField();
    while (_battle_status)
    {
        makeQueue();
        displayField();
        turn();
        updateEffects();
    }
}

void BattleManager::turn()
{
    for (auto& troop : _queue)
    {
        if (!_battle_status)
        {
            break;
        }
        if (troop->getAmount() <= 0)
        {
            continue;
        }

        std::string player_name = troop->getOwner() ? (_mode ? _player2.getName() : _ai.getName()) : _player1.getName();
        std::cout << "\n=== Turn Start ===\n";
        std::cout << "This is the turn of " << player_name << "'s " << troop->getName() << ".\n";

        troop->setHasAttacked(false);
        troop->setHasCasted(false);
        troop->setCurrentStamina(troop->getMaxStamina());

        if (troop->getOwner() && !_mode)
        {
            _ai.makeTurn(troop, _field, _action, _battle_status);
            displayField();
        }
        else
        {
            int valid;
            while (troop->getCurrentStamina() > 0 || !troop->hasAttacked())
            {
                std::cout << "Position: (" << troop->getX() << ", " << troop->getY() << ")\n";
                std::cout << "Remaining stamina: " << troop->getCurrentStamina() << "\n";
                std::cout << "You can:\n";
                std::cout << "1. Move" << (troop->getCurrentStamina() <= 0 ? " (unavailable)" : "") << "\n";
                std::cout << "2. Attack" << (troop->hasAttacked() ? " (unavailable)" : (_action.canAttackTarget(troop) ? "" : " (no targets)")) << "\n";
                std::cout << "3. Cast Spell" << (troop->hasCasted() ? " (unavailable)" : "") << "\n";
                std::cout << "4. Skip\n";
                std::cout << "Enter 1, 2, 3, or 4: ";
                std::string action;
                std::getline(std::cin, action);
                try
                {
                    int action_num = std::stoi(action);
                    if (1 <= action_num && action_num <= 4)
                    {
                        switch (action_num)
                        {
                        case 1:
                            valid = _action.move(troop);
                            break;
                        case 2:
                            valid = _action.attack(troop);
                            break;
                        case 3:
                            valid = _action.castSpell(troop);
                            break;
                        case 4:
                            _action.skip(troop);
                            break;
                        }
                        if (valid == 1)
                        {
                            continue;
                        }
                        if (valid == 2)
                        {
                            _battle_status = false;
                            break;
                        }
                    }
                    else
                    {
                        std::cout << "Invalid input. Please enter 1, 2, 3, or 4.\n";
                        continue;
                    }
                }
                catch (std::exception& e)
                {
                    std::cout << "Invalid input. Please enter 1, 2, 3, or 4.\n";
                    continue;
                }
                std::cout << "==================\n";
                displayField();
            }
        }
    }
}
void BattleManager::makeQueue()
{
    _queue.clear();
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (_field[i][j] && _field[i][j]->getAmount() > 0)
            {
                _queue.push_back(_field[i][j]);
            }
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

void BattleManager::updateEffects()
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (_field[i][j] && _field[i][j]->getAmount() > 0)
            {
                _field[i][j]->applyEffects();
                if (_action.removeDefeatedTroop(_field[i][j], i, j) == 2)
                {
                    _battle_status = false;
                    return;
                }
            }
        }
    }
}

void BattleManager::fillTheField()
{
    for (int i = 0; i < 6; ++i)
    {
        std::shared_ptr<Troop> troop1 = _player1.getArmy().getTroops()[i];
        std::shared_ptr<Troop> troop2;
        if (!_mode)
        {
            troop2 = _ai.getArmy().getTroops()[i];
        } else
        {
            troop2 = _player2.getArmy().getTroops()[i];
            troop2->setOwner();
        }
        
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

    Hero& hero1 = _player1.getArmy().getHero();
    Hero& hero2 = !_mode ? _ai.getArmy().getHero() : _player2.getArmy().getHero();

    std::cout << std::left << std::setw(width) << ("[P1]" + _player1.getName() + "'s Hero: " + hero1.getName()) << std::string(spaces_between, ' ') << std::setw(width) << ("[P2]" + _player2.getName() + "'s Hero: " + hero2.getName()) << "\n";

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
                }
                else
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
            }
            else
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


Player& BattleManager::getPlayer1()
{
    return _player1;
}

Player& BattleManager::getPlayer2()
{
    return _player2;
}

AI& BattleManager::getAI()
{
    return _ai;
}

void BattleManager::setMode()
{
    _mode = !_mode;
}
