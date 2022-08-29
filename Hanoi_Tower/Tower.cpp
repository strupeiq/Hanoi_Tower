#include "graphics.h"
#include <vector>

#include "Tower.h"

#pragma comment(lib, "Msimg32.lib")

const int WIDTH = 1200;
const int HEIGHT = 900;

int h = 80;
int r = 30;
int disk_width = 300;

std::vector<int> first_pillar(5);
std::vector<int> second_pillar(0);
std::vector<int> third_pillar(0);

int y_min_1 = HEIGHT - h * first_pillar.size();
int y_min_2 = HEIGHT - h * second_pillar.size();
int y_min_3 = HEIGHT - h * third_pillar.size();

void draw_disks_1() {
	/*Disk disk_1;
	disk_1.left = 50;
	disk_1.top = 820;
	disk_1.right = 350;
	disk_1.bottom = 900;
	*/

	for (int i = 0; i < first_pillar.size(); ++i) {
		first_pillar[i] = disk_width;
		disk_width -= 60;
	}

	for (int i = 0; i < first_pillar.size(); ++i) {
		if (first_pillar[i] == 300) {
			setfillstyle(SOLID_FILL, RGB(59, 153, 105));
			bar(50, 820, 350, 900);
		}
		else if(first_pillar[i] == 240){
			setfillstyle(SOLID_FILL, RGB(59, 153, 178));
			bar(80, 740, 320, 820);
			/*disk_1.left += r;
			disk_1.top -= h;
			disk_1.right -= r;
			disk_1.bottom -= h;
			*/
		}
		else if (first_pillar[i] == 180) {
			setfillstyle(SOLID_FILL, RGB(59, 153, 105));
			bar(110, 660, 290, 740);
		}
		else if (first_pillar[i] == 120) {
			setfillstyle(SOLID_FILL, RGB(59, 153, 178));
			bar(140, 580, 260, 660);
		}
		else if (first_pillar[i] == 60) {
			setfillstyle(SOLID_FILL, RGB(59, 153, 105));
			bar(170, 500, 230, 580);
		}
	}
}

int select_disk_1() {
	int x = mousex();
	int y = mousey();

	if (x >= 200 - (first_pillar[first_pillar.size()] / 2) && x <= 200 + (first_pillar[first_pillar.size()] / 2)
		&& y >= y_min_1 - h * first_pillar.size() && y <= y_min_1 - h * (first_pillar.size() - 1)) {

		return 1;
	}
}

int select_disk_2() {
	int x = mousex();
	int y = mousey();

	if (x >= 600 - (second_pillar[second_pillar.size()] / 2) && x <= 600 + (second_pillar[second_pillar.size()] / 2)
		&& y >= y_min_2 - h * second_pillar.size() && y <= y_min_2 - h * (second_pillar.size() - 1)) {

		return 2;
	}
}

int select_disk_3() {
	int x = mousex();
	int y = mousey();

	if (x >= 1000 - (third_pillar[third_pillar.size()]) && x <= 1000 + (third_pillar[third_pillar.size()] / 2)
		&& y >= y_min_3 - h * third_pillar.size() && y <= y_min_3 - h * (third_pillar.size() - 1)) {

		return 3;
	}
}

int check() {

}