//
// Created by User on 09.05.2023.
//

#include "CAction.h"

bool CAction::activate(CState &stats, CProgtest &progtest) {
    bool statsFlag = changeStats(stats);
    bool progtestFlag = changeProgtest(progtest);
    return statsFlag || progtestFlag;
}
