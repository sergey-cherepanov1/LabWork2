/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef INFO_h
#define INFO_h

class Info()
{
public:
    void displayInfo(GameState state);
    void displayBattleTurn(Troop& troop, Player& player);
    void displayBattleEnd(Player& winner);
}


#endif
