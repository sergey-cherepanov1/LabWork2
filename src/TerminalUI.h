/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TERMINALUI_H
#define TERMINALUI_H

#include <iostream>
#include "GameState.h"
#include "GameMode.h"
#include "Catalog.h"

class TerminalUI
{
public:
    void displayInfo(GameState state, GameMode mode) const;
    std::string handleInput(GameState state, GameMode mode) const;
private:
    Catalog _catalog;
    void showHeroes() const;
    void showTroops() const;
};

#endif
