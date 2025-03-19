/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "Troop.h"

Troop::Troop() : _name("Default"), _amount(1), _health(0), _attack(0), _max_stamina(0), _current_stamina(0), _initiative(0), _might(0), _effects(), _description(""), _owner(0) {}

Troop::Troop(std::string name, int amount, int health, int attack, int max_stamina, int current_stamina, int initiative, int might, std::vector<Effect> effects, std::string description) : _name(name), _amount(amount), _health(health), _attack(attack), _max_stamina(max_stamina), _current_stamina(current_stamina), _initiative(initiative), _might(might), _effects(effects), _description(description) {}

std::string Troop::getName()
{
    return _name;
}

int Troop::getAmount()
{
    return _amount;
}

int Troop::getHealth()
{
    return _health;
}

int Troop::getAttack()
{
    return _attack;
}

int Troop::getMaxStamina()
{
    return _max_stamina;
}

int Troop::getCurrentStamina()
{
    return _current_stamina;
}

int Troop::getInitiative()
{
    return _initiative;
}

int Troop::getMight()
{
    return _might;
}

std::vector<Effect> Troop::getEffects()
{
    return _effects;
}

std::string Troop::getDescription()
{
    return _description;
}

void Troop::setAmount(int amount)
{
    _amount = amount;
}

int Troop::getTotalHealth()
{
    return _health * _amount;
}
int Troop::getTotalAttack()
{
    return _attack * _amount;
}
int Troop::getTotalMight()
{
    return _might * _amount;
}

int Troop::getX()
{
    return _x;
}

int Troop::getY()
{
    return _y;
}

bool Troop::getOwner()
{
    return _owner;
}

bool Troop::hasAttacked()
{
    return _hasAttacked;
}

void Troop::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void Troop::setHasAttacked(bool attacked)
{
    _hasAttacked = attacked;
}

void Troop::setCurrentStamina(int stamina)
{
    _current_stamina = stamina;
}

void Troop::setOwner()
{
    _owner = !_owner;
}
