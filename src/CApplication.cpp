//
// Created by User on 08.05.2023.
//

#include "CApplication.h"
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <termios.h>

CApplication::CApplication() = default;

void CApplication::run(std::string path) {
    // The path to the config file can be received in program arguments
    if (!path.empty()) {
        std::ifstream in(path);
        if ( in.fail() )
            throw  std::logic_error("File \"" + path + "\" does not exist.");
        m_Game = CGame(path);
        m_Game.start();
        return;
    }

    //Enable reading of each character
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    std::cout << "1. Start thr game with default configuration file." << std::endl;
    std::cout << "2. Start the game by saving." << std::endl;
    std::cout << "3. Enter own configuration/save file." << std::endl;

    char c;
    while (std::cin >> c) {
        // Disable reading of each character
        term.c_lflag |= ECHO | ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
        switch (c) {
            case '1':
                m_Game = CGame("examples/config.txt");
                m_Game.start();
                return;
            case '2':
                m_Game = CGame("examples/save.txt");
                m_Game.start();
                return;
            case '3': {
                std::cout << "Enter the path to the configuration/save file." << std::endl;
                std::string str;
                std::cin >> str;
                if (std::cin.eof())
                    return;
                std::ifstream in(str);
                while ( in.fail() ) {
                    std::cout << "Pleas, enter correct path." << std::endl;
                    std::cin >> str;
                    if (std::cin.eof())
                        return;
                    in.open(str);
                }

                m_Game = CGame(str);
                m_Game.start();
                return;
            }
            default:
                std::cout << "Please choose 1, 2 or 3" << std::endl;
        }
        //Enable reading of each character
        term.c_lflag &= ~(ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
    }
}
