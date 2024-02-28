//
// Created by User on 19.05.2023.
//

#include <iostream>
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
#include "blocks/CCorruptionBlock.h"

#ifndef HRYNTMAK_CBLOCKAGGREGATOR_H
#define HRYNTMAK_CBLOCKAGGREGATOR_H


class CBlockAggregator {
public:
    /**
     * Default constructor;
     */
    CBlockAggregator();
    /**
     * Construct the instance with information from config file.
     * @param configFile Path to the config file
     */
    explicit CBlockAggregator(const std::string & configFile);
    /**
     * Returns a unique pointer to the block, that corresponds to this char.
     * If the char corresponds to the player, then return a pointer
     * to the CAirBlock and write Player position and direction
     * @param c Char on which the returned block depends
     * @param playerPosition Reference to the Player position
     * @param playerDirection Reference to the Player direction
     * @param actualPosition Actual position of the block/char
     * @return Pointer to the block
     */
    std::unique_ptr<CBlock> creatBlock(char c,
                                       SPos &playerPosition,
                                       SPos &playerDirection,
                                       SPos actualPosition);
    /**
     * Print map in the configuration file format
     * @param out Output stream.
     * @return Reference to the output stream.
     */
    void printConfig(std::ostream &out) const;
private:
    int m_PickaxeToolLevel;
};


#endif //HRYNTMAK_CBLOCKAGGREGATOR_H
