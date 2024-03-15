//
// Created by User on 09.05.2023.
//

#include "CEnergyAction.h"

CEnergyAction::CEnergyAction(int energy) : m_Energy(energy) {}

bool CEnergyAction::changeStats(SState &stats) {
    stats.m_Energy += m_Energy;
    if (stats.m_Energy < 0) {
        stats.m_Lives--;
        stats.m_Energy = 0;
        return false;
    }
    if (stats.m_Energy > 999999) {
        stats.m_Energy = 999999;
        return false;
    }
    return true;
}

bool CEnergyAction::changeProgtest(SProgtest &progtest) {
    return false;
}
