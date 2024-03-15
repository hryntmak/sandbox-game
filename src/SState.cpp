//
// Created by User on 08.05.2023.
//

#include "SState.h"
#include "CConfig.h"

SState::SState() = default;

SState::SState(std::istream &in) {
    m_Lives            = CConfig::getInteger(in, "Lives", 10000);
    m_Energy           = CConfig::getInteger(in, "Energy", 999999);
    m_Electricity      = CConfig::getInteger(in, "Electricity", 999999);
    m_ProgrammingLevel = CConfig::getDouble(in, "ProgrammingLevel", 100);
    std::cout << "State has been configured" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const SState &state) {
    out << "stats:" << std::endl;
    out << "Lives = " << state.m_Lives << std::endl;
    out << "Energy = " << state.m_Energy << std::endl;
    out << "Electricity = " << state.m_Electricity << std::endl;
    out << "ProgrammingLevel = " << state.m_ProgrammingLevel << std::endl;
    return out;
}
