//
// Created by User on 09.05.2023.
//

#include "CTakeDamage.h"

CTakeDamage::CTakeDamage(int dmg) : m_Damage(dmg) {}

bool CTakeDamage::changeStats(SState &stats) {
    stats.m_Lives -= m_Damage;
    if (stats.m_Lives < 0)
        stats.m_Lives = 0;
    return true;
}

bool CTakeDamage::changeProgtest(SProgtest &progtest) {
    return false;
}
