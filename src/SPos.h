//
// Created by User on 08.05.2023.
//

#ifndef HRYNTMAK_SPOS_H
#define HRYNTMAK_SPOS_H

/**
 * Container for coordinates
 */
struct SPos {
    /**
     * Default constructor
     */
    SPos() = default;
    /**
     * Construct with received coordinates.
     * @param X X coordinate
     * @param Y Y coordinate
     */
    SPos(int X, int Y);
    /**
     * Add two positions like (x1 + x2, y1 + y2).
     * @param other Position for addition.
     * @return Return new position.
     */
    SPos operator + (SPos other);
    /**
     * Compare two positions.
     * @param other Position for comparison.
     * @return Return true, if are equals.
     */
    bool operator == (const SPos & other) const;
    /**
     * Compare two positions.
     * @param other Position for comparison.
     * @return Return true, if aren't equals.
     */
    bool operator != (const SPos & other) const;

    /*
     * X(horizontal) coordinate
     */
    int x;
    /*
     * Y(vertical) coordinate
     */
    int y;
};

#endif //HRYNTMAK_SPOS_H
