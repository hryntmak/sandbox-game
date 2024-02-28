//
// Created by User on 09.05.2023.
//

#include "../CBlock.h"

#ifndef HRYNTMAK_CAIRBLOCK_H
#define HRYNTMAK_CAIRBLOCK_H


class CAirBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CAirBlock();
    /**
     * Does nothing.
     * @param activeItem Block, that will not be used for this action
     * @return CNoAction
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
    bool refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map, SPos pos) override;
};


#endif //HRYNTMAK_CAIRBLOCK_H
