//
// Created by User on 09.05.2023.
//

#include "CMakeProgtest.h"

CMakeProgtest::CMakeProgtest(int electricityCost): m_ElectricityCost(electricityCost) {}

bool CMakeProgtest::changeStats(CState &stats) {
    if (stats.m_Electricity < m_ElectricityCost)
        m_ElectricityCost = stats.m_Electricity;
    stats.m_Electricity -= m_ElectricityCost;
    return true;
}

bool CMakeProgtest::changeProgtest(CProgtest &progtest) {
    return true;
}

bool CMakeProgtest::activate(CState &stats, CProgtest &progtest) {
    if (!changeStats(stats))
        return false;
    progtest.m_Progress += progtest.m_Complexity * stats.m_ProgrammingLevel * m_ElectricityCost / 2;
    stats.m_ProgrammingLevel += 0.2 * m_ElectricityCost / 100.0;
    return true;
}
