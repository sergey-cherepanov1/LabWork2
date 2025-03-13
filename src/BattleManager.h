/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include <array>
#include <memory>
#include "Troop.h"
#include "Player.h"

class BattleManager
{
public:
    void run(std::unique_ptr<Player>& player1, std::unique_ptr<Player>& player2);
private:
    std::array<std::array<std::unique_ptr<Troop>,6>, 6> _field;
};


#endif
