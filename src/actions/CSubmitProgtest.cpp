//
// Created by User on 09.05.2023.
//

#include "CSubmitProgtest.h"

bool CSubmitProgtest::changeStats(CState &stats) {
    return false;
}

bool CSubmitProgtest::changeProgtest(CProgtest &progtest) {
    return progtest.submit();
}

bool CSubmitProgtest::activate(CState &stats, CProgtest &progtest) {
    bool success = changeProgtest(progtest);
    if (progtest.m_RedFlag)
        stats.m_Lives--; // Take damage every time you submit a task if there is a red flag
    return success;
}
