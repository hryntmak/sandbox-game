//
// Created by User on 09.05.2023.
//

#include "../CAction.h"

#ifndef HRYNTMAK_CTAKEDAMAGE_H
#define HRYNTMAK_CTAKEDAMAGE_H


/**
 * Descendant of an abstract class CAction.
 * Implements taking damage.
 */
class CTakeDamage : public CAction{
public:
    /**
     * Constructs an action with the amount of damage,
     * that will be dealt when activated.
     * @param dmg Amount of damage
     */
    explicit CTakeDamage(int dmg = 0);
    /**
     * Will deal damage (reduce lives by the amount of damage)
     * @param stats Reference to the changing stats
     * @return Success of the action.
     */
    bool changeStats(SState &stats) override;
    /**
     * Does nothing.
     * @param progtest Reference to the changing progtest
     * @return Always false.
     */
    bool changeProgtest(SProgtest &progtest) override;
private:
    /**
     * Amount of damage
     */
    int m_Damage;
};


#endif //HRYNTMAK_CTAKEDAMAGE_H
