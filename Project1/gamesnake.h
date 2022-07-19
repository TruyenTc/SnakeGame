#pragma once
#include <iostream>
#include <vector>
#include "game.h"
#include"player.h"

using namespace std;



class GameSnake : public Game{
public:
    vector<int> snake;
    GameSnake();
    void draw_snake();
    void remove_snake();
    bool game_over();
    void new_snake(int x, int y);
    void control();
    void creat_food();
    void eat_food(player &P);
    ~GameSnake();
};
