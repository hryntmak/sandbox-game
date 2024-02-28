//
// Created by User on 08.05.2023.
//

#include "CGame.h"
#include <string>
#include "CMap.h"
#include "CPlayer.h"
#include "CProgtest.h"
#include "CState.h"
#include "CBlock.h"

#ifndef HRYNTMAK_CAPPLICATION_H
#define HRYNTMAK_CAPPLICATION_H


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
    /*
     * Current game
     */
    CGame m_Game;
};


#endif //HRYNTMAK_CAPPLICATION_H
