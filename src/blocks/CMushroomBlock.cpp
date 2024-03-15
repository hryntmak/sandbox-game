//
// Created by User on 16.05.2023.
//

#include "CMushroomBlock.h"
#include "../actions/CNoAction.h"
#include "../actions/CEnergyAction.h"

CMushroomBlock::CMushroomBlock() : CBlock('.', 0, 0, 0, false),
                                   m_DayToGrowUp(1) {}

CMushroomBlock::CMushroomBlock(char c) : CBlock(c, 0, 0, 0, false),
                                         m_DayToGrowUp(1) {
    if (c == '?') {
        m_DayToGrowUp = 0;
        update();
    }
}

std::unique_ptr<CAction> CMushroomBlock::action(std::unique_ptr<CBlock> &activeItem) {
    return std::make_unique<CNoAction>();
}

bool CMushroomBlock::use(std::unique_ptr<CAction> &action) {
    if (m_DayToGrowUp == 0) {
        action = std::make_unique<CEnergyAction>(20); // add 20 to player energy
        return true;
    }
    action = std::make_unique<CNoAction>();
    return false;
}

bool CMushroomBlock::update() {
    m_DayToGrowUp--;
    if (m_DayToGrowUp <= 0) {
        m_DayToGrowUp = 0;
        m_Icon = '?';
        m_BurnEnergy = 5;
    }
    return true;
}

bool CMushroomBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                             SPos                                               pos) {
    return false;
}
