//
// Created by User on 08.05.2023.
//

#include "CGame.h"
#include "actions/CNoAction.h"
#include "CBlockAggregator.h"
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <memory>
#include <utility>

std::string CGame::accum(std::istream &in, int n) {
    std::string accumulate;
    std::string line; // line in map
    for (int i = 0; i < n; ++i) {
        getline(in, line);
        if (line.empty() || line == "\n") {
            i--;
            continue;
        }
        accumulate += line + "\n";
    }
    return accumulate;
}

CGame::CGame() = default;

CGame::CGame(std::string configFile) : m_ConfigFile(std::move(configFile)),
                                       m_IsRunning(true),
                                       m_Aggregator(m_ConfigFile){
    std::string word;
    std::ifstream in(m_ConfigFile);
    //  Configure game with config file
    if (in.is_open())
    {
        if ( in . fail () ) throw std::logic_error("Can't open config file");
        in >> word;
        if (word == "map:") {
            m_Map = std::move(CMap(in, m_Aggregator)); // Initialize map with map from config file
        } else {
            throw std::logic_error("Map isn't in config file or bad order");
        }
        in >> word;
        if (word == "player:") {
            std::string accumulated = accum(in, 2);
            std::istringstream iss (accumulated);
            m_Map.setPlayer(std::move(CPlayer(iss, m_Aggregator)));
        } else {
            throw std::logic_error("Player isn't in config file or bad order");
        }
        in >> word;
        if (word == "progtest:") {
            std::string accumulated = accum(in, 8);
            std::istringstream iss (accumulated);
            m_Progtest = CProgtest(iss);
        } else {
            throw std::logic_error("Progtest isn't in config file or bad order");
        }
        in >> word;
        if (word == "stats:") {
            std::string accumulate = accum(in, 4);
            std::istringstream iss (accumulate);
            m_Stats = CState(iss);
        } else {
            throw std::logic_error("Stats isn't in config file or bad order");
        }
    }
    in.close();
}

void CGame::start() {
    //Enable reading of each character
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    std::cout << m_Map << std::endl;
    std::cout << m_Stats << std::endl;
    std::cout << m_Progtest << std::endl;
    char c;
    while(std::cin >> c) {
        std::unique_ptr<CAction> action = std::make_unique<CNoAction>();
        if (std::cin.eof()) {
            save();
            std::cout << "Game was saved and end." << std::endl;
            // Disable reading of each character
            term.c_lflag |= ECHO | ICANON;
            tcsetattr(STDIN_FILENO, TCSANOW, &term);
            return;
        }
        switch(c) {
            case 'w':
            case 'W':
                m_Map.move({0,-1})->activate(m_Stats, m_Progtest);
                action = m_Map.action(true);
                break;
            case 's':
            case 'S':
                m_Map.move({0,1})->activate(m_Stats, m_Progtest);
                action = m_Map.action(true);
                break;
            case 'a':
            case 'A':
                m_Map.move({-1,0})->activate(m_Stats, m_Progtest);
                action = m_Map.action(true);
                break;
            case 'd':
            case 'D':
                m_Map.move({1,0})->activate(m_Stats, m_Progtest);
                action = m_Map.action(true);
                break;
            case 'q':
            case 'Q':
                m_Map.mine();
                break;
            case 'e':
            case 'E':
                m_Map.placeBlock();
                break;
            case 'f':
            case 'F':
                action = m_Map.action(false);
                break;
            case '1':
                m_Map.setActiveItem(0);
                break;
            case '2':
                m_Map.setActiveItem(1);
                break;
            case '3':
                m_Map.setActiveItem(2);
                break;
            case '4':
                m_Map.setActiveItem(3);
                break;
            case '5':
                m_Map.setActiveItem(4);
                break;
            case 'l':
            case 'L':
                save();
                break;
            case 'r':
            case 'R':
                restart();
                break;
            case 'k':
            case 'K':
                // Disable reading of each character
                term.c_lflag |= ECHO | ICANON;
                tcsetattr(STDIN_FILENO, TCSANOW, &term);
                // End the game
                end();
                return;
        }
        int dayToDeadline = m_Progtest.m_Deadline;
        action->activate(m_Stats,m_Progtest);
        if (dayToDeadline != m_Progtest.m_Deadline)
            m_Map.update();
        m_Map.refresh();
        std::cout << m_Map << std::endl;
        std::cout << m_Stats << std::endl;
        std::cout << m_Progtest << std::endl;
        if (m_Progtest.m_Deadline == 0
         || m_Progtest.m_Attempts == m_Progtest.m_MaxAttempts
         || m_Stats.m_Lives == 0) {
            // Disable reading of each character
            term.c_lflag |= ECHO | ICANON;
            tcsetattr(STDIN_FILENO, TCSANOW, &term);
            // End the game, if isn't runnig
            end();
            if(!m_IsRunning) // Can run, if user restart the game after end.
                return;
            // Enable reading of each character
            term.c_lflag &= ~(ECHO | ICANON);
            tcsetattr(STDIN_FILENO, TCSANOW, &term);
        }
    }
    if (std::cin.eof()) {
        std::cout << "End game." << std::endl;
    }
    // Disable reading of each character
    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void CGame::end() {
    m_IsRunning = false;
    if (m_Progtest.m_Deadline == 0 || m_Progtest.m_Attempts == m_Progtest.m_MaxAttempts) {
        if(m_Progtest.m_Score >= 5.5) {
            std::cout << "Not today..." << std::endl <<
                      "  ________" << std::endl <<
                      " |/      |" << std::endl <<
                      " |      ( )" << std::endl <<
                      " |" << std::endl <<
                      " |" << std::endl <<
                      " |" << std::endl <<
                      " |" << std::endl << std::endl;
            std::cout << "You were able to pass the task. Congratulations!!!" << std::endl;
            return;
        } else {
            std::cout << "The time is up..." << std::endl;
            std::cout <<  "  ________" << std::endl <<
                      " |/      |" << std::endl <<
                      " |      (O)" << std::endl <<
                      " |      /|\\" << std::endl <<
                      " |       |" << std::endl <<
                      " |      / \\" << std::endl <<
                      " |" << std::endl << std::endl;
            std::cout << "Good luck next time" << std::endl;
            return;
        }
    }
    std::string str;
    if (m_Stats.m_Lives == 0) {
        std::cout << "You're dead \\(X_X)/" << std::endl;
        while (true) {
            std::cout << "Do you want to restart the game? (Yes/No)" << std::endl;
            std::cin >> str;
            if (std::cin.eof() || str == "No" || str == "no" || str == "N" || str == "n")
                return;
            if (str == "Yes" || str == "yes" || str == "Y" || str == "y") {
                //Enable reading of each character
                termios term;
                tcgetattr(STDIN_FILENO, &term);
                term.c_lflag &= ~(ECHO | ICANON);
                tcsetattr(STDIN_FILENO, TCSANOW, &term);
                // Restart the game
                restart();
                // Disable reading of each character
                term.c_lflag |= ECHO | ICANON;
                tcsetattr(STDIN_FILENO, TCSANOW, &term);
                return;
            }
        }
    }
    while (true) {
        std::cout << "Do you want to save this game? (Yes/No)" << std::endl;
        std::cin >> str;
        if (std::cin.eof() || str == "No" || str == "no" || str == "N" || str == "n")
            return;
        if (str == "Yes" || str == "yes" || str == "Y" || str == "y") {
            save();
            return;
        }
    }
}

void CGame::save() const {
    std::ofstream fout("examples/save.txt", std::ios_base::out | std::ios_base::trunc);
    fout << "map:" << std::endl;
    m_Map.printConfig(fout);
    fout << m_Progtest << std::endl;
    fout << m_Stats << std::endl;
    m_Aggregator.printConfig(fout);
}

void CGame::restart() {
    std::cout << "1. Restart the game with default configuration file." << std::endl;
    std::cout << "2. Restart the game by saving." << std::endl;
    std::cout << "3. Cansel." << std::endl;
    char c;
    while (std::cin >> c) {
        switch (c) {
            case '1':
                *this = CGame("examples/config.txt");
                return;
            case '2':
                *this = CGame("examples/save.txt");
                return;
            case '3':
                return;
            default:
                std::cout << "Please choose 1, 2 or 3." << std::endl;
        }
    }
}

