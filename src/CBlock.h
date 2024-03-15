//
// Created by User on 08.05.2023.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "SState.h"
#include "SProgtest.h"
#include "SPos.h"
#include "CAction.h"

#ifndef HRYNTMAK_CBLOCK_H
#define HRYNTMAK_CBLOCK_H


/**
 * Abstract block class.
 */
class CBlock {
public:
    /**
     * Default constructor.
     */
    CBlock() = default;
    /**
     * Construct the instance with icon, color, hardness, energy, tool level and flag 'isSolid'.
     * @param icon Char for icon
     * @param hardness Integer for hardness
     * @param energy Integer for energy
     * @param toolLvl Integer for tool level
     * @param isSolid Bool, true - is solid, false - isn't solid
     */
    CBlock(char icon,
           int  hardness,
           int  energy,
           int  toolLvl,
           bool isSolid);

    /**
     * Performs actions with the block
     * @param activeItem Block, which can be used for action
     * @return Action
     */
    virtual std::unique_ptr<CAction> action(std::unique_ptr<CBlock> &activeItem) = 0;

    /**
     * Update block
     * @return If True - The update was carried out. If False - it wasn't
     */
    virtual bool update() = 0;

    /**
     * Refresh the block so that it can change the surrounding blocks
     * @param map Reference to the map
     * @param pos Position of the block
     * @return True - block has changed the map next to the block. False - hasn't change the map
     */
    virtual bool refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                         SPos                                               pos) = 0;

    /**
     * Uses the item(Block) and returns the action.
     * Designed for the use of items in the inventory.
     * @param action Action received after use
     * @return A sign that the item has been used or out of the usage possibilities
     */
    virtual bool use(std::unique_ptr<CAction> & action);

    /**
     * Print the block like for config file
     * @return Char of the block
     */
    virtual void printConfig(std::ostream &out) const;

    /**
     * Say, if the block is solid
     * @return True - is solid, False - isn't solid
     */
    bool isSolid() const;

    /**
     * Get hardness number of block
     * @return Hardness number
     */
    int getHardness() const;

    /**
     * Get how much energy will be obtained by burning the block
     * @return Amount of energy
     */
    int getBurnEnergy() const;

    /**
     * Get tool level of block
     * @return tool level
     */
    int getToolLevel() const;
    /**
     * Operator for print.
     * @param out Output stream.
     * @param player Block for print.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out,
                                    const CBlock &block);

protected:
    /**
     * Char icon of block.
     */
    char m_Icon;
    /**
     * Hardness of the block
     */
    int m_Hardness;
    /**
     * Amount of energy obtained by burning
     */
    int m_BurnEnergy;
    /**
     * Tool level for blocks that are used as a tool
     */
    int m_ToolLevel;
    /**
     * Flag, true - is solid, false - isn't solid
     */
    bool m_IsSolid;
};


#endif //HRYNTMAK_CBLOCK_H
