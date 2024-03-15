//
// Created by User on 09.05.2023.
//

#include "../CBlock.h"

#ifndef HRYNTMAK_CCOMPUTERBLOCK_H
#define HRYNTMAK_CCOMPUTERBLOCK_H


/**
 * Descendant of an abstract class CBlock.
 * Implementation of the computer block.
 * Implements communication with the user, allowing to work on a progtest or try to submit it.
 */
class CComputerBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CComputerBlock();
    /**
     * Starts communication with the user,
     * gives the opportunity to work on the progtest, try to submit it or cancel the action.
     * @param activeItem Block, that will not be used for this action
     * @return CMakeProgtest, CSubmitProgtest or CNoAction
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


#endif //HRYNTMAK_CCOMPUTERBLOCK_H
