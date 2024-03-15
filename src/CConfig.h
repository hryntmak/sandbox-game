//
// Created by User on 16.05.2023.
//

#include <iostream>
#include <limits>

#ifndef HRYNTMAK_CCONFIG_H
#define HRYNTMAK_CCONFIG_H

/**
 * Support class for working with the configuration file.
 */
class CConfig {
public:
    /**
     * Return true if string is a double
     * @param str String to check
     * @return True - is double. False - is not.
     */
    static bool isDouble(const std::string &str);
    /**
     * Return true if string is an integer
     * @param str String to check
     * @return True - is integer. False - is not.
     */
    static bool isInteger(const std::string &str);
    /**
     * Get one line from output stream.
     * Check for the correctness of the configuration
     * Extract and return a double from config line.
     * @param in Input stream with configuration.
     * @param expected Expected name of attribute configuration
     * @param max Limit for config number
     * @return Double from config line
     */
    static double getDouble(std::istream      &in,
                            const std::string &expected,
                            double             max = std::numeric_limits<double>::max());
    /**
     * Get one line from output stream.
     * Check for the correctness of the configuration
     * Extract and return an integer from config line.
     * @param in Input stream with configuration.
     * @param expected Expected name of attribute configuration
     * @param max Limit for config number
     * @return Integer from config line
     */
    static int getInteger(std::istream      &in,
                          const std::string &expected,
                          int                max = std::numeric_limits<int>::max());
};


#endif //HRYNTMAK_CCONFIG_H
