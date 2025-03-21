/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Army.h"
#include "Catalog.h"

class Player
{
public:
    Player();
    std::string getName();
    Army& getArmy();

    void setName(std::string name);
    void showMightLeft();
    virtual void setupArmy(Catalog& catalog) {}
private:
    std::string _name;
    Army _army;
};

#endif
