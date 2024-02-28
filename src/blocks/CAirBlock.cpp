//
// Created by User on 09.05.2023.
//

#include "CAirBlock.h"
#include "../actions/CNoAction.h"

CAirBlock::CAirBlock() : CBlock(' ', -1, 0, 0, false) {

}

std::unique_ptr<CAction> CAirBlock::action(std::unique_ptr<CBlock> &activeItem) {
    return std::make_unique<CNoAction>();
}

bool CAirBlock::update() {
    return false;
}

bool CAirBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map, SPos pos) {
    return false;
}
