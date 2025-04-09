/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Player.h"

/**
 * @brief Default constructor for Player.
 */
Player::Player() : _name(), _army() {}

/**
 * @brief Gets the name of the player.
 */
std::string Player::getName()
{
    return _name;
}

/**
 * @brief Gets the player's army.
 */
Army& Player::getArmy()
{
    return _army;
}

/**
 * @brief Sets the name of the player.
 */
void Player::setName(std::string name)
{
    _name = name;
}

/**
 * @brief Displays the remaining might of the player's army.
 */
void Player::showMightLeft()
{
    std::cout << "\nThe Might of " << _name << "'s army: " << _army.getCurrentMight() << "/" << _army.getMaxMight() << "\n";
}
