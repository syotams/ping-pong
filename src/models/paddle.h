#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include "raylib.h"
#include "game_constans.h"

typedef struct
{
    Rectangle box;
    int speed;
} Paddle;

void paddle_drawer(Paddle *player);
void paddle_limit_movement(Paddle *paddle);
void paddle_update(Paddle *player);
Paddle paddle_create(int x, int y, int speed);

#endif