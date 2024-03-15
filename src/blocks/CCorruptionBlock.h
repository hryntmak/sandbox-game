//
// Created by User on 24.05.2023.
//

#include "../CBlock.h"

#ifndef HRYNTMAK_CCORRUPTIONBLOCK_H
#define HRYNTMAK_CCORRUPTIONBLOCK_H


/**
 * Descendant of an abstract class CBlock.
 * Implementation of the corruption block.
 * Can spread with 5% chance and deal damage, if player contact it.
 */
class CCorruptionBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CCorruptionBlock();
    /**
     * Deal damage.
     * @param activeItem Block, which can be used for action
     * @return Action: -1 live
     */
    std::unique_ptr<CAction> action(std::unique_ptr<CBlock> &activeItem) override;
    /**
     * Does nothing.
     * @return Always true.
     */
    bool update() override;
    /**
     * Refresh the block so that it can change the surrounding blocks.
     * Corruption can spread with 5% chance to not solid blocks
     * or to blocks with a hardness between 0 and 3.
     * @param map Reference to the map
     * @param pos Position of the block
     * @return True - Corruption has spread. False - Corruption hasn't change the map
     */
    bool refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                 SPos                                               pos) override;
};


#endif //HRYNTMAK_CCORRUPTIONBLOCK_H
