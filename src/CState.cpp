//
// Created by User on 08.05.2023.
//

#include "CState.h"
#include "CConfig.h"

CState::CState() = default;

CState::CState(std::istream &in) {
    m_Lives            = CConfig::getInteger(in, "Lives", 10000);
    m_Energy           = CConfig::getInteger(in, "Energy", 10000);
    m_Electricity      = CConfig::getInteger(in, "Electricity", 10000);
    m_ProgrammingLevel = CConfig::getDouble(in, "ProgrammingLevel", 100);
    std::cout << "State has been configured" << std::endl;
}
//stats:
//Lives = 5
//Energy = 100
//Electricity = 100
//ProgrammingLevel = 1
std::ostream &operator<<(std::ostream &out, const CState &state) {
    out << "stats:" << std::endl;
    out << "Lives = " << state.m_Lives << std::endl;
    out << "Energy = " << state.m_Energy << std::endl;
    out << "Electricity = " << state.m_Electricity << std::endl;
    out << "ProgrammingLevel = " << state.m_ProgrammingLevel << std::endl;
    return out;
}
