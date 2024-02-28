//
// Created by User on 19.05.2023.
//

#include "CBlockAggregator.h"
#include "CConfig.h"
#include <fstream>

CBlockAggregator::CBlockAggregator() : m_PickaxeToolLevel(5) {}

CBlockAggregator::CBlockAggregator(const std::string & configFile) : m_PickaxeToolLevel(5) {
    std::string line;
    std::ifstream in(configFile);
    while (true) {
        std::getline(in, line);
        if (in.eof())
            break;
        if (line == "pickaxe:") {
            m_PickaxeToolLevel = CConfig::getInteger(in,"pickaxeToolLevel", 9999);
            return;
        }
    }
}

std::unique_ptr<CBlock>
CBlockAggregator::creatBlock(char c, SPos &playerPosition, SPos &playerDirection, SPos actualPosition) {
    switch (c) {
        case ' ': // Air
            return std::make_unique<CAirBlock>();
        case '#': // Dirt
            return std::make_unique<CSolidBlock>('#',0,0,0);
        case 'C': // Computer
            return std::make_unique<CComputerBlock>();
        case 'B': // Bed
            return std::make_unique<CBedBlock>();
        case '^': // Player
            playerPosition = actualPosition;
            playerDirection = {0,-1}; // up
            return std::make_unique<CAirBlock>();
        case 'v': // Player
            playerPosition = actualPosition;
            playerDirection = {0,1}; // down
            return std::make_unique<CAirBlock>();
        case '>': // Player
            playerPosition = actualPosition;
            playerDirection = {1,0}; // right
            return std::make_unique<CAirBlock>();
        case '<': // Player
            playerPosition = actualPosition;
            playerDirection = {-1,0}; // left
            return std::make_unique<CAirBlock>();
        case '-':
        case '+': // map border
        case '|':
            return std::make_unique<CSolidBlock>(c,-1,0,0); // hardness = -1  - is indestructible
        case '.': //Mushroom
        case '?':
            return std::make_unique<CMushroomBlock>(c);
        case 't': // Tree
        case 'T':
            return std::make_unique<CTreeBlock>(c);
        case 'G': // Generator
            return std::make_unique<CGeneratorBlock>();
        case '~': // Water
            return std::make_unique<CWaterBlock>(2);
        case '"': // Water
            return std::make_unique<CWaterBlock>(1);
        case '`': // Water
            return std::make_unique<CWaterBlock>(0);
        case '@': // Coal
            return std::make_unique<CSolidBlock>(c,3,60,0);
        case '/': // Pickaxe
            return std::make_unique<CSolidBlock>(c,0,15,m_PickaxeToolLevel);
        case 'R': // Rock
            return std::make_unique<CSolidBlock>(c,4,0,0);
        case 'x': // Corruption
            return std::make_unique<CCorruptionBlock>();
        default:
            throw std::logic_error("An unknown block was received");
    }
}

void CBlockAggregator::printConfig(std::ostream &out) const {
    out << "pickaxe:" << std::endl;
    out << "pickaxeToolLevel = " << m_PickaxeToolLevel << std::endl;
}
