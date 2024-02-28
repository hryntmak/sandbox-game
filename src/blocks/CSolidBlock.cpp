//
// Created by User on 14.05.2023.
//

#include "CSolidBlock.h"
#include "../actions/CNoAction.h"

CSolidBlock::CSolidBlock() = default;

CSolidBlock::CSolidBlock(char icon,
                         int  hardness,
                         int  energy,
                         int  toolLvl)
                         : CBlock(icon, hardness, energy, toolLvl, true) {}


std::unique_ptr<CAction> CSolidBlock::action(std::unique_ptr<CBlock> &activeItem) {
    return std::make_unique<CNoAction>();
}

bool CSolidBlock::update() {
    return false;
}

bool CSolidBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map, SPos pos) {
    return false;
}
