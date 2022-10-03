#include "../includes/terminal.hpp"

#include <chrono>
#include <thread>

void drawAnimation(int i) {
    terminal::terminal terminal;
    
    terminal.clear();
    terminal::draw::drawSprite("../sprites/boss.ascii",(4*i));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() {
    while(true) {
        for (int i=0; i<10; i++) {
           drawAnimation(i);
        }
    }
    return 0;
}