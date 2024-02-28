//
// Created by User on 09.05.2023.
//

#include "../CAction.h"

#ifndef HRYNTMAK_NOACTION_H
#define HRYNTMAK_NOACTION_H


class CNoAction : public CAction {
public:
    /**
     * Does nothing.
     * @param stats Reference to the changing stats
     * @return Always false.
     */
    bool changeStats(CState &stats) override;
    /**
     * Does nothing.
     * @param progtest Reference to the changing progtest
     * @return Always false.
     */
    bool changeProgtest(CProgtest &progtest) override;
};


#endif //HRYNTMAK_NOACTION_H
