#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include "raylib.h"
#include "game_constans.h"

typedef struct
{
    Rectangle box;
    int speed;
} Paddle;

void paddle_drawer(Paddle *player)
{
    DrawRectangleRounded(player->box, 0.8, 0, WHITE);
}

void paddle_limit_movement(Paddle *paddle)
{
    if (paddle->box.y < 0)
    {
        paddle->box.y = 0;
    }
    if (paddle->box.y + PADDLE_HEIGHT > PONG_SCREEN_HEIGHT)
    {
        paddle->box.y = PONG_SCREEN_HEIGHT - PADDLE_HEIGHT;
    }
}

void paddle_update(Paddle *player)
{
    if (IsKeyDown(KEY_UP))
    {
        player->box.y -= player->speed;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        player->box.y += player->speed;
    }

    paddle_limit_movement(player);
}

Paddle paddle_create(int x, int y, int speed)
{
    Paddle paddle = {.box = {x, y, PADDLE_WIDTH, PADDLE_HEIGHT}, .speed = speed};
    return paddle;
}

#endif