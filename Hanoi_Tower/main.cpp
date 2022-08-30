#include <iostream>
#include <vector>

#include "Tower.h"
#include "graphics.h"
#pragma comment(lib, "Msimg32.lib")

const int WIDTH = 1200;
const int HEIGHT = 900;
int disk_width = 300;

int main() {
    initwindow(WIDTH, HEIGHT, "Towers", 0, 0, true);
    r_push();

    std::vector<int> first_pillar(5);
    std::vector<int> second_pillar(0);
    std::vector<int> third_pillar(0);

    for (int i = 0; i < first_pillar.size(); ++i) {
        first_pillar[i] = disk_width;
        disk_width -= 60;

    }
    for (int i = 0; i < second_pillar.size(); ++i) {
        second_pillar[i] = disk_width;
        disk_width -= 60;
    }
    for (int i = 0; i < third_pillar.size(); ++i) {
        third_pillar[i] = disk_width;
        disk_width -= 60;
    }

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
