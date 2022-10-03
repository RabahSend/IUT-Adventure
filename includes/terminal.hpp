#pragma once
#include <string>

namespace terminal {
    
    struct terminal {
        terminal();
        std::string osName; //linux, macos, windows32, windows64, freebsd, unix or other.

        void clear();
    };

}