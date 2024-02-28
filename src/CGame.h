//
// Created by User on 08.05.2023.
//

#include <iostream>
#include <vector>
#include <string>
#include "CMap.h"
#include "CPlayer.h"
#include "CProgtest.h"
#include "CState.h"
#include "CBlock.h"


#ifndef HRYNTMAK_CGAME_H
#define HRYNTMAK_CGAME_H


class CGame {
public:
    CGame();
    /**
     * Construct the game with configurations from config.txt
    */
    CGame(std::string configFile);

    /**
     * Start the game
     */
    void start();
    /**
     * End the game
     */
    void end();
    /**
     * Restart the game
     */
    void restart();
    /**
     * Save the game
     */
    void save() const;

private:
    /*
     * Map of the game
     */
    CMap      m_Map;
    /*
     * Player stats
     */
    CState    m_Stats;
    /*
     * Game progtest
     */
    CProgtest m_Progtest;
    /*
     * Path to the configuration file
     */
    std::string m_ConfigFile;
    /*
     * A sign that the game is on
     */
    bool m_IsRunning;
    /*
     * Aggregator for creating blocks using a configuration file
     */
    CBlockAggregator m_Aggregator;

    /**
     * Take N lines from the input stream and return string with these lines
     * @param in Input stream
     * @param n Number of lines
     * @return String with the received lines
     */
    std::string accum(std::istream &in, int n);
};


#endif //HRYNTMAK_CGAME_H
