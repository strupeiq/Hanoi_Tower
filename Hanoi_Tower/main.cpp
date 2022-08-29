#include <iostream>
#include <vector>

#include "Tower.h"
#include "graphics.h"
#pragma comment(lib, "Msimg32.lib")

const int WIDTH = 1200;
const int HEIGHT = 900;


int main() {
	initwindow(WIDTH, HEIGHT, "Towers", 0, 0);
	setfillstyle(SOLID_FILL, BROWN);
	bar(180, 300, 220, 900);
	bar(570, 300, 610, 900);                   //Отрисовка столбиков
	bar(960, 300, 1000, 900);

	if (mousebuttons() == 1) {
		int button = select_disk_1();
		if (button == 1) {
			std::cout << "yes";
		}
	}
	std::vector<int> first_pillar(5);
	std::vector<int> second_pillar(0);
	std::vector<int> third_pillar(0);

	/*for (int i = 0; i < first_pillar.size(); ++i) {
		first_pillar[i] = disk_width;
		disk_width -= 60;
	}
	*/
	draw_disks_1();

	getch();

	return 0;
}
