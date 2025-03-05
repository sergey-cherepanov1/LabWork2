/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TERMINALUI_H
#define TERMINALUI_H

#include <iostream>
#include "GameState.h"
#include "Catalog.h"

class TerminalUI
{
public:
    void displayInfo(GameState state) const;
    std::string handleInput(GameState state) const;
    void showHeroes() const;
    void showTroops() const;
private:
    Catalog _catalog;
};

#endif
