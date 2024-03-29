//
// Created by User on 09.05.2023.
//

#include "../CAction.h"

#ifndef HRYNTMAK_CSKIPDAY_H
#define HRYNTMAK_CSKIPDAY_H


/**
 * Descendant of an abstract class CAction.
 * Implements skiping day.
 */
class CSkipDay : public CAction {
public:
    /**
     * Reduce the number of days before the deadline
     * @param stats Reference to the changing stats
     * @return Success of the action
     */
    bool changeStats(SState &stats) override;
    /**
     * Does nothing.
     * @param progtest Reference to the changing progtest
     * @return Always false.
     */
    bool changeProgtest(SProgtest &progtest) override;
};


#endif //HRYNTMAK_CSKIPDAY_H
