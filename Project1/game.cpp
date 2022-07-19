#include "game.h"

Game::Game() {}
//ham ve thanh ngang cho khung
void Game::drawColum(int x, int y, int y1) {
	int a = x;
	while (x <= 95) {
		gotoXY(x, y);
		cout << "*";
		x++;
	}
	while (a <= 95) {
		gotoXY(a, y1);
		cout << "*";
		a++;
	}
}
//ham ve thanh doc cho khung
void Game::drawRow(int y, int x, int x1) {
	int a = y;
	int b = y;
	while (y <= 25) {
		gotoXY(x, y);
		cout << "*";
		y++;
	}
	while (a <= 25) {
		gotoXY(x1, a);
		cout << "*";
		a++;
	}
	while (b <= 25) {
		gotoXY(95, b);
		cout << "*";
		b++;
	}
}
//ham dua con tro den toa do x, y
void Game::gotoXY(int x, int y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//ham doc ky tu nhap vao
void Game::read_word() {

	if (_kbhit()) {
		char ky_tu = _getch();//lay ky tu o bo nho dem
		if (ky_tu == 'w' && check != "down") {//kiem tra neu dang di xuong thi ko di len duoc
			check = "up";
		}
		if (ky_tu == 's' && check != "up") {//kiem tra neu dang di len thi ko di xuong duoc
			check = "down";
		}
		//moi vao khong qua trai duoc
		if (ky_tu == 'a' && check != "right"&& check != "") {//kiem tra neu dang phai xuong thi ko di trai duoc
			check = "left";
		}
		else if (ky_tu == 'd' && check != "left") {//kiem tra neu dang di trai thi ko di phai duoc
			check = "right";
		}
	}
}
Game::~Game() {}