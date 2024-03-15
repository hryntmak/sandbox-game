//
// Created by User on 09.05.2023.
//

#include "../CAction.h"

#ifndef HRYNTMAK_NOACTION_H
#define HRYNTMAK_NOACTION_H


/**
 * Descendant of an abstract class CAction.
 * Implements an action that does nothing.
 */
class CNoAction : public CAction {
public:
    /**
     * Does nothing.
     * @param stats Reference to the changing stats
     * @return Always false.
     */
    bool changeStats(SState &stats) override;
    /**
     * Does nothing.
     * @param progtest Reference to the changing progtest
     * @return Always false.
     */
    bool changeProgtest(SProgtest &progtest) override;
};


#endif //HRYNTMAK_NOACTION_H
