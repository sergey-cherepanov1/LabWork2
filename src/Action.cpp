/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Action.h"
#include <cstdlib>

Action::Action(std::array<std::array<std::shared_ptr<Troop>, 6>, 6>& field) 
    : _field(field) 
{}

void Action::move(std::shared_ptr<Troop>& troop)
{
    int current_row = troop->getX();
    int current_col = troop->getY();

    if (troop->getCurrentStamina() <= 0)
    {
        std::cout << "No stamina left to move.\n";
        return;
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
        catch (std::exception& e)
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

void Action::attack(std::shared_ptr<Troop>& troop)
{
    if (troop->hasAttacked())
    {
        std::cout << troop->getName() << " has already attacked this turn.\n";
        return;
    }

    int x = troop->getX();
    int y = troop->getY();
    int target_x, target_y;
    bool owner = troop->getOwner();
    bool valid_target = false;

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
        catch (std::exception& e)
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

        if (_field[target_x][target_y] == troop)
        {
            std::cout << "Cannot attack yourself.\n";
            continue;
        }

        if (_field[target_x][target_y]->getOwner() == owner)
        {
            std::cout << "Cannot attack your own troop.\n";
            continue;
        }

        int dx = std::abs(target_x - x);
        int dy = std::abs(target_y - y);
        if (dx > 1 || dy > 1 || (dx == 0 && dy == 0))
        {
            std::cout << "Target must be exactly 1 step away (up, down, left, right, or diagonal).\n";
            continue;
        }

        valid_target = true;
    }

    std::shared_ptr<Troop>& target = _field[target_x][target_y];
    std::cout << troop->getName() << " attacks " << target->getName() << " at Row " << target_x << ", Col " << target_y << ".\n";
    troop->setHasAttacked(true);
}

