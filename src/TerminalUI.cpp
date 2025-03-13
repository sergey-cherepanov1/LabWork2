/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#include "TerminalUI.h"

void TerminalUI::displayInfo(InfoState info_state)
{
    switch (info_state)
    {
    case InfoState::MENU:
        std::cout << "=== Main Menu ===\n"
                  << "1. Start Game\n"
                  << "2. Local Multiplayer\n"
                  << "3. Exit\n"
                  << "Enter your choice: ";
        break;
    case InfoState::ENTER_NAME_SINGLEPLAYER:
        std::cout << "\n=== Enter Player Name ===\n"
                  << "Enter name for Player (max 20 characters, must not be empty): ";
        break;
    case InfoState::ENTER_NAME_MULTIPLAYER_1:
        std::cout << "\n=== Enter Player Names ===\n"
                  << "Enter name for Player 1 (max 20 characters, must not be empty): ";
        break;
    case InfoState::ENTER_NAME_MULTIPLAYER_2:
        std::cout << "Enter name for Player 2 (max 20 characters, must not be empty): ";
        break;

    case InfoState::CHOOSE_DIFFICULTY:
        std::cout << "\n== Choose Difficulty Level ==\n"
                  << "1. Easy (MaxMight:5500)\n"
                  << "2. Normal (MaxMight: 2500)\n"
                  << "3. Hard (MaxMight: 1000)\n"
                  << "Enter your choice: ";
        break;
    case InfoState::HEROES:
        std::cout << "\n=== Prepare Your Army===\n"
                  << "Select your hero.\n\n";
        showHeroes();
        std::cout << "Enter the number of the hero you have chosen: ";
        break;
    case InfoState::TROOPS:
        std::cout << "\nSelect your 6 troops.\n\n";
        showTroops();
        std::cout << "\nChoose units in order; they will be placed on the battlefield from top to bottom (1-6).\n" << "Enter the chosen troop number: ";
        break;
    case InfoState::AMOUNT:
        std::cout << "Enter the amount of units for chosen troop: ";
        break;
    }
}

std::string TerminalUI::handleInput(InputState input_state)
{
    std::string input;
    bool validInput = false;

    while (!validInput)
    {
        std::getline(std::cin, input);

        switch (input_state)
        {
        case InputState::ONE_OF_THREE:
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
        case InputState::GET_NAME:
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
        case InputState::TROOPS:
        {
            try
            {
                int number = std::stoi(input);
                if (number >= 1 && number <= 15)
                {
                    validInput = true;
                }
                else
                {
                    std::cout << "Please enter a number between 1 and 15: ";
                }
            }
            catch (const std::exception&)
            {
                std::cout << "Invalid input. Please enter a number between 1 and 15: ";
            }
            break;
        }
        case InputState::AMOUNT:
        {
            try
            {
                int number = std::stoi(input);
                if (number >= 1 && number <= 99)
                {
                    validInput = true;
                }
                else
                {
                    std::cout << "Please enter a number between 1 and 99: ";
                }
            }
            catch (const std::exception&)
            {
                std::cout << "Invalid input. Please enter a number between 1 and 99: ";
            }
            break;
        }
        }
    }
    return input;
}

void TerminalUI::showHeroes()
{
    std::cout << "=== Available Heroes ===\n";
    std::vector<Hero>& heroes = _catalog.getHeroTemplates();
    int i = 0;
    for (auto hero: heroes)
    {
        i++;
        std::cout << i << ". " << hero.getName() << " (Might: " << hero.getMight()
                  << ", Mana: " << hero.getMana() << ")\n";
        std::cout << "   Spells: \n";
        std::vector<Spell>& spells = hero.getSpells();
        for (auto spell: spells)
        {
            std::cout << "   * " << spell.getName() << "\n   -- Cost: " << spell.getManaCost() << "\n   -- Description: " << spell.getDescription() << "\n";
        }
        std::cout << "\n\n";
    }
}

void TerminalUI::showTroops()
{
    std::cout << "=== Available Troops ===\n";
    std::vector<std::unique_ptr<Troop>>& troops = _catalog.getTroopTemplates();
    int i = 0;
    for (auto& troop: troops)
    {
        i++;
        std::cout << i << ". " << troop->getName() << " (Health: " << troop->getHealth() << ", Attack: " << troop->getAttack() << ", Stamina: " << troop->getMaxStamina() << ", Initiative: " << troop->getInitiative() << ", Might: " << troop->getMight() << ")\n";
    }
}

void TerminalUI::showArmy(std::unique_ptr<Player>& player)
{
    std::cout << "\n=== " << player->getName() <<"'s Army ===\n";

    Hero& hero = player->getArmy().getHero();
    std::cout << hero.getName() << " (Might: " << hero.getMight() << ", Mana: " << hero.getMana() << ")\n";
    std::cout << "   Spells: \n";
    for (auto& spell : hero.getSpells())
    {
        std::cout << "   * " << spell.getName() << "\n   -- Cost: " << spell.getManaCost() << "\n   -- Description: " << spell.getDescription() << "\n";
    }
    std::cout << "\n\n";
    int i = 0;
    std::array<std::unique_ptr<Troop>, 6>& troops = player->getArmy().getTroops();
    for (auto& troop : troops)
    {
        if (troop != nullptr)
        {
            i++;
            std::cout << i << ". " << troop->getName() << " (Health: " << troop->getTotalHealth() << ", Attack: " << troop->getTotalAttack() << ", Stamina: " << troop->getMaxStamina() << ", Initiative: " << troop->getInitiative() << ", Might: " << troop->getTotalMight() << ", Amout: " << troop->getAmount() << ")\n";
        }
    }
    player->showMightLeft();
}

Catalog& TerminalUI::getCatalog()
{
    return _catalog;
}

std::unique_ptr<Troop> TerminalUI::selectTroop(int remaining_might, bool& should_end)
{
    should_end = false;
    std::unique_ptr<Troop> selected_troop;

    while (true)
    {
        displayInfo(InfoState::TROOPS);
        int troop_index = std::stoi(handleInput(InputState::TROOPS)) - 1;
        selected_troop = std::make_unique<Troop>(*_catalog.getTroopTemplates()[troop_index]);
        int troop_might = selected_troop->getMight();

        if (troop_might > remaining_might)
        {
            std::cout << "\nNot enough Might to add even one " << selected_troop->getName() << " (Requires: " << troop_might << ", Remaining: " << remaining_might << ").\n";

            bool any_troop_available = false;
            for (auto& troop : _catalog.getTroopTemplates())
            {
                if (troop->getMight() <= remaining_might)
                {
                    any_troop_available = true;
                    break;
                }
            }
            if (!any_troop_available)
            {
                std::cout << "No troops can be added with remaining Might (" << remaining_might << "). Proceeding with current army.\n";
                should_end = true;
                return nullptr;
            }
            std::cout << "Please select a different troop.\n";
            continue;
        }

        int desired_amount = selectTroopAmount(selected_troop, remaining_might);
        selected_troop->setAmount(desired_amount);
        break;
    }
    return selected_troop;
}

int TerminalUI::selectTroopAmount(std::unique_ptr<Troop>& troop, int remaining_might)
{
    int troop_might = troop->getMight();
    displayInfo(InfoState::AMOUNT);
    int desired_amount = std::stoi(handleInput(InputState::AMOUNT));
    int max_affordable_amount = remaining_might / troop_might;

    while (desired_amount * troop_might > remaining_might)
    {
        std::cout << "You cannot afford " << desired_amount << " " << troop->getName() << " (Requires: " << desired_amount * troop_might << ", Remaining: " << remaining_might << ").\n";
        std::cout << "Maximum you can take: " << max_affordable_amount << ".\n";
        std::cout << "Enter a new amount (1-" << max_affordable_amount << "): ";
        desired_amount = std::stoi(handleInput(InputState::AMOUNT));
    }
    return desired_amount;
}
