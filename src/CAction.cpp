//
// Created by User on 09.05.2023.
//

#include "CAction.h"

bool CAction::activate(SState    &stats,
                       SProgtest &progtest) {
    bool statsFlag    = changeStats(stats);
    bool progtestFlag = changeProgtest(progtest);
    return statsFlag || progtestFlag;
}
