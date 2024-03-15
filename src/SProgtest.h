//
// Created by User on 08.05.2023.
//

#include <iostream>

#ifndef HRYNTMAK_CPROGTEST_H
#define HRYNTMAK_CPROGTEST_H

/**
 * Class for progtest stats and methods.
 */
class SProgtest {
public:
    /**
     * Default constructor.
     */
    SProgtest() = default;
    /**
     * Construct Progtest with config from input stream.
     * @param in Input stream.
     */
    explicit SProgtest(std::istream &in);
    /**
     * Try to submit progtest and take a score.
     * @return Success of submission.
     */
    bool submit();
    /**
     * Operator for print.
     * @param out Output stream.
     * @param progtest Progtest for print.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const SProgtest &progtest);


    /**
     * Progtest score.
     */
    double m_Score;
    /**
     * Progtest complexity.
     */
    double m_Complexity;
    /**
     * Suspicions of cheating on the progtest. A chance to get a red flag.
     */
    double m_CheatingSuspicion;
    /**
     * Progtest progress.
     */
    double m_Progress;
    /**
     * Number of days before the deadline.
     */
    int    m_Deadline;
    /**
     * Number of attempts used to submit the progtest.
     */
    int    m_Attempts;
    /**
     * Max number of attempts to submit the progtest.
     */
    int    m_MaxAttempts;
    /**
     * Red flag. This is true if the player was suspected of cheating.
     */
    bool   m_RedFlag;
private:
};


#endif //HRYNTMAK_CPROGTEST_H
