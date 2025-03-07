/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TERMINALUI_H
#define TERMINALUI_H

#include <iostream>
#include "Catalog.h"

/*enum class GameInfo {}*/
/*enum class GameInput {}*/

class TerminalUI
{
public:
    void displayInfo(int info_state) const;
    std::string handleInput(int input_state) const;
private:
    Catalog _catalog;
    void showHeroes() const;
    void showTroops() const;
};

#endif
