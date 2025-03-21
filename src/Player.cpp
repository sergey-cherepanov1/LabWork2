/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Player.h"

Player::Player() : _name(), _army() {}

std::string Player::getName()
{
    return _name;
}

Army& Player::getArmy()
{
    return _army;
}

void Player::setName(std::string name)
{
    _name = name;
}

void Player::showMightLeft()
{
    std::cout << "\nThe Might of " << _name << "'s army: " << _army.getCurrentMight() << "/" << _army.getMaxMight() << "\n";
}
