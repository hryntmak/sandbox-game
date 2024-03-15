//
// Created by User on 09.05.2023.
//

#include "../CAction.h"

#ifndef HRYNTMAK_CSUBMITPROGTEST_H
#define HRYNTMAK_CSUBMITPROGTEST_H


/**
 * Descendant of an abstract class CAction.
 * Implements submiting progtest.
 */
class CSubmitProgtest : public CAction {
public:
    /**
     * Try to submit the progtest and
     * if have red flag deal 1 damage.
     * @param stats Reference to the changing stats
     * @param progtest Reference to the changing progtest
     * @return Success of the action
     */
    bool activate(SState    &stats,
                  SProgtest &progtest) override;
    /**
     * Does nothing.
     * @param stats Reference to the changing stats
     * @return Always false.
     */
    bool changeStats(SState &stats) override;
    /**
     * Try to submit the progtest.
     * @param progtest Reference to the changing progtest
     * @return Success of the action
     */
    bool changeProgtest(SProgtest &progtest) override;
};


#endif //HRYNTMAK_CSUBMITPROGTEST_H
