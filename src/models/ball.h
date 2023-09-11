#ifndef BALL_HEADER
#define BALL_HEADER

#include "raylib.h"
#include "game_constans.h"

typedef struct
{
    Vector2 position;
    Vector2 speed;
    int radius;
} Ball;

Ball ball_create(int x, int y, int speed_x, int speed_y);
void ball_update(Ball *ball);
void ball_drawer(Ball *ball);
void ball_flip_x_direction(Ball *ball);
void ball_flip_y_direction(Ball *ball);
void ball_reset(Ball *ball);

#endif