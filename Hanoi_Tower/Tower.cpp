#include "headers/graphics.h"
#include <vector>
#include <iostream>

#include "Tower.h"

#pragma comment(lib, "Msimg32.lib")

const int WIDTH = 1200;
const int HEIGHT = 900;

int h = 80;

int r_1 = 150;
int r_2 = 150;
int r_3 = 150;

int x_0_1 = 200;
int x_0_2 = 590;
int x_0_3 = 980;

int y_0 = HEIGHT;

int f_n = 5;
int s_n = 1;
int t_n = 1;

std::vector<int> first_pillar(f_n);
std::vector<int> second_pillar(s_n);
std::vector<int> third_pillar(t_n);

bool selectionFrom = true;
bool selectionTo = false;
int from;
int stop = 0;

/*
Первый диск из (x0-r0 - left; y0 - w - top) в точку (x0 + r0 - right; y0 - bottom)
Второй диск из (x0-r1; y0 – w * 2) в точку (x0+r1; y0 – w)
x_0 - r[i] - left
y_0 - h * (i + 1) - top
x_0 + r[i] - right
y_0 - h * i - bottom
*/

void vector_push() {
    for (int i = 0; i < first_pillar.size(); ++i) {
        first_pillar[i] = r_1;
        r_1 -= 30;

    }
    for (int i = 0; i < second_pillar.size(); ++i) {
        second_pillar[i] = r_2;
        r_2 -= 30;
    }
    for (int i = 0; i < third_pillar.size(); ++i) {
        third_pillar[i] = r_3;
        r_3 -= 30;
    }
}


void draw_disks_1() {
    for (int i = 0; i < first_pillar.size(); ++i) {
        if (i == 0) {
            setfillstyle(SOLID_FILL, BROWN);
            bar(x_0_1 - first_pillar[0], y_0 - h, x_0_1 + first_pillar[0], y_0);
        }
        else {
            setfillstyle(SOLID_FILL, RGB(59, 153, 105));
            bar(x_0_1 - first_pillar[i], y_0 - h * (i + 1), x_0_1 + first_pillar[i], y_0 - h * i);
        }
    }
}

void draw_disks_2() {
    for (int i = 0; i < second_pillar.size(); ++i) {
        if (i == 0) {
            setfillstyle(SOLID_FILL, BROWN);
            bar(x_0_2 - second_pillar[0], y_0 - h, x_0_2 + second_pillar[0], y_0);
        }
        else {
            setfillstyle(SOLID_FILL, RGB(59, 153, 105));
            bar(x_0_2 - second_pillar[i], y_0 - h * (i + 1), x_0_2 + second_pillar[i], y_0 - h * i);
        }
    }
}

void draw_disks_3() {
    for (int i = 0; i < third_pillar.size(); ++i) {
        if (i == 0) {
            setfillstyle(SOLID_FILL, BROWN);
            bar(x_0_3 - third_pillar[0], y_0 - h, x_0_3 + third_pillar[0], y_0);
        }
        else {
            setfillstyle(SOLID_FILL, RGB(59, 153, 105));
            bar(x_0_3 - third_pillar[i], y_0 - h * (i + 1), x_0_3 + third_pillar[i], y_0 - h * i);
        }
    }
}

int select_disk_1() {
    int x = mousex();
    int y = mousey();

    int topRadius = first_pillar[first_pillar.size() - 1];


    if (x >= x_0_1 - topRadius && x <= x_0_1 + topRadius
        && y <= y_0 - h * (first_pillar.size() - 1) && y >= y_0 - h * first_pillar.size()) {
        std::cout << "Selected\n";
        return 1;
    }
    else {
        std::cout << "Not selected\n";
        return 0;
    }
}

int select_disk_2() {
    int x = mousex();
    int y = mousey();

    int topRadius = second_pillar[second_pillar.size() - 1];

    if (x >= x_0_2 - topRadius && x <= x_0_2 + topRadius
        && y <= y_0 - h * (second_pillar.size() - 1) && y >= y_0 - h * second_pillar.size()) {

        return 1;
    }
    else {
        return 0;
    }
}

int select_disk_3() {
    int x = mousex();
    int y = mousey();

    int topRadius = third_pillar[third_pillar.size() - 1];

    if (x >= x_0_3 - topRadius && x <= x_0_3 + topRadius
        && y <= y_0 - h * (third_pillar.size() - 1) && y >= y_0 - h * third_pillar.size()) {

        return 1;
    }
    else {
        return 0;
    }
}

void game() {

    setfillstyle(SOLID_FILL, BROWN);
    bar(180, 300, 220, 900);
    bar(570, 300, 610, 900);                   //Отрисовка колышков
    bar(960, 300, 1000, 900);

    draw_disks_1();
    draw_disks_2();
    draw_disks_3();

    //Проверка 
    if (selectionFrom) {
        if (mousebuttons() == 1 && select_disk_1()) {
            std::cout << "Select disk 1\n";
            setfillstyle(SOLID_FILL, RED);
            bar(x_0_1 - first_pillar[first_pillar.size() - 1], y_0 - h * first_pillar.size(), x_0_1 + first_pillar[first_pillar.size() - 1], y_0 - h * (first_pillar.size() - 1));
            from = 1;
            selectionFrom = false;
            selectionTo = true;
        }
        else if (mousebuttons() == 1 && select_disk_2()) {
            std::cout << "Select disk 2\n";
            setfillstyle(SOLID_FILL, RED);
            bar(x_0_2 - second_pillar[second_pillar.size() - 1], y_0 - h * second_pillar.size(), x_0_2 - second_pillar[second_pillar.size() - 1], y_0 - h * (second_pillar.size() - 1));
            from = 2;
            selectionFrom = false;
            selectionTo = true;
        }
        else if (mousebuttons() == 1 && select_disk_3()) {
            std::cout << "Select disk 3\n";
            setfillstyle(SOLID_FILL, RED);
            bar(x_0_3 - third_pillar[third_pillar.size() - 1], y_0 - h * third_pillar.size(), x_0_3 - third_pillar[third_pillar.size() - 1], y_0 - h * (third_pillar.size() - 1));
            from = 3;
            selectionFrom = false;
            selectionTo = true;
        }
    }

    else if (selectionTo) {
        std::cout << "selectionto\n";
        if (from == 1) {
            if (select_disk_2()) {
                if (first_pillar[first_pillar.size() - 1] < second_pillar[second_pillar.size() - 1]) {
                    second_pillar.push_back(first_pillar[first_pillar.size() - 1]);
                    first_pillar.pop_back();
                    selectionTo = false;
                    selectionFrom = true;
                }
            }
            else if (select_disk_3()) {
                if (first_pillar[first_pillar.size() - 1] < third_pillar[third_pillar.size() - 1]) {
                    third_pillar.push_back(first_pillar[first_pillar.size() - 1]);
                    first_pillar.pop_back();
                }
                selectionTo = false;
                selectionFrom = true;
            }
        }

        else if (from == 2) {
            if (select_disk_1()) {
                if (second_pillar[second_pillar.size() - 1] < first_pillar[first_pillar.size() - 1]) {
                    first_pillar.push_back(second_pillar[second_pillar.size() - 1]);
                    second_pillar.pop_back();
                }
                selectionTo = false;
                selectionFrom = true;
            }
            else if (select_disk_3()) {
                if (second_pillar[second_pillar.size() - 1] < third_pillar[third_pillar.size() - 1]) {
                    third_pillar.push_back(second_pillar[second_pillar.size() - 1]);
                    second_pillar.pop_back();
                }
                selectionTo = false;
                selectionFrom = true;
            }
        }

        else if (from == 3) {
            if (select_disk_1()) {
                if (third_pillar[third_pillar.size() - 1] < first_pillar[first_pillar.size() - 1]) {
                    first_pillar.push_back(third_pillar[third_pillar.size() - 1]);
                    third_pillar.pop_back();
                    selectionTo = false;
                    selectionFrom = true;
                }
            }
            else if (select_disk_2()) {
                if (third_pillar[third_pillar.size() - 1] < second_pillar[second_pillar.size() - 1]) {
                    second_pillar.push_back(third_pillar[third_pillar.size() - 1]);
                    third_pillar.pop_back();
                    selectionTo = false;
                    selectionFrom = true;
                }
            }
        }
        /*
        selectionTo = false;
        selectionFrom = true;
        */
    }
}
