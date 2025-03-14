/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "BattleManager.h"

BattleManager::BattleManager() : _player1(std::make_unique<Player>()), _player2(std::make_unique<AI>()), _field(), _queue() {}

void BattleManager::run()
{
    while (_player1->getArmy().getStatus() && _player2->getArmy().getStatus())
    {
        
        
        break;
    }
}

void BattleManager::fillTheField()
{
  
}

std::unique_ptr<Player>& BattleManager::getPlayer1()
{
    return _player1;
}

std::unique_ptr<Player>& BattleManager::getPlayer2()
{
    return _player2;
}
