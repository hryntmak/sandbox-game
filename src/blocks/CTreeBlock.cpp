//
// Created by User on 15.05.2023.
//

#include "CTreeBlock.h"
#include "../actions/CNoAction.h"

CTreeBlock::CTreeBlock() : CBlock('t', 0, 5, 0, false),
                           m_DayToGrowUp(3) {}

CTreeBlock::CTreeBlock(char c) : CBlock(c, 0, 5, 0, true),
                                 m_DayToGrowUp(3) {
    if (c == 'T') {
        m_DayToGrowUp = 0;
        update();
    }
}

std::unique_ptr<CAction> CTreeBlock::action(std::unique_ptr<CBlock> &activeItem) {
    return std::make_unique<CNoAction>();
}

bool CTreeBlock::update() {
    m_DayToGrowUp--;
    if (m_DayToGrowUp <= 0) {
        m_DayToGrowUp = 0;
        m_Icon = 'T';
        m_BurnEnergy = 40;
        m_IsSolid = true;
    }
    return true;
}

bool CTreeBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                         SPos                                               pos) {
    return false;
}
