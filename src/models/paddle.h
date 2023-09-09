#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include "raylib.h"

const int PADDLE_WIDTH = 10;
const int PADDLE_HEIGHT = 80;

typedef struct
{
    Vector2 position;
    int speed;
} Paddle;

void paddle_drawer(Paddle *player)
{
    DrawRectangle(player->position.x, player->position.y, PADDLE_WIDTH, PADDLE_HEIGHT, BLACK);
}

void paddle_limit_movement(Paddle *paddle)
{
    if (paddle->position.y < 0)
    {
        paddle->position.y = 0;
    }
    if (paddle->position.y + PADDLE_HEIGHT > GetScreenHeight())
    {
        paddle->position.y = GetScreenHeight() - PADDLE_HEIGHT;
    }
}

void paddle_update(Paddle *player)
{
    if (IsKeyDown(KEY_UP))
    {
        player->position.y -= player->speed;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        player->position.y += player->speed;
    }

    paddle_limit_movement(player);
}

#endif