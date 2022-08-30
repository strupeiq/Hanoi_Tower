#include "graphics.h"
#include <vector>

#include "Tower.h"

#pragma comment(lib, "Msimg32.lib")

const int WIDTH = 1200;
const int HEIGHT = 900;

int h = 80;
int disk_width = 300;
int max_r = 150;

int x_0_1 = 200;
int x_0_2 = 590;
int x_0_3 = 980;
int y_0 = HEIGHT;

std::vector<int> first_pillar(5);
std::vector<int> second_pillar(0);
std::vector<int> third_pillar(0);

/*
ѕервый диск из (x0-r0 - left; y0 - w - top) в точку (x0 + r0 - right; y0 - bottom)
¬торой диск из (x0-r1; y0 Ц w * 2) в точку (x0+r1; y0 Ц w)
x_0 - r[i] - left
y_0 - h * (i + 1) - top
x_0 + r[i] - right
y_0 - h * i - bottom
*/
std::vector<int> r(5);

void r_push() {
    for (int i = 0; i < r.size(); ++i) {
        r[i] = max_r;
        max_r -= 30;
    }
}

void draw_disks_1() {
    for (int i = 0; i < first_pillar.size(); ++i) {
        setfillstyle(SOLID_FILL, RGB(59, 153, 105));
        bar(x_0_1 - r[i], y_0 - h * (i + 1), x_0_1 + r[i], y_0 - h * i);
    }
}

void draw_disks_2() {
    for (int i = 0; i < second_pillar.size(); ++i) {
        setfillstyle(SOLID_FILL, RGB(59, 153, 105));
        bar(x_0_2 - r[i], y_0 - h * (i + 1), x_0_2 + r[i], y_0 - h * i);
    }
}

void draw_disks_3() {
    for (int i = 0; i < third_pillar.size(); ++i) {
        setfillstyle(SOLID_FILL, RGB(59, 153, 105));
        bar(x_0_3 - r[i], y_0 - h * (i + 1), x_0_3 + r[i], y_0 - h * i);
    }
}

int select_disk_1() {
    int x = mousex();
    int y = mousey();

    if (x >= x_0_1 - r[first_pillar.size() - 1] && x <= x_0_1 + r[first_pillar.size() - 1]
        && y >= y_0 - h * first_pillar.size() - 1 && y <= y_0 - h * first_pillar.size()) {

        return 1;
    }
}

int select_disk_2() {
    int x = mousex();
    int y = mousey();

    if (x >= x_0_2 - r[second_pillar.size() - 1] && x <= x_0_2 + r[second_pillar.size() - 1]
        && y >= y_0 - r[second_pillar.size() - 1] && y <= y_0 + r[second_pillar.size() - 1]) {

        return 2;
    }
}

int selet_disk_3() {
    int x = mousex();
    int y = mousey();

    if (x >= x_0_3 - r[third_pillar.size() - 1] && x <= x_0_3 + r[third_pillar.size() - 1]
        && y >= y_0 - r[third_pillar.size() - 1] && y <= y_0 + r[third_pillar.size() - 1]) {

        return 3;
    }
}

