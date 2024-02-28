//
// Created by User on 14.05.2023.
//

#include "../CBlock.h"

#ifndef HRYNTMAK_CSOLIDBLOCK_H
#define HRYNTMAK_CSOLIDBLOCK_H


class CSolidBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CSolidBlock();
    /**
     * Construct the instance with icon, color, hardness, energy and tool level.
     * @param icon Char for icon
     * @param hardness Integer for hardness, if -1, then the block is indestructible
     * @param energy Integer for energy
     * @param toolLvl Integer for tool level
     */
    CSolidBlock(char icon,
                int hardness,
                int energy,
                int toolLvl);
    /**
     * Does nothing.
     * @param activeItem Block, that will not be used for this action
     * @return CNoAction - does nothing.
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
     * @return Always False - hasn't change the map
     */
    bool refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map, SPos pos) override;
};


#endif //HRYNTMAK_CSOLIDBLOCK_H