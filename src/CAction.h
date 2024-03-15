//
// Created by User on 09.05.2023.
//

#include "SState.h"
#include "SProgtest.h"

#ifndef HRYNTMAK_CACTION_H
#define HRYNTMAK_CACTION_H


/**
 * Abstract action class.
 * Can be activated in other class.
 */
class CAction {
public:
    /**
     * Make changes with stats and progtest
     * @param stats Reference to the changing stats
     * @param progtest Reference to the changing progtest
     * @return If has there been a change both
     */
    virtual bool activate(SState    &stats,
                          SProgtest &progtest);
    /**
     * Make changes with stats
     * @param stats Reference to the changing stats
     * @return If has there been a change
     */
    virtual bool changeStats(SState &stats) = 0;
    /**
     * Make changes with progtest
     * @param progtest Reference to the changing progtest
     * @return If has there been a change
     */
    virtual bool changeProgtest(SProgtest &progtest) = 0;

};


#endif //HRYNTMAK_CACTION_H
