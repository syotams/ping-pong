#include "ball.h"

Ball ball_create(int x, int y, int speed_x, int speed_y)
{
    Ball ball = {.position = {x, y}, .speed = {speed_x, speed_y}, 10};
    return ball;
}

void ball_flip_x_direction(Ball *ball)
{
    ball->speed.x *= -1;
}

void ball_flip_y_direction(Ball *ball)
{
    ball->speed.y *= -1;
}

void ball_reset(Ball *ball)
{
    ball->position.x = PONG_SCREEN_WIDTH / 2;
    ball->position.y = PONG_SCREEN_HEIGHT / 2;
}

void ball_update(Ball *ball)
{
    ball->position.x += ball->speed.x;
    ball->position.y += ball->speed.y;

    if (ball->position.x + ball->radius > PONG_SCREEN_WIDTH || ball->position.x < ball->radius)
    {
        ball_flip_x_direction(ball);
    }
    if (ball->position.y + ball->radius > PONG_SCREEN_HEIGHT || ball->position.y < ball->radius)
    {
        ball_flip_y_direction(ball);
    }
}

void ball_drawer(Ball *ball)
{
    DrawCircle(ball->position.x, ball->position.y, ball->radius, PONG_YELLOW);
}