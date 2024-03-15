//
// Created by User on 09.05.2023.
//

#include "CBedBlock.h"
#include "../actions/CSkipDay.h"

CBedBlock::CBedBlock() : CBlock('B', -1, 0, 0, true) {}

std::unique_ptr<CAction> CBedBlock::action(std::unique_ptr<CBlock> &activeItem) {
    return std::make_unique<CSkipDay>();
}

bool CBedBlock::update() {
    return false;
}

bool CBedBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                        SPos                                               pos) {
    return false;
}

