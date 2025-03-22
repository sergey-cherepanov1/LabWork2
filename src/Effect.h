/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/

#ifndef EFFECT_H
#define EFFECT_H

/**
 * @enum EffectType
 * @brief Defines the types of effects that can be applied to troops.
 */
enum EffectType { HEALTH, ATTACK, STAMINA };

/**
 * @class Effect
 * @brief Represents an effect that can modify a troop's attributes.
 *
 * Effects can alter health, attack, or stamina and may persist for multiple turns.
 */
class Effect
{
public:
    /**
     * @brief Default constructor for Effect.
     *
     * Initializes an effect with default values (HEALTH, 0 value, 0 duration).
     */
    Effect();

    /**
     * @brief Constructor for Effect with specific parameters.
     * @param type Type of the effect (HEALTH, ATTACK, or STAMINA).
     * @param value Value of the effect (positive or negative).
     * @param duration Number of turns the effect lasts.
     * @param applyEachTurn Whether the effect applies every turn or once.
     */
    Effect(EffectType type, int value, int duration, bool applyEachTurn);

    /**
     * @brief Gets the value of the effect.
     * @return Integer value of the effect.
     */
    int getValue();

    /**
     * @brief Gets the remaining duration of the effect.
     * @return Number of turns the effect will persist.
     */
    int getDuration();

    /**
     * @brief Gets the type of the effect.
     * @return EffectType enum value (HEALTH, ATTACK, or STAMINA).
     */
    EffectType getType();

    /**
     * @brief Decreases the duration of the effect by 1.
     */
    void decreaseDuration();

    /**
     * @brief Checks if the effect applies each turn.
     * @return True if the effect is applied every turn, false if applied once.
     */
    bool applyEachTurn();

private:
    EffectType _type; ///< Type of the effect (HEALTH, ATTACK, or STAMINA).
    int _value; ///< Value of the effect (positive or negative).
    int _duration; ///< Remaining duration of the effect in turns.
    bool _applyEachTurn; ///< Flag indicating if the effect applies each turn.
};

#endif
