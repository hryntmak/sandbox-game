//
// Created by User on 16.05.2023.
//

#include "CWaterBlock.h"
#include "../actions/CNoAction.h"
#include "../actions/CEnergyAction.h"


CWaterBlock::CWaterBlock() : CBlock('~', -1, 0, 0, false),
                             m_SourcePower(2) {}

CWaterBlock::CWaterBlock(int sourcePower) : CBlock('~', -1, 0, 0, false),
                                            m_SourcePower(sourcePower) {}

std::unique_ptr<CAction> CWaterBlock::action(std::unique_ptr<CBlock> &activeItem) {
    return std::make_unique<CEnergyAction>(-3); // Walking in water takes energy
}

bool CWaterBlock::update() {
    if (m_SourcePower == 2)
        return true;
    return false;
}

bool CWaterBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                          SPos                                               pos) {
    if (m_SourcePower == 0)
        return false;

    if (!map[pos.y][pos.x-1]->isSolid()
     && !map[pos.y][pos.x-1]->update()) // check the block on the left
        map[pos.y][pos.x-1] = std::make_unique<CWaterBlock>(m_SourcePower - 1);

    if (!map[pos.y][pos.x+1]->isSolid()
     && !map[pos.y][pos.x+1]->update()) // check the block on the right
        map[pos.y][pos.x+1] = std::make_unique<CWaterBlock>(m_SourcePower - 1);

    if (!map[pos.y-1][pos.x]->isSolid()
     && !map[pos.y-1][pos.x]->update()) // check the block on the top
        map[pos.y-1][pos.x] = std::make_unique<CWaterBlock>(m_SourcePower - 1);

    if (!map[pos.y+1][pos.x]->isSolid()
     && !map[pos.y+1][pos.x]->update()) // check the block on the bottom
        map[pos.y+1][pos.x] = std::make_unique<CWaterBlock>(m_SourcePower - 1);

    return true;
}

void CWaterBlock::printConfig(std::ostream &out) const {
    switch (m_SourcePower) {
        case 2:
            out << '~';
            break;
        case 1:
            out << '"';
            break;
        case 0:
            out << '`';
    }
}
