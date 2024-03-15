//
// Created by User on 09.05.2023.
//

#include "CBurn.h"

CBurn::CBurn(int electricity) : m_Electricity(electricity) {}

bool CBurn::changeStats(SState &stats) {
    stats.m_Electricity += m_Electricity;
    if (stats.m_Electricity < 0) {
        stats.m_Electricity = 0;
        return false;
    }
    if (stats.m_Electricity > 999999) {
        stats.m_Electricity = 999999;
        return false;
    }
    return true;
}

bool CBurn::changeProgtest(SProgtest &progtest) {
    return false;
}
