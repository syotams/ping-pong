#ifndef BALL_HEADER
#define BALL_HEADER

#include "raylib.h"

typedef struct
{
    Vector2 position;
    Vector2 speed;
    int radius;
} Ball;

void ball_flip_x_direction(Ball *ball)
{
    ball->speed.x *= -1;
}

void ball_flip_y_direction(Ball *ball)
{
    ball->speed.y *= -1;
}

void ball_update(Ball *ball)
{
    ball->position.x += ball->speed.x;
    ball->position.y += ball->speed.y;

    if (ball->position.x + ball->radius > GetScreenWidth() || ball->position.x < ball->radius)
    {
        ball_flip_x_direction(ball);
        // ball->speed.x *= -1;
    }
    if (ball->position.y + ball->radius > GetScreenHeight() || ball->position.y < ball->radius)
    {
        ball_flip_y_direction(ball);
        // ball->speed.y *= -1;
    }
}

void ball_drawer(Ball *ball)
{
    DrawCircle(ball->position.x, ball->position.y, ball->radius, BLACK);
}

#endif