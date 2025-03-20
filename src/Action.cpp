/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Action.h"

Action::Action(std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& field, Player* player1, Player* player2) : _field(field), _player1(player1), _player2(player2) {}

int Action::move(std::shared_ptr<Troop>& troop)
{
    int current_row = troop->getX();
    int current_col = troop->getY();

    if (troop->getCurrentStamina() <= 0)
    {
        std::cout << "No stamina left to move.\n";
        return 1;
    }

    int new_row, new_col;
    bool valid_input = false;

    while (!valid_input)
    {
        std::cout << "Current position: Row " << current_row << ", Col " << current_col << "\n";
        std::cout << "Remaining stamina: " << troop->getCurrentStamina() << " steps\n";
        std::cout << "Enter new Row (0-5): ";
        std::string new_row_str;
        std::getline(std::cin, new_row_str);
        std::cout << "Enter new Col (0-5): ";
        std::string new_col_str;
        std::getline(std::cin, new_col_str);

        try
        {
            new_row = std::stoi(new_row_str);
            new_col = std::stoi(new_col_str);
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid input: Please enter numbers only.\n";
            continue;
        }

        if (new_row < 0 || new_row >= 6 || new_col < 0 || new_col >= 6)
        {
            std::cout << "Position out of bounds: Enter Row and Col between 0 and 5.\n";
            continue;
        }

        if (_field[new_row][new_col])
        {
            std::cout << "Position is occupied: Choose another position.\n";
            continue;
        }

        int distance = std::abs(new_row - current_row) + std::abs(new_col - current_col);
        if (distance > troop->getCurrentStamina())
        {
            std::cout << "Move too far: Max distance is " << troop->getCurrentStamina() << " steps.\n";
            continue;
        }

        valid_input = true;
    }

    _field[new_row][new_col] = troop;
    _field[current_row][current_col] = nullptr;
    troop->setPosition(new_row, new_col);
    troop->setCurrentStamina(troop->getCurrentStamina() - (std::abs(new_row - current_row) + std::abs(new_col - current_col)));
    std::cout << troop->getName() << " moved to Row " << new_row << ", Col " << new_col << ".\n";
    return 0;
}

bool Action::canAttackTarget(std::shared_ptr<Troop>& troop)
{
    int x = troop->getX();
    int y = troop->getY();
    bool owner = troop->getOwner();

    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            int new_x = x + dx;
            int new_y = y + dy;
            if (new_x >= 0 && new_x < 6 && new_y >= 0 && new_y < 6 && !(dx == 0 && dy == 0))
            {
                if (_field[new_x][new_y] && _field[new_x][new_y] != troop && _field[new_x][new_y]->getOwner() != owner)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int Action::attack(std::shared_ptr<Troop>& troop)
{
    std::cout << "Enter target Row (0-5): ";
    std::string target_row_str;
    std::getline(std::cin, target_row_str);
    std::cout << "Enter target Col (0-5): ";
    std::string target_col_str;
    std::getline(std::cin, target_col_str);

    int target_x = std::stoi(target_row_str);
    int target_y = std::stoi(target_col_str);

    if (target_x < 0 || target_x >= 6 || target_y < 0 || target_y >= 6 || !_field[target_x][target_y])
    {
        std::cout << "Invalid target.\n";
        return 1;
    }

    auto target = _field[target_x][target_y];
    if (target->getOwner() == troop->getOwner())
    {
        std::cout << "Cannot attack allied unit.\n";
        return 1;
    }

    troop->attack(target);
    troop->setHasAttacked(true);
    troop->setCurrentStamina(troop->getCurrentStamina() - 1);

    if (target->getAmount() <= 0)
    {
        std::cout << target->getName() << " has been defeated!\n";
        _field[target_x][target_y] = nullptr;

        Player* target_player = target->getOwner() ? _player2 : _player1;
        auto& troops = target_player->getArmy().getTroops();
        for (auto& troop_ptr : troops)
        {
            if (troop_ptr == target)
            {
                troop_ptr = nullptr;
                break;
            }
        }
        if (!target_player->getArmy().getStatus())
        {
            std::cout << target_player->getName() << "'s army has been defeated!\n";
            return 2;
        }
    }
    return 0;
}

int Action::castSpell(std::shared_ptr<Troop>& troop)
{
    Player* player = troop->getOwner() ? _player2 : _player1;
    auto& spells = player->getArmy().getHero().getSpells();
    int mana = player->getArmy().getHero().getMana();

    std::cout << "Available spells (Mana: " << mana << "):\n";
    for (size_t i = 0; i < spells.size(); ++i)
    {
        std::cout << (i + 1) << ". " << spells[i].getName() << " (Cost: " << spells[i].getCost() 
                  << ", " << spells[i].getDescription() << ")\n";
    }
    std::cout << "Enter spell number (1-" << spells.size() << ") or 0 to cancel: ";
    std::string spell_input;
    std::getline(std::cin, spell_input);
    int spell_index = std::stoi(spell_input) - 1;

    if (spell_index == -1)
    {
        std::cout << "Spell casting cancelled.\n";
        return 1;
    }

    if (spell_index < 0 || spell_index >= static_cast<int>(spells.size()))
    {
        std::cout << "Invalid spell number.\n";
        return 1;
    }

    Spell& spell = spells[spell_index];
    if (spell.getCost() > mana)
    {
        std::cout << "Not enough mana to cast " << spell.getName() << ".\n";
        return 1;
    }

    int target_x = -1, target_y = -1;
    bool valid_target = false;
    bool is_positive_effect = spell.getEffect().getValue() > 0;

    while (!valid_target)
    {
        std::cout << "Enter target Row (0-5): ";
        std::string target_row_str;
        std::getline(std::cin, target_row_str);
        std::cout << "Enter target Col (0-5): ";
        std::string target_col_str;
        std::getline(std::cin, target_col_str);

        try
        {
            target_x = std::stoi(target_row_str);
            target_y = std::stoi(target_col_str);
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid input: Please enter numbers only.\n";
            continue;
        }

        if (target_x < 0 || target_x >= 6 || target_y < 0 || target_y >= 6)
        {
            std::cout << "Target out of bounds: Enter Row and Col between 0 and 5.\n";
            continue;
        }

        if (!_field[target_x][target_y])
        {
            std::cout << "No target at this position.\n";
            continue;
        }

        bool target_owner = _field[target_x][target_y]->getOwner();
        if (is_positive_effect && target_owner != troop->getOwner())
        {
            std::cout << "You can only cast this spell on an ally.\n";
            continue;
        }
        if (!is_positive_effect && target_owner == troop->getOwner())
        {
            std::cout << "You can only cast this spell on an enemy.\n";
            continue;
        }

        valid_target = true;
    }

    auto target = _field[target_x][target_y];
    player->getArmy().getHero().setMana(mana - spell.getCost());
    Effect effect = spell.getEffect();
    target->addEffect(effect);
    std::cout << troop->getName() << " casts " << spell.getName() << " on " << target->getName() << ".\n";

    if (effect.getType() == EffectType::HEALTH && target->getAmount() <= 0)
    {
        std::cout << target->getName() << " has been defeated!\n";
        _field[target_x][target_y] = nullptr;

        Player* target_player = target->getOwner() ? _player2 : _player1;
        auto& troops = target_player->getArmy().getTroops();
        for (auto& troop_ptr : troops)
        {
            if (troop_ptr == target)
            {
                troop_ptr = nullptr;
                break;
            }
        }
        if (!target_player->getArmy().getStatus())
        {
            std::cout << target_player->getName() << "'s army has been defeated!\n";
            return 2;
        }
    }
    return 0;
}
void Action::skip(std::shared_ptr<Troop>& troop)
{
    troop->setHasAttacked(true);
    troop->setCurrentStamina(0);
    std::cout << troop->getName() << " skips its turn.\n";
}
