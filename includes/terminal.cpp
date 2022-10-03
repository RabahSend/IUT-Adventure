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

        void error(std::string error) {
            char c;
            do {
                terminal term;
                term.clear();
                std::cout << error << std::endl;
                std::cout << "Continuer [O/n] ";
                std::cin >> c;
                if (c == 'n' || c == 'N')
                    exit(0);

            } while (c != 'o' || c != 'O');
        }

        void titleScreen() {
            terminal terminal;
            terminal.clear();
            drawSprite("../sprites/title.ascii");

            std::cout << "\n\n\n" << "Bienvenue dans IUT Adventure! le jeux où tout est possible (enfin presque)" << std::endl;
        }

        void titleSelectMenu(unsigned int& choice) {
            std::cout << "Choisissez votre aventure :" << std::endl;
            std::cout << "1. Charger une sauvegarde\n"
                      << "0. Quitter" << std::endl;

            std::cin >> choice;
        }
    }
}