#pragma once
#include <string>

namespace terminal {
    
    struct terminal {
        terminal();
        std::string osName; //linux, macos, windows32, windows64, freebsd, unix or other.

        void clear();
    };

    namespace draw {
        void drawSprite(std::string spritePath); //Without gap
        void drawSprite(std::string spritePath, unsigned int gap); //With gap
    }

}