//
// Created by User on 08.05.2023.
//

#include "CBlock.h"
#include "memory"

#include <utility>

int CBlock::getHardness() const {
    return m_Hardness;
}

int CBlock::getBurnEnergy() const {
    return m_BurnEnergy;
}

int CBlock::getToolLevel() const {
    return m_ToolLevel;
}

CBlock::CBlock(char icon,
               int  hardness,
               int  energy,
               int  toolLvl,
               bool isSolid) : m_Icon(icon),
                               m_Hardness(hardness),
                               m_BurnEnergy(energy),
                               m_ToolLevel(toolLvl),
                               m_IsSolid(isSolid) {}

bool CBlock::isSolid() const {
    return m_IsSolid;
}

bool CBlock::use(std::unique_ptr<CAction> &action) {
    return false;
}

void CBlock::printConfig(std::ostream &out) const {
    out << m_Icon;
}

std::ostream &operator<<(std::ostream &out,
                         const CBlock &block) {
    out << block.m_Icon;
    return out;
}
