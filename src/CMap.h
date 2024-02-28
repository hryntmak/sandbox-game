//
// Created by User on 08.05.2023.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "CBlock.h"
#include "SPos.h"
#include "blocks/CBedBlock.h"
#include "blocks/CAirBlock.h"
#include "blocks/CComputerBlock.h"
#include "blocks/CSolidBlock.h"
#include "blocks/CGeneratorBlock.h"
#include "blocks/CMushroomBlock.h"
#include "blocks/CTreeBlock.h"
#include "blocks/CWaterBlock.h"
#include "CBlockAggregator.h"
#include "CPlayer.h"

#ifndef HRYNTMAK_CMAP_H
#define HRYNTMAK_CMAP_H


class CMap {
public:
    /**
     * Default constructor.
     */
    CMap();
    /**
     * Construct Map with config from input stream.
     * @param in Input stream.
     */
    explicit CMap(std::istream &in, CBlockAggregator aggregator);
    void setPlayer(CPlayer player);
    /**
     * Return unique pointer to the block ahead of the player
     * @return Unique pointer to the block ahead of the player
     */
    std::unique_ptr<CBlock> &getBlockAhead();
    /**
     * Update all blocks on the map
     * @return Success of the update
     */
    void update();
    /**
     * Refresh all blocks on the map
     * @return Success of the refreshing
     */
    void refresh();
    /**
     * Will make the player mine
     * @return Success of the mine
     */
    bool mine();
    /**
     * Will make the player interact with the block in front of him
     * @return Received action after interaction with block
     */
    std::unique_ptr<CAction> action(bool steppedOn);
    /**
     * Move the player
     * @param direction Direction of movement
     * @return Success of the movement
     */
    std::unique_ptr<CAction> move(SPos direction);
    /**
     * Will make the player place active block from his inventory
     * @return Success of the placement
     */
    bool placeBlock();
    /**
     * Set number of the active item in the inventory
     * @param n New number of active item
     */
    void setActiveItem(int n);
    /**
     * Print map in the configuration file format
     * @param out Output stream.
     * @return Reference to the output stream.
     */
    void printConfig(std::ostream &out) const;
    /**
     * Operator for print.
     * @param out Output stream.
     * @param map Map for print.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const CMap &map);

private:
    /*
     * A double vector of blocks implementing the map.
     */
    std::vector<std::vector<std::unique_ptr<CBlock>>> m_Map;
    /*
     * Player on the map.
     */
    CPlayer m_Player;
    /*
     * Position of player on the map.
     */
    SPos m_PlayerPosition;
    /*
     * Direction of player.
     */
    SPos m_PlayerDirection;
    /*
     * Aggregator for creating blocks using a configuration file
     */
    CBlockAggregator m_Aggregator;
};


#endif //HRYNTMAK_CMAP_H
