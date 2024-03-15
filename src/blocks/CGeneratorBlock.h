//
// Created by User on 15.05.2023.
//

#ifndef HRYNTMAK_CGENERATORBLOCK_H
#define HRYNTMAK_CGENERATORBLOCK_H

#include "../CBlock.h"


/**
 * Descendant of an abstract class CBlock.
 * Implementation of the generator block.
 */
class CGeneratorBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CGeneratorBlock();
    /**
     * Burn the resulting block and return an action,
     * that will give an amount of electricity equivalent to the energy received when burning.
     * @param activeItem Block, that will be Burn
     * @return CBurn, that will give electricity when activated
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


#endif //HRYNTMAK_CGENERATORBLOCK_H
