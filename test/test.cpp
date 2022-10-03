#include "../includes/terminal.hpp"

int main() {
    terminal::terminal terminal;
    terminal.clear();
    terminal::draw::drawSprite("../sprites/boss.ascii");

    return 0;
}