#include "terminal.hpp"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>

namespace terminal {
    terminal::terminal() { //Struct constructor, places the name of the OS in osName

        #ifdef _WIN32
        osName = "windows32t";

        #elif _WIN64
        osName = "windows64";

        #elif __APPLE__ || __MACH__
        osName = "macos";

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
        else
            system("clear");
    }

    //Draw on screen
    namespace draw {
        void drawSprite(std::string spritePath) {
            std::string sprite;
            std::ifstream spriteStream;

            spriteStream.open(spritePath);
            
            while (spriteStream.peek() != EOF) { //Until end of file
                std::getline(spriteStream, sprite);
                std::cout << sprite << "\n";
            }

            spriteStream.close(); //Never forget to close the stream


        }

        void drawSprite(std::string spritePath, unsigned int gap) {
            std::string sprite;
            std::ifstream spriteStream;

            spriteStream.open(spritePath);
            
            while (spriteStream.peek() != EOF) { //Until end of file
                std::getline(spriteStream, sprite);

                for (unsigned int i=0; i<gap; i++) { //Add a gap before the sprite
                    std::cout << " ";
                }

                std::cout << sprite << "\n";
            }

            spriteStream.close(); //Never forget to close the stream


        }
    }
}