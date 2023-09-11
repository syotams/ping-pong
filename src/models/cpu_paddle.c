#include "cpu_paddle.h"

void cpu_paddle_update(Paddle *player, Ball *ball)
{
    if (player->box.y + PADDLE_HEIGHT / 2 > ball->position.y)
    {
        player->box.y -= player->speed;
    }
    else if (player->box.y + PADDLE_HEIGHT / 2 <= ball->position.y)
    {
        player->box.y += player->speed;
    }
    paddle_limit_movement(player);
}