//
// Created by User on 24.05.2023.
//

#include "CCorruptionBlock.h"
#include "../actions/CTakeDamage.h"
#include <random>

CCorruptionBlock::CCorruptionBlock() : CBlock('x',-1,0,0, false) {}

std::unique_ptr<CAction> CCorruptionBlock::action(std::unique_ptr<CBlock> &activeItem) {
    return std::make_unique<CTakeDamage>(1); // Walking in water deal 1 damage
}

bool CCorruptionBlock::update() {
    return true;
}

bool CCorruptionBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                               SPos                                               pos) {
    std::random_device random;
    std::default_random_engine gen(random());
    // 5% chance to spread
    std::discrete_distribution<> roll({ 5, 95 });

    if ((!map[pos.y][pos.x-1]->isSolid()
      || (map[pos.y][pos.x-1]->getHardness() >= 0  // check the block on the left
      &&  map[pos.y][pos.x-1]->getHardness() < 3))
      &&  roll(gen) == 0)
        map[pos.y][pos.x-1] = std::make_unique<CCorruptionBlock>();

    if ((!map[pos.y][pos.x+1]->isSolid()
     || (map[pos.y][pos.x+1]->getHardness() >= 0  // check the block on the right
     &&  map[pos.y][pos.x+1]->getHardness() < 3))
     &&  roll(gen) == 0)
        map[pos.y][pos.x+1] = std::make_unique<CCorruptionBlock>();

    if ((!map[pos.y-1][pos.x]->isSolid()
      || (map[pos.y-1][pos.x]->getHardness() >= 0  // check the block on the top
      &&  map[pos.y-1][pos.x]->getHardness() < 3))
      &&  roll(gen) == 0)
        map[pos.y-1][pos.x] = std::make_unique<CCorruptionBlock>();

    if ((!map[pos.y+1][pos.x]->isSolid()
      || (map[pos.y+1][pos.x]->getHardness() >= 0  // check the block on the bottom
      &&  map[pos.y+1][pos.x]->getHardness() < 3))
      &&  roll(gen) == 0)
        map[pos.y+1][pos.x] = std::make_unique<CCorruptionBlock>();

    return true;
}
