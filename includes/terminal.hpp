#pragma once
#include <string>

namespace terminal {

    const std::string mid = "           ";
    
    struct terminal {
        terminal();
        std::string osName; //linux, macos, windows32, windows64, freebsd, unix or other.

        void clear();
    };

    namespace draw {
        void drawSprite(std::string); //Without gap
        void drawSprite(std::string, unsigned); //With gap

        void error(std::string);

        void titleScreen();
        void titleSelectMenu(unsigned int&); //title screen menu slection
        void mobApparition(std::string);

        void saveMenu();
    }

}