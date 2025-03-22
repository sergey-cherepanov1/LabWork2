/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Army.h"

/**
 * @brief Default constructor for Army.
 */
Army::Army() : _hero(), _troops{}, _max_might(5500), _current_might(0), _status(1) {}

/**
 * @brief Constructor for Army with specific parameters.
 */
Army::Army(Hero hero, std::array<std::shared_ptr<Troop>, 6> troops, int max_might) : _hero(hero), _troops{}, _max_might(max_might), _status(0) {}

/**
 * @brief Gets the hero leading the army.
 */
Hero& Army::getHero()
{
    return _hero;
}

/**
 * @brief Gets the array of troops in the army.
 */
std::array<std::shared_ptr<Troop>, 6>& Army::getTroops()
{
    return _troops;
}

/**
 * @brief Checks the status of the army.
 */
bool Army::getStatus()
{
    for (int i = 0; i < 6; ++i)
    {
        if (_troops[i])
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Gets the maximum allowed might for the army.
 */
int Army::getMaxMight()
{
    return _max_might;
}

/**
 * @brief Gets the current total might of the army.
 */
int Army::getCurrentMight()
{
    updateCurrentMight();
    return _current_might;
}

/**
 * @brief Sets the hero leading the army.
 */
void Army::setHero(Hero& hero)
{
    _hero = hero;
}

/**
 * @brief Sets a troop at a specific position in the army.
 */
void Army::setTroop(int position, std::shared_ptr<Troop> troop)
{
    _troops[position] = troop;
}

/**
 * @brief Sets the maximum might for the army.
 */
void Army::setMaxMight(int max_might)
{
    _max_might = max_might;
}

/**
 * @brief Updates the current might of the army.
 */
void Army::updateCurrentMight()
{
    int hero_might = _hero.getMight();
    int troops_might = 0;
    for (auto& troop: _troops)
    {
        if (troop)
        {
            troops_might += troop->getTotalMight();
        }
    }
    _current_might = hero_might + troops_might;
}
