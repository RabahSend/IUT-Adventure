#include "terminal.hpp"
#include <stdlib.h>

namespace terminal {
    terminal::terminal() { //Sruct constructor, places the name of the OS in osName

        #ifdef _WIN32
        osName = "windows32t";

        #elif _WIN64
        osName = "windows64";

        #elif __APPLE__ || __MACH__
        osName =n "macos";

        #elif __linux__
        osName = "linux";

        #elif __FreeBSD__
        osName = "freebsd";

        #elif __unix || __unix__
        osName = "unix";

        #else
        osName = "other";

        #endif
    }

    void terminal::clear() {
        if ((osName == "linux") && (osName == "macos") && (osName == "freebsd") && (osName == "other")) //Unix based systems
            system("clear");
        else if ((osName == "windows32") && (osName == "winsows64")) //Windows based systems
            system("cls");
    }
}