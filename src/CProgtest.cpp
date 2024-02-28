//
// Created by User on 08.05.2023.
//

#include "CProgtest.h"
#include "CConfig.h"
#include <random>

CProgtest::CProgtest(std::istream &in) {
    m_Complexity        = CConfig::getDouble(in, "Complexity", 10);
    m_Score             = CConfig::getDouble(in, "Score", 100);
    m_CheatingSuspicion = CConfig::getDouble(in, "CheatingSuspicion", 100);
    m_Progress          = CConfig::getDouble(in, "Progress", 100);
    m_Deadline          = CConfig::getInteger(in, "Deadline");
    m_Attempts          = CConfig::getInteger(in, "Attempts");
    m_MaxAttempts       = CConfig::getInteger(in, "MaxAttempts");
    m_RedFlag           = CConfig::getInteger(in, "RedFlag", 1) == 1;
    std::cout << "Progtest has been configured" << std::endl;
}

bool CProgtest::submit() {
    m_Attempts++;
    std::random_device random;
    std::default_random_engine gen(random());
    // A chance to get a red flag. Unlucky :(
    std::discrete_distribution<> discreteCheating({m_CheatingSuspicion, 100.0 - m_CheatingSuspicion });
    // A 5% chance to get +0.5 score. Lucky :)
    std::discrete_distribution<> discreteScore({ 5, 100 });
    m_CheatingSuspicion = m_CheatingSuspicion < 100 ? m_CheatingSuspicion + 0.5 : 0;
    m_RedFlag = m_RedFlag ? m_RedFlag : discreteCheating(gen) == 0; // Roll red flag
    double tmpScore = 5.5 * m_Progress / 100.0; // Calculate score
    m_Score = m_Score > tmpScore ? m_Score : tmpScore;
    m_Score += discreteScore(gen) == 0 ? 0.5 : 0; // Roll random bonus +0.5 score
    return true;
}

std::ostream &operator<<(std::ostream &out, const CProgtest &progtest) {
    out << "progtest:" << std::endl;
    out << "Complexity = " << progtest.m_Complexity << std::endl;
    out << "Score = " << progtest.m_Score << std::endl;
    out << "CheatingSuspicion = " << progtest.m_CheatingSuspicion << std::endl;
    out << "Progress = " << progtest.m_Progress << std::endl;
    out << "Deadline = " << progtest.m_Deadline << std::endl;
    out << "Attempts = " << progtest.m_Attempts << std::endl;
    out << "MaxAttempts = " << progtest.m_MaxAttempts << std::endl;
    out << "RedFlag = " << progtest.m_RedFlag << std::endl;
    return out;
}
