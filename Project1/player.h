#pragma once
#include<string>
#include<iostream>

using namespace std;

class player {
private:
	string name;
	int score=0;
public:
	//set diem cho nguoi choi
	void set_score(int Score) {
		score = Score;
	}
	//lay diem cua nguoi choi
	int get_socre() {
		return score;
	}
	//lay ten nguoi choi
	string get_name() {
		return name;
	}
	//ham khoi tao nguoi choi
	player() {
		cout << "Name player : ";
		getline(cin, name);
	}
};