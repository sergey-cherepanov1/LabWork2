/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "TerminalUI.h"

void TerminalUI::displayInfo(GameState state) const
{
    switch (state)
    {
    case GameState::MENU:
        std::cout << "=== Main Menu ===\n"
                  << "1. Start Game\n"
                  << "2. Local Multiplayer\n"
                  << "3. Exit\n"
                  << "Enter your choice: ";
        break;
    case GameState::PREPARE_ARMY:
        break;
    case GameState::BATTLE:
        break;
    case GameState::END:
        break;
    case GameState::REPLAY:
        break;
    }
}

std::string TerminalUI::handleInput(GameState state) const
{
    std::string input;
    bool validInput = false;

    while (!validInput)
    {
        std::getline(std::cin, input);

        switch (state)
        {
        case GameState::MENU:
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
        case GameState::PREPARE_ARMY:
        {
            break;
        }
        case GameState::BATTLE:
        {
            break;
        }
        case GameState::END:
        {
            break;
        }
        case GameState::REPLAY:
        {
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
            std::cout << "   *** " << spells[j].getName() << " (Cost: " << spells[j].getManaCost()
                      << ", Description: " << spells[j].getDescription() << ")\n";
        }
        std::cout << "\n";
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
