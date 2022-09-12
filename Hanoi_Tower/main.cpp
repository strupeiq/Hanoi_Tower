#include <iostream>
#include <vector>

#include "Tower.h"
#include "graphics.h"
#pragma comment(lib, "Msimg32.lib")

const int WIDTH = 1200;
const int HEIGHT = 900;


int main() {
    initwindow(WIDTH, HEIGHT, "Towers", 0, 0, true);

    std::vector<int> first_pillar(5);
    std::vector<int> second_pillar(0);
    std::vector<int> third_pillar(0);
    vector_push();



    while (true) {
        setbkcolor(BLACK);
        clearviewport();

        game();

        swapbuffers();
        delay(10);

        if (kbhit()) {
            int key = getch();
            if (key == KEY_ESC) {
                break;
            }
            return 0;

        }
    }
}
