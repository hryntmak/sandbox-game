//
// Created by User on 08.05.2023.
//

#include "CGame.h"
#include <string>
#include "CMap.h"
#include "CPlayer.h"
#include "SProgtest.h"
#include "SState.h"
#include "CBlock.h"

#ifndef HRYNTMAK_CAPPLICATION_H
#define HRYNTMAK_CAPPLICATION_H


/**
 * An application class that takes care of running the game.
 */
class CApplication {
public:
    /**
     * Default constructor
     */
    CApplication();
    /**
     * Run application
     */
    void run(std::string path);
private:
    /**s
     * Current game
     */
    CGame m_Game;
};


#endif //HRYNTMAK_CAPPLICATION_H
