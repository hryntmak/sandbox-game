//
// Created by User on 09.05.2023.
//

#include "../CAction.h"

#ifndef HRYNTMAK_CBURN_H
#define HRYNTMAK_CBURN_H


class CBurn : public CAction {
public:
    /**
     * Constructs an action with the amount of electricity,
     * that will be added.
     * @param electricity Amount of electricity, that will be added
     */
    explicit CBurn(int electricity = 0);
    /**
     * If can - add the electricity.
     * @param stats Reference to the changing stats
     * @return Success of the action.
     */
    bool changeStats(CState &stats) override;
    /**
     * Does nothing.
     * @param progtest Reference to the changing progtest
     * @return Always false.
     */
    bool changeProgtest(CProgtest &progtest) override;
private:
    int m_Electricity;
};


#endif //HRYNTMAK_CBURN_H
