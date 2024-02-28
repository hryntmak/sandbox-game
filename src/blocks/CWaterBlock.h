//
// Created by User on 16.05.2023.
//

#include "../CBlock.h"

#ifndef HRYNTMAK_CWATERBLOCK_H
#define HRYNTMAK_CWATERBLOCK_H

class CWaterBlock : public CBlock {
public:
    /**
     * Default constructor.
     */
    CWaterBlock();
    /**
     * Construct the instance with the specification of the source power.
     * @param sourcePower Number of blocks on which water can spread
     */
    explicit CWaterBlock(int sourcePower);
    /**
     * Takes energy
     * @param activeItem Block, which can be used for action
     * @return Action: -3 energy
     */
    std::unique_ptr<CAction> action(std::unique_ptr<CBlock> &activeItem) override;
    /**
     * Update only, if it is real source(source power = 2)
     * @return If True - Is a source. If False - isn't
     */
    bool update() override;
    /**
     * Refresh the block so that it can change the surrounding blocks.
     * Water can spread
     * @param map Reference to the map
     * @param pos Position of the block
     * @return True - Water has spread. False - Water hasn't change the map
     */
    bool refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map, SPos pos) override;
    /**
     * Print the block like for config file
     * @return Char of the block
     */
    void printConfig(std::ostream &out) const override;
private:
    /*
     * Number of blocks on which water can spread
     */
    int m_SourcePower;
};

#endif //HRYNTMAK_CWATERBLOCK_H
