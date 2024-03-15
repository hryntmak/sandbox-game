//
// Created by User on 09.05.2023.
//

#include "../CAction.h"

#ifndef HRYNTMAK_CMAKEPROGTEST_H
#define HRYNTMAK_CMAKEPROGTEST_H


/**
 * Descendant of an abstract class CAction.
 * Implements making progtest.
 */
class CMakeProgtest : public CAction {
public:
    /**
     * Constructs an action with the amount of electricity,
     * that will be used for work on progtest, when activated.
     * @param electricityCost amount of electricity for work on progtest
     */
    explicit CMakeProgtest(int electricityCost = 10);
    /**
     * Increase progress in proportion to the electricity taken away.
     * @param stats Reference to the changing stats
     * @param progtest Reference to the changing progtest
     * @return Success of the action
     */
    bool activate(SState    &stats,
                  SProgtest &progtest) override;
    /**
     * If can - take away amount of electricity.
     * @param stats Reference to the changing stats
     * @return Success of  the action.
     */
    bool changeStats(SState &stats) override;
    /**
     * Does nothing.
     * @param progtest Reference to the changing progtest
     * @return Always true.
     */
    bool changeProgtest(SProgtest &progtest) override;
private:
    /**
     * Amount of electricity, that will be used for work on progtest.
     */
    int m_ElectricityCost;
};


#endif //HRYNTMAK_CMAKEPROGTEST_H
