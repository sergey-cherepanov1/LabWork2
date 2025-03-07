/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "TerminalUI.h"

void TerminalUI::displayInfo(int info_state) const
{
    switch (info_state)
    {
    case 0: /*InfoState::MENU*/
        std::cout << "=== Main Menu ===\n"
                  << "1. Start Game\n"
                  << "2. Local Multiplayer\n"
                  << "3. Exit\n"
                  << "Enter your choice: ";
        break;
    case 1: /*InfoState::ENTER_NAME_SINGLEPLAYER*/
        std::cout << "\n=== Enter Player Name ===\n"
                  << "Enter name for Player (max 20 characters, must not be empty): ";
        break;
    case 2: /*InfoState::ENTER_NAME_MULTIPLAYER_1*/
        std::cout << "\n=== Enter Player Names ===\n"
                  << "Enter name for Player 1 (max 20 characters, must not be empty): ";
        break;
    case 3: /*InfoState::ENTER_NAME_MULTIPLAYER_2*/
        std::cout << "Enter name for Player 2 (max 20 characters, must not be empty): ";
        break;

    case 4: /*InfoState::CHOOSE_DIFFICLUTY*/
        std::cout << "\n== Choose Difficulty Level ==\n"
                  << "1. Easy (MaxMight:5500)\n"
                  << "2. Normal (MaxMight: 2500)\n"
                  << "3. Hard (MaxMight: 1000)\n"
                  << "Enter your choice: ";
        break;
    case 5: /*InfoState::PREPARE_ARMY_SINGLEPLAYER_HEROES*/
        std::cout << "\n=== Prepare Your Army===\n"
                  << "Select your hero.\n\n";

        std::cout << "Enter the number of the hero you have chosen: ";

        break;

    }
}

std::string TerminalUI::handleInput(int input_state) const
{
    std::string input;
    bool validInput = false;

    while (!validInput)
    {
        std::getline(std::cin, input);

        switch (input_state)
        {
        case 0: /*InputState::MENU*/
        {
            if (input == "1" || input == "2" || input == "3")
            {
                validInput = true;
            }
            else
            {
                std::cout << "Invalid input. Please enter 1, 2, or 3: ";
            }
            break;
        }
        case 1: /*InputState::GET_NAME*/
        {
            if (input.empty())
            {
                std::cout << "Name cannot be empty. Please enter a valid name: ";
            }
            else if (input.length() > 20)
            {
                std::cout << "Name is too long (max 20 characters). Please enter a shorter name: ";
            }
            else
            {
                validInput = true;
            }

            break;
        }
        case 5: /*InputState::PREPARE_ARMY*/
        {
            if (input == "hero" || input == "troop" || input == "switch")
            {

            }
            else
            {
                std::cout << "Invalid input. Please enter hero, troop, or switch: ";
            }
            break;
        }

        }
    }
    return input;
}

void TerminalUI::showHeroes() const
{
    std::cout << "=== Available Heroes ===\n";
    const std::vector<Hero>& heroes = _catalog.getHeroTemplates();
    for (size_t i = 0; i < heroes.size(); ++i)
    {
        const Hero& hero = heroes[i];
        std::cout << (i + 1) << ". " << hero.getName() << " (Might: " << hero.getMight()
                  << ", Mana: " << hero.getMana() << ")\n";
        std::cout << "   Spells: \n";
        const std::vector<Spell>& spells = hero.getSpells();
        for (size_t j = 0; j < spells.size(); ++j)
        {
            std::cout << "   * " << spells[j].getName() << "\n   -- Cost: " << spells[j].getManaCost() << "\n   -- Description: " << spells[j].getDescription() << "\n";
        }
        std::cout << "\n\n";
    }
    std::cout << "Select a hero by number (e.g., 'hero 1') or continue: ";
}

void TerminalUI::showTroops() const
{
    std::cout << "=== Available Troops ===\n";
    const std::vector<Troop>& troops = _catalog.getTroopTemplates();
    for (size_t i = 0; i < troops.size(); ++i)
    {
        const Troop& troop = troops[i];
        std::cout << (i + 1) << ". " << troop.getName() << " (Health: " << troop.getHealth()
                  << ", Attack: " << troop.getAttack() << ", Stamina: " << troop.getMaxStamina()
                  << ", Initiative: " << troop.getInitiative() << ", Might: " << troop.getMight()
                  << ", Amount: " << troop.getAmount() << ")\n";
    }
    std::cout << "Select a troop by number and amount (e.g., 'troop 1 100') or continue: ";
}
