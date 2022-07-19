#include <iostream>
#include "gamesnake.h"
#include"setup.h"



int main(int argc, char* argv[]) {

tryagain:
	GameSnake gs;
	player p;
	setSleep();
	draw(p, gs);
	while (true) {
		gs.remove_snake();
		gs.control();
		gs.read_word();
		if (gs.game_over()) {
			break;
		}
		gs.eat_food(p);
		gs.remove_snake();
		gs.draw_snake();
		if (gs.snake.size() <= 16) {
			Sleep(m);
		}
		else if (gs.snake.size() > 16) {
			Sleep((m-50));
		}
	}
	system("cls");
	cout << "\n1. Ban muon choi lai ";
	cout << "\n2. ket thuc ";
	cout << "\nNhap lua chon cua ban : ";
	int n;
	tryagain2:
	cin >> n;
	cin.ignore();
	switch (n) {
	case 1: {
		//cho nguoi choi choi lai
		gs.snake.erase(gs.snake.begin(), gs.snake.begin() + gs.snake.size());
		system("cls");
		goto tryagain;
	}
		  break;
	case 2: {
		//thoat va in ra ket qua
		system("cls");
		cout << "\nPlayer : " << p.get_name();
		cout << "\nDiem cua ban la : " << p.get_socre();
		}
		  break;
	default: {
		cout << "\nNhap lai lua chon cua ban : ";
		goto tryagain2;
	}
		   break;
	}
	return 0;
}