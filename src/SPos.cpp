//
// Created by User on 16.05.2023.
//

#include "SPos.h"

SPos SPos::operator+(SPos other) {
    SPos tmp = *this;
    tmp.x += other.x;
    tmp.y += other.y;
    return tmp;
}

bool SPos::operator==(const SPos & other) const {
    return (x == other.x) && (y == other.y);
}

bool SPos::operator!=(const SPos &other) const {
    return !((*this) == other);
}

SPos::SPos(int X, int Y) : x(X), y(Y) {}

