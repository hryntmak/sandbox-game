//
// Created by User on 15.05.2023.
//

#include "../CBlock.h"

#ifndef HRYNTMAK_CTREEBLOCK_H
#define HRYNTMAK_CTREEBLOCK_H


class CTreeBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CTreeBlock();
    /**
     * Construct the instance with the char,
     * that specifies whether the tree has grown.
     * 'T' - old tree, have 40 burn energy;
     * 't' - young tree, have 5 burn energy.
     * @param c Char, that specifies whether the tree has grown
     */
    explicit CTreeBlock(char c);
    /**
     * Does nothing.
     * @param activeItem Block, that will not be used for this action
     * @return CNoAction - does nothing.
     */
    std::unique_ptr<CAction> action(std::unique_ptr<CBlock> &activeItem) override;
    /**
     * Reduces the number of days before the tree grows
     * @return If True - The update was carried out. If False - it wasn't
     */
    bool update() override;
    /**
     * Does nothing.
     * @param map Reference to the map
     * @param pos Position of the block
     * @return Always false
     */
    bool refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map, SPos pos) override;
private:
    /*
     * Number of days before the tree grows
     */
    int m_DayToGrowUp;
};


#endif //HRYNTMAK_CTREEBLOCK_H
