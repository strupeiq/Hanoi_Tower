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
    r_push();
    vector_push();

    while (true) {
        setbkcolor(BLACK);
        clearviewport();

        setfillstyle(SOLID_FILL, BROWN);
        bar(180, 300, 220, 900);
        bar(570, 300, 610, 900);                   //Отрисовка столбиков
        bar(960, 300, 1000, 900);

        draw_disks_1();
        draw_disks_2();
        draw_disks_3();

        if (mousebuttons() == 1) {
            game();
        }

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
