//
// Created by User on 16.05.2023.
//

#include "../CBlock.h"

#ifndef HRYNTMAK_CMUSHROOMBLOCK_H
#define HRYNTMAK_CMUSHROOMBLOCK_H

class CMushroomBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CMushroomBlock();
    /**
     * Construct the instance with the char,
     * that specifies whether the tree has grown.
     * '?' - old tree, have 40 burn energy;
     * '.' - young tree, have 5 burn energy.
     * @param c Char, that specifies whether the tree has grown
     */
    explicit CMushroomBlock(char c);
    /**
     * Does nothing.
     * @param activeItem Block, that will not be used for this action
     * @return CNoAction - does nothing.
     */
    std::unique_ptr<CAction> action(std::unique_ptr<CBlock> &activeItem) override;
    /**
     * Uses the mushroom and returns the action.
     * If it has grown once it gives 20 energy and returns True (so the block must be deleted),
     * if hasn't grown return false (the block must remain).
     * @param action Action, that give 20 energy(CEnergyAction(20)) or CNoAction
     * @return A sign that the item has been used or out of the usage possibilities
     */
    bool use(std::unique_ptr<CAction> & action) override;
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

#endif //HRYNTMAK_CMUSHROOMBLOCK_H
