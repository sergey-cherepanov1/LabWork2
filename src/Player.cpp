/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Player.h"

Player::Player() : _name("Player1"), _army() {}

Player::Player(const std::string& name, const Army& army) : _name(name), _army(army) {}

std::string Player::getName() const { return _name; }
Army Player::getArmy() const { return _army; }
void Player::setName(std::string name) { _name = name; }
