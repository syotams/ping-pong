#ifndef GAME_HEADER
#define GAME_HEADER

#include "raylib.h"
#include "ball.h"
#include "paddle.h"

void detect_collision(Ball *ball, Paddle *player)
{
    Rectangle rec = {player->position.x, player->position.y, PADDLE_WIDTH, PADDLE_HEIGHT};

    if (CheckCollisionCircleRec(ball->position, ball->radius, rec))
    {
        ball_flip_x_direction(ball);
    }
}

#endif // GAME_HEADER
