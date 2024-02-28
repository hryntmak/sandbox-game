//
// Created by User on 15.05.2023.
//

#include "CGeneratorBlock.h"
#include "../actions/CBurn.h"
#include "../blocks/CAirBlock.h"

CGeneratorBlock::CGeneratorBlock() : CBlock('G', -1, 0, 0, true) {}

std::unique_ptr<CAction> CGeneratorBlock::action(std::unique_ptr<CBlock> &activeItem) {
    int energy = activeItem->getBurnEnergy();
    activeItem = nullptr;
    return std::make_unique<CBurn>(energy);
}

bool CGeneratorBlock::update() {
    return false;
}

bool CGeneratorBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map, SPos pos) {
    return false;
}
