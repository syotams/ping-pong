#ifndef CPUPADDLE_HEADER
#define CPUPADDLE_HEADER

#include "paddle.h"
#include "ball.h"

void cpu_paddle_update(Paddle *player, Ball *ball)
{
    if (player->position.y + PADDLE_HEIGHT / 2 > ball->position.y)
    {
        player->position.y -= player->speed;
    }
    else if (player->position.y + PADDLE_HEIGHT / 2 <= ball->position.y)
    {
        player->position.y += player->speed;
    }
    paddle_limit_movement(player);
}

#endif