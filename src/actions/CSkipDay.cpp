//
// Created by User on 09.05.2023.
//

#include "CSkipDay.h"

bool CSkipDay::changeStats(CState &stats) {
    stats.m_Energy += 30;
    if (stats.m_Energy > 100) {
        stats.m_Energy = 100;
        return false;
    }
    return true;
}

bool CSkipDay::changeProgtest(CProgtest &progtest) {
    progtest.m_Deadline--;
    return true;
}
