/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Army.h"

class Player
{
public:
    Player();
    Player(std::string name, Army&& army);
    std::string getName();
    Army& getArmy();

    void setName(std::string name);
    void showMightLeft();
private:
    std::string _name;
    Army _army;
};

#endif
