#include <iostream>
#include "CApplication.h"

int main(int argc, char* argv[]) {
    try {
        CApplication app;
        // If an argument was received, pass it, otherwise pass an empty string
        app.run(argc > 1 ? argv[1] : "");
        return 0;
    } catch ( const std::ios::failure & exception ) {
        if ( std::cin.eof() )
            return 0;
        std::cerr << "Unexpected problem with input and output." << std::endl;
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch ( const std::logic_error & exception ) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 2;
    }
}