//
// Created by User on 16.05.2023.
//

#include "CConfig.h"

bool CConfig::isDouble(const std::string &str) {
    bool doteFlag = false;
    for (char c : str) {
        if (!isdigit(c) && c != '.')
            return false;
        if (c == '.') {
            if (doteFlag)
                return false;
            doteFlag = true;
        }
    }
    return true;
}

bool CConfig::isInteger(const std::string &str) {
    for (char c : str) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

int CConfig::getInteger(std::istream &in, const std::string & expected, int max) {
    std::string str;

    in >> str;
    if (str != expected)
        throw std::logic_error("Expected '" + expected + "' in the config file.");

    in >> str;
    if (str != "=")
        throw std::logic_error("Expected '='.");

    in >> str;
    if (!isInteger(str))
        throw std::logic_error("Expected integer.");
    if(str.size() > 7)
        throw std::logic_error("Too big number in the configuration of \"" + expected + "\".");
    int n = std::stoi(str);

    if (n > max)
        throw std::logic_error("Too big number in the configuration of \"" + expected + "\".");

    return n;
}

double CConfig::getDouble(std::istream &in, const std::string & expected, double max) {
    std::string str;

    in >> str;
    if (str != expected)
        throw std::logic_error("Bad progtest config.");

    in >> str;
    if (str != "=")
        throw std::logic_error("Expected '='.");

    in >> str;
    if (!isDouble(str))
        throw std::logic_error("Expected double.");

    double d = std::stod(str);
    if (d > max)
        throw std::logic_error("Too big number in the configuration of \"" + expected + "\".");

    return d;
}
