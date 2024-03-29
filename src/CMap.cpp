//
// Created by User on 08.05.2023.
//

#include "CMap.h"
#include "actions/CEnergyAction.h"
#include <random>


CMap::CMap() = default;

CMap::CMap(std::istream &in, CBlockAggregator aggregator) : m_Aggregator(aggregator) {
    bool isComputer  = false; // Is computer on the map
    bool isGenerator = false; // Is generator on the map
    bool isBed       = false; // Is bed on the map
    bool isPlayer    = false; // Is player on the map
    std::string line;
    size_t mapLength = 0;
    int row = -1;
    char c;
    in >> c;
    if (c != '+') throw std::logic_error("Excepted '+' in the map configuration.");

    m_Map.emplace_back(); // add new row
    row++;

    m_Map[row].emplace_back(m_Aggregator.creatBlock(c,
                            m_PlayerPosition,
                            m_PlayerDirection,
                            SPos(mapLength, row)));
    std::getline(in, line);
    for (char ch : line) {
        if (ch == '+') { // End of the row
            m_Map[row].emplace_back(m_Aggregator.creatBlock(ch,
                                    m_PlayerPosition,
                                    m_PlayerDirection,
                                    SPos(mapLength, row)));
            break;
        }
        mapLength++;

        if (ch != '-') throw std::logic_error("Excepted '-' in the map configuration.");

        m_Map[row].emplace_back(m_Aggregator.creatBlock(ch,
                                m_PlayerPosition,
                                m_PlayerDirection,
                                SPos(mapLength, row)));
    }

    if (line[mapLength] != '+') throw std::logic_error("Excepted '+' on the end of the map configuration.");

    while (true) {
        m_Map.emplace_back(); // Add new row
        row++;
        std::getline(in, line);
        if (line.size() >= mapLength + 2
         && line[0]     == '|') {
            for (size_t column = 0; column < mapLength + 1; ++column) {
                if (line[column] == 'C') isComputer  = true;
                if (line[column] == 'G') isGenerator = true;
                if (line[column] == 'B') isBed       = true;
                if (line[column] == '>'
                 || line[column] == '<'
                 || line[column] == 'v'
                 || line[column] == '^') {
                    if (isPlayer) throw std::logic_error("Second player ont the map.");
                    isPlayer = true;
                }
                m_Map[row].emplace_back(m_Aggregator.creatBlock(line[column],
                                                                m_PlayerPosition,
                                                                m_PlayerDirection,
                                                                SPos(column, row)));
            }
            if (line[mapLength + 1] != '|')
                throw std::logic_error("Excepted '|' on the end of line in the map configuration.");
            m_Map[row].emplace_back(m_Aggregator.creatBlock(line[mapLength + 1],
                                                            m_PlayerPosition,
                                                            m_PlayerDirection,
                                                            SPos(0, row)));
        } else if (line.size() >= mapLength + 2
                && line[0]     == '+'
                && row         != 1) {
            line.resize(mapLength + 2); // If there are comments to the right of the map
            if (line != "+" + std::string(mapLength, '-') + "+")
                throw std::logic_error("Excepted end line of the map configuration.");
            for (size_t i = 0; i < mapLength + 2; i++) {
                m_Map[row].emplace_back(m_Aggregator.creatBlock(line[i],
                                                                m_PlayerPosition,
                                                                m_PlayerDirection,
                                                                SPos(0, row)));
            }
            if (!isComputer
             || !isGenerator
             || !isBed) throw std::logic_error("There is no computer, generator or bed on the map");
            if (m_PlayerDirection == SPos(0,0))
                throw std::logic_error("There is no player on the map");
            std::cout << "Map has been configured." << std::endl;
            return;
        } else
            throw std::logic_error("Excepted '|' on the begin of line in the map configuration.");
    }
}


bool CMap::mine() {
    return m_Player.mine(getBlockAhead());
}

std::unique_ptr<CAction> CMap::action(bool steppedOn) {
    // Interact with the block ahead
    if (!steppedOn)
        return m_Player.action(getBlockAhead(), steppedOn);
    // Interact with the block that has been stepped on
    return m_Player.action(m_Map[m_PlayerPosition.y][m_PlayerPosition.x], steppedOn);
}

bool CMap::placeBlock() {
    return m_Player.placeBlock(getBlockAhead());
}

std::unique_ptr<CAction> CMap::move(SPos direction) {
    std::random_device random;
    std::default_random_engine gen(random());
    // 40% chance to spend energy while moving
    std::discrete_distribution<> roll({40, 60} );

    if (m_PlayerDirection != direction) { // Check, if we are turning around
        m_PlayerDirection = direction;
        m_Player.setDirection(direction);
        return std::make_unique<CEnergyAction>(0); // Don't spend energy, when turning around
    }

    if (getBlockAhead()->isSolid())
        return std::make_unique<CEnergyAction>(0);

    m_PlayerPosition = m_PlayerPosition + m_PlayerDirection;

    return std::make_unique<CEnergyAction>(roll(gen) == 0 ? -1 : 0);
}

std::unique_ptr<CBlock> &CMap::getBlockAhead() {
    SPos blockPos = m_PlayerPosition + m_PlayerDirection;
    return m_Map[blockPos.y][blockPos.x];
}

void CMap::update() {
    for (auto & row : m_Map) {
        for (auto & block : row) {
            block->update();
        }
    }
}

void CMap::refresh() {
    for (size_t y = 0; y < m_Map.size(); ++y) {
        for (size_t x = 0; x < m_Map[y].size(); ++x) {
            m_Map[y][x]->refresh(m_Map, SPos(x, y));
        }
    }
}

void CMap::setActiveItem(int n) {
    m_Player.setActiveItem(n);
}

void CMap::setPlayer(CPlayer player) {
    m_Player = std::move(player);
}

std::ostream &operator<<(std::ostream &out,
                         const CMap   &map) {
    for (size_t y = 0; y < map.m_Map.size(); ++y) {
        for (size_t x = 0; x < map.m_Map[y].size(); ++x) {
            if ( map.m_PlayerPosition == SPos(x, y) ) {
                map.m_Player.print(out);
                continue;
            }
            out << *map.m_Map[y][x];
        }
        out << std::endl;
    }
    out << std::endl << map.m_Player;
    return out;
}

void CMap::printConfig(std::ostream &out) const {
    for (size_t y = 0; y < m_Map.size(); ++y) {
        for (size_t x = 0; x < m_Map[y].size(); ++x) {
            if ( m_PlayerPosition == SPos(x, y) ) {
                m_Player.print(out);
                continue;
            }
            m_Map[y][x]->printConfig(out);
        }
        out << std::endl;
    }
    m_Player.printConfig(out);
}
