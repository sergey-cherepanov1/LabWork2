/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TERMINALUI_h
#define TERMINALUI_h

#include <iostream>
#include "GameState.h"

class TerminalUI
{
public:
    void displayInfo(GameState state);
    std::string handleInput(GameState state);
};


#endif
