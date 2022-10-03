#include "../includes/terminal.hpp"

#include <iostream>


int main() {
    
    unsigned int choice;
    bool valid = false;

    do {
        terminal::draw::titleScreen();
        terminal::draw::titleSelectMenu(choice);
        
        switch (choice) {
            case 0:
                exit(0);
                break;

            case 1:
                
                break;
        
            default:
                break;
        }
    } while (!valid);
    


    terminal::terminal term;
    term.clear();
    
    return 0;
}