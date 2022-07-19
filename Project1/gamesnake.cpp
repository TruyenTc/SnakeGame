#include "gamesnake.h"


int tempX, tempY;
int flag;


//ham khoi tao ran ban dau 4 dot 
GameSnake::GameSnake() {
	int x = 30, y = 12;
	for (int i = 0; i < 4; i++) {
		snake.push_back(x);
		snake.push_back(y);
		x--;
	}
}
//ham ve ran len man hinh console
void GameSnake::draw_snake() {
	for (int i = 0; i < (snake.size()); i = i + 2) {
		gotoXY(snake[i], snake[i + 1]);
		cout << "o";
	}
}
//ham xoa ran de ve lai ran
void GameSnake::remove_snake() {
	for (int i = 0; i < (snake.size()); i = i + 2) {
		gotoXY(snake[i], snake[i + 1]);
		cout << " ";
	}
}
//ham kiem tra cham tuong
bool GameSnake::game_over() {
	if (snake[0] == 10 || snake[0] == 75 || snake[1] == 5 || snake[1] == 25) {
		return true;
	}
	//kiem tra cham than
	for (int i = 2; i < snake.size(); i = i + 2) {
		if (snake[0] == snake[i] && snake[1] == snake[i + 1]) {
			return true;
		}
	}
	return false;
}
//ham cap nhat lai ran
void GameSnake::new_snake(int x, int y) {
	//them vao ran 1 dot o dau
	if (flag == 1) {
		snake.insert(snake.begin(), y);
		snake.insert(snake.begin(), x);
		flag = 0;
	}
	// xoa duoi va them dau
	else {
		snake.erase(snake.begin() + (snake.size() - 2), snake.begin() + snake.size());
		snake.insert(snake.begin(), y);
		snake.insert(snake.begin(), x);
	}

}
//ham dieu khien con ran
void GameSnake::control() {
	//so sanh bien check o ben ham read_word
	if (check == "up") { //di len
		int y = snake[1] - 1;
		new_snake(snake[0], y);//goi den ham tao ran moi
	}
	if (check == "down") {//di xuong
		int y = snake[1] + 1;
		new_snake(snake[0], y);

	}
	if (check == "left") {//qua trai
		int x = snake[0] - 1;
		new_snake(x, snake[1]);

	}
	if (check == "right") {//qua phai
		int x = snake[0] + 1;
		new_snake(x, snake[1]);

	}

}
//ham tao moi
void GameSnake::creat_food() {
		srand(time(NULL));
		tempX = rand() % (74 - 11 + 1) + 11;
		tempY = rand() % (24 - 6 + 1) + 6;
		gotoXY(tempX, tempY);
		cout << "*";
}
//ham kiem tra ran an moi
void GameSnake::eat_food(player &P) {
	if (tempX == snake[0] && tempY == snake[1]) {
		flag = 1;
		creat_food();
		P.set_score((P.get_socre()+10));//set lai diem cho nguoi choi
		gotoXY(77, 9);
		cout << "Score :" <<P.get_socre() ;//in diem ra man hinh
	}
}

GameSnake::~GameSnake() {}