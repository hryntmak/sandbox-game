//
// Created by User on 08.05.2023.
//

#include <iostream>

#ifndef HRYNTMAK_CSTATS_H
#define HRYNTMAK_CSTATS_H

/**
 * Class for player stats.
 */
class SState {
public:
    /**
     * Default constructor.
     */
    SState();
    /**
     * Construct State with config from input stream.
     * @param in Input stream.
     */
    explicit SState(std::istream &in);
    /**
     * Operator for print.
     * @param out Output stream.
     * @param progtest Progtest for print.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const SState &state);


    /**
     * Player lives.
     */
    int    m_Lives;
    /**
     * Player energy
     */
    int    m_Energy;
    /**
     * Amount of player electricity.
     */
    int    m_Electricity;
    /**
     * Player programming level
     */
    double m_ProgrammingLevel;
};


#endif //HRYNTMAK_CSTATS_H
