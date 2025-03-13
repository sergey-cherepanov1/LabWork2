/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TERMINALUI_H
#define TERMINALUI_H

#include <iostream>
#include <array>
#include <memory>
#include "Catalog.h"
#include "Player.h"

enum class InfoState
{
    MENU,
    ENTER_NAME_SINGLEPLAYER,
    ENTER_NAME_MULTIPLAYER_1,
    ENTER_NAME_MULTIPLAYER_2,
    CHOOSE_DIFFICULTY,
    HEROES,
    TROOPS,
    AMOUNT
};
enum class InputState
{
    ONE_OF_THREE,
    GET_NAME,
    TROOPS,
    AMOUNT
};

class TerminalUI
{
public:
    void displayInfo(InfoState info_state);
    std::string handleInput(InputState input_state);
    void showArmy(std::unique_ptr<Player>& player);
    std::unique_ptr<Troop> selectTroop(int remaining_might, bool& should_end);

    Catalog& getCatalog();
private:
    void showHeroes();
    void showTroops();
    int selectTroopAmount(std::unique_ptr<Troop>& troop, int remaining_might);
    Catalog _catalog;
};

#endif
