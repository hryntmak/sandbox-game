//
// Created by User on 08.05.2023.
//

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "CState.h"
#include "CBlock.h"
#include "CBlockAggregator.h"

#ifndef HRYNTMAK_CPLAYER_H
#define HRYNTMAK_CPLAYER_H


class CPlayer {
public:
    /**
     * Default constructor
     */
    CPlayer();
    /**
     * Construct CPlayer with configurations from input stream
     * @param in Input stream with configurations
     */
    explicit CPlayer(std::istream &in, CBlockAggregator aggregator);
    /**
     * Mine block. If can save it in the inventory
     * and replace the received block with CAirBlock.
     * @param block Unique pointer to the block ahead of the player
     * @return Success of the mine
     */
    bool mine(std::unique_ptr<CBlock> & block);
    /**
     * Interact with the block in front of the player.
     * @param block Unique pointer to the block ahead of the player
     * @return Action with block, which can be activate
     */
    std::unique_ptr<CAction> action(const std::unique_ptr<CBlock> & block, bool steppedOn);
    /**
     * If can replace the received block with active block in the player inventory.
     * @param block Unique pointer to the block ahead of the player
     * @return Success of the placement
     */
    bool placeBlock(std::unique_ptr<CBlock> & block);
    /**
     * Set m_Direction
     * @param direction New direction
     */
    void setDirection(const SPos &direction);
    void setActiveItem(int n);
    /**
     * Print player
     * @param out Output stream
     */
    void print(std::ostream &out) const;
    /**
     * Print player in the configuration file format
     * @param out Output stream
     */
    void printConfig(std::ostream &out) const;
    /**
     * Operator for print.
     * @param out Output stream.
     * @param player Player for print.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const CPlayer &player);
private:
    /*
     * Color of player icon.
     */
    std::string m_Color;
    /*
     * Player icon.
     */
    char m_Icon;
    /*
     * PLayer inventory.
     */
    std::unique_ptr<CBlock> m_Inventory[5];
    /*
     * Index of active item in the player inventory.
     */
    int m_ActiveItem;
    /*
     * Aggregator for creating blocks using a configuration file
     */
    CBlockAggregator m_Aggregator;
};


#endif //HRYNTMAK_CPLAYER_H
