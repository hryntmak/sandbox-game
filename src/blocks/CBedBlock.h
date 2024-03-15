//
// Created by User on 09.05.2023.
//

#include "../CBlock.h"

#ifndef HRYNTMAK_CBEDBLOCK_H
#define HRYNTMAK_CBEDBLOCK_H


/**
 * Descendant of an abstract class CBlock.
 * Implementation of the bed block.
 * Implements sleeping.
 */
class CBedBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CBedBlock();
    /**
     * Sleeps, which skips the day, updates the map and gives 40 energy to the player.
     * @param activeItem Block, that will not be used for this action
     * @return CSkipDay
     */
    std::unique_ptr<CAction> action(std::unique_ptr<CBlock> &activeItem) override;
    /**
     * Does nothing.
     * @return Always false.
     */
    bool update() override;
    /**
     * Does nothing.
     * @param map Reference to the map
     * @param pos Position of the block
     * @return Always false
     */
    bool refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                 SPos                                               pos) override;
};


#endif //HRYNTMAK_CBEDBLOCK_H
