/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef TROOP_H
#define TROOP_H

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include "Effect.h"

/**
 * @class Troop
 * @brief Represents a troop unit in the game with combat attributes and effects.
 * 
 * Manages a troop's stats, position, actions, and applied effects during battle.
 */
class Troop
{
public:
    /**
     * @brief Default constructor for Troop.
     * 
     * Initializes a troop with default values.
     */
    Troop();

    /**
     * @brief Constructor for Troop with specific parameters.
     * @param name Name of the troop.
     * @param amount Number of units in the troop.
     * @param health Health per unit.
     * @param attack Attack value per unit.
     * @param max_stamina Maximum stamina of the troop.
     * @param initiative Initiative value determining turn order.
     * @param might Might value per unit.
     * @param effects Vector of effects applied to the troop.
     * @param description Description of the troop.
     */
    Troop(std::string name, int amount, int health, int attack, int max_stamina, int initiative, int might, std::vector<Effect> effects, std::string description);

    /**
     * @brief Sets the number of units in the troop.
     * @param amount New number of units.
     */
    void setAmount(int amount);

    /**
     * @brief Sets the position of the troop on the battlefield.
     * @param x X-coordinate on the battlefield.
     * @param y Y-coordinate on the battlefield.
     */
    void setPosition(int x, int y);

    /**
     * @brief Sets whether the troop has attacked this turn.
     * @param attacked True if the troop has attacked, false otherwise.
     */
    void setHasAttacked(bool attacked);

    /**
     * @brief Sets the current stamina of the troop.
     * @param stamina New stamina value.
     */
    void setCurrentStamina(int stamina);

    /**
     * @brief Toggles the owner of the troop (Player 1 or Player 2/AI).
     */
    void setOwner();

    /**
     * @brief Sets whether the troop has cast a spell this turn.
     * @param casted True if the troop has cast a spell, false otherwise.
     */
    void setHasCasted(bool casted);

    /**
     * @brief Gets the name of the troop.
     * @return String containing the troop's name.
     */
    std::string getName();

    /**
     * @brief Gets the current number of units in the troop.
     * @return Integer representing the number of units.
     */
    int getAmount();

    /**
     * @brief Gets the health per unit of the troop.
     * @return Integer representing health per unit.
     */
    int getHealth();

    /**
     * @brief Gets the current attack value per unit.
     * @return Integer representing attack per unit.
     */
    int getAttack();

    /**
     * @brief Gets the maximum stamina of the troop.
     * @return Integer representing maximum stamina.
     */
    int getMaxStamina();

    /**
     * @brief Gets the current stamina of the troop.
     * @return Integer representing current stamina.
     */
    int getCurrentStamina();

    /**
     * @brief Gets the initiative value of the troop.
     * @return Integer representing initiative.
     */
    int getInitiative();

    /**
     * @brief Gets the might value per unit.
     * @return Integer representing might per unit.
     */
    int getMight();

    /**
     * @brief Gets the vector of effects applied to the troop.
     * @return Reference to the vector of Effect objects.
     */
    std::vector<Effect>& getEffects();

    /**
     * @brief Gets the description of the troop.
     * @return String containing the troop's description.
     */
    std::string getDescription();

    /**
     * @brief Gets the X-coordinate of the troop on the battlefield.
     * @return Integer representing the X-coordinate.
     */
    int getX();

    /**
     * @brief Gets the Y-coordinate of the troop on the battlefield.
     * @return Integer representing the Y-coordinate.
     */
    int getY();

    /**
     * @brief Gets the owner of the troop.
     * @return True if owned by Player 2/AI, false if owned by Player 1.
     */
    bool getOwner();

    /**
     * @brief Checks if the troop has attacked this turn.
     * @return True if the troop has attacked, false otherwise.
     */
    bool hasAttacked();

    /**
     * @brief Checks if the troop has cast a spell this turn.
     * @return True if the troop has cast a spell, false otherwise.
     */
    bool hasCasted();

    /**
     * @brief Gets the total health of the troop (health * amount).
     * @return Integer representing total health.
     */
    int getTotalHealth();

    /**
     * @brief Gets the total attack of the troop (attack * amount).
     * @return Integer representing total attack.
     */
    int getTotalAttack();

    /**
     * @brief Gets the total might of the troop (might * amount).
     * @return Integer representing total might.
     */
    int getTotalMight();

    /**
     * @brief Performs an attack on a target troop.
     * @param target Shared pointer to the target troop.
     */
    void attack(std::shared_ptr<Troop>& target);

    /**
     * @brief Applies all active effects to the troop.
     */
    void applyEffects();

    /**
     * @brief Adds a new effect to the troop.
     * @param effect Reference to the Effect object to add.
     */
    void addEffect(Effect& effect);

    /**
     * @brief Resets an effect when it expires.
     * @param effect Reference to the Effect object to reset.
     */
    void resetEffect(Effect& effect);

private:
    std::string _name; ///< Name of the troop.
    int _amount; ///< Number of units in the troop.
    int _health; ///< Health per unit.
    int _total_health; ///< Total health of the troop (health * amount).
    int _attack; ///< Current attack value per unit.
    int _base_attack; ///< Base attack value per unit (before effects).
    int _max_stamina; ///< Maximum stamina of the troop.
    int _current_stamina; ///< Current stamina of the troop.
    int _initiative; ///< Initiative value determining turn order.
    int _might; ///< Might value per unit.
    int _total_might; ///< Total might of the troop (might * amount, unused in header).
    std::vector<Effect> _effects; ///< Vector of effects applied to the troop.
    std::string _description; ///< Description of the troop.
    int _x; ///< X-coordinate on the battlefield.
    int _y; ///< Y-coordinate on the battlefield.
    bool _hasAttacked; ///< Flag indicating if the troop has attacked this turn.
    bool _hasCasted; ///< Flag indicating if the troop has cast a spell this turn.
    bool _owner; ///< Owner of the troop (false - Player 1, true - Player 2/AI).
};

#endif
