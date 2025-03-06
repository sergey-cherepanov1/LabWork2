/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Army.h"

class Player
{
public:
    Player();
    Player(const std::string& name, const Army& army);
    std::string getName() const;
    Army getArmy() const;
    void setName(std::string name);
    
private:
    std::string _name;
    Army _army;
};

#endif
