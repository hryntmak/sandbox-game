//
// Created by User on 09.05.2023.
//

#include "../CAction.h"

#ifndef HRYNTMAK_CENERGYACTION_H
#define HRYNTMAK_CENERGYACTION_H

/**
 * Descendant of an abstract class CAction.
 * Implements adding or subtracting energy.
 */
class CEnergyAction : public CAction {
public:
    /**
     * Constructs an action with the amount of energy,
     * that will be added.
     * @param energy Amount of energy, that will be added
     */
    explicit CEnergyAction(int energy = 0);
    /**
     * If can - add the energy.
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
     * Amount of energy, that will be added.
     */
    int m_Energy;
};


#endif //HRYNTMAK_CENERGYACTION_H
