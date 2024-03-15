//
// Created by User on 09.05.2023.
//

#include "CComputerBlock.h"
#include "../CConfig.h"
#include "../actions/CMakeProgtest.h"
#include "../actions/CSubmitProgtest.h"
#include "../actions/CNoAction.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>

CComputerBlock::CComputerBlock() : CBlock('C', -1, 0, 0, true) {}

std::unique_ptr<CAction> CComputerBlock::action(std::unique_ptr<CBlock> &activeItem) {
    termios term;
    tcgetattr(STDIN_FILENO, &term);

    char c;
    std::cout << "1 - Work on progtest.\n2 - Try to submit progtest.\n3 - End work.\n";
    bool flag = true;
    while(flag) {
        std::cin >> c;
        switch (c) {
            case '1':
                // Disable reading of each character
                term.c_lflag |= ECHO | ICANON;
                tcsetattr(STDIN_FILENO, TCSANOW, &term);

                std::cout << "Enter the amount of energy to work with progtest.\n";
                while (true) {
                    int n;
                    std::string str;
                    std::getline(std::cin, str);
                    if (std::cin.eof())
                        return std::make_unique<CNoAction>();
                    while (!CConfig::isInteger(str)
                         || str.size() > 4) {
                        std::cout << "Excepted an integer number in the range from 1 to 9999." << std::endl;
                        std::getline(std::cin, str);
                        if (std::cin.eof())
                            return std::make_unique<CNoAction>();
                    }
                    n = std::stoi(str);
                    if (n < 0) {
                        std::cout << "Enter a number greater than 0\n";
                        continue;
                    }

                    //Enable reading of each character
                    term.c_lflag &= ~(ECHO | ICANON);
                    tcsetattr(STDIN_FILENO, TCSANOW, &term);

                    return std::make_unique<CMakeProgtest>(n);
                }
            case '2':
                return std::make_unique<CSubmitProgtest>();
            case '3':
                return std::make_unique<CNoAction>();
        }
    }
    return nullptr;
}

bool CComputerBlock::update() {
    return false;
}

bool CComputerBlock::refresh(std::vector<std::vector<std::unique_ptr<CBlock>>> &map,
                             SPos                                               pos) {
    return false;
}

