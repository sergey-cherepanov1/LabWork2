/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Catalog.h"

class AI : public Player
{
public:
    AI();
    void setupArmy(Catalog& catalog);
};

#endif
