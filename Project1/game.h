#pragma once
#include <iostream>
#include <windows.h>
#include<string>
#include <stdio.h>
#include <conio.h>
#include<ctime>

using namespace std;

class Game {
public:
	string check ;
	Game();
	~Game();
	void drawColum(int x, int y, int y1);
	void drawRow(int y, int x, int x1);
	void gotoXY(int x, int y);
	void read_word();
};
