#ifndef GAME_HEADER
#define GAME_HEADER

#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include "game_constans.h"

typedef struct
{
    int player_score;
    int cpu_score;
} GameLogic;

GameLogic game_logic = {0, 0};

void game_engine_detect_collision(Ball *ball, Paddle *player)
{
    if (CheckCollisionCircleRec(ball->position, ball->radius, player->box))
    {
        ball_flip_x_direction(ball);
    }
}

void game_engine_update_score(Ball *ball)
{
    if (ball->position.x <= ball->radius)
    {
        game_logic.cpu_score++;
        ball_reset(ball);
    }
    else if (ball->position.x >= PONG_SCREEN_WIDTH - PADDLE_WIDTH)
    {
        game_logic.player_score++;
        ball_reset(ball);
    }
}

void game_engine_draw_score()
{
    DrawText(TextFormat("%i", game_logic.player_score), PONG_SCREEN_WIDTH / 4, 20, 80, WHITE);
    DrawText(TextFormat("%i", game_logic.cpu_score), 3 * PONG_SCREEN_WIDTH / 4, 20, 80, WHITE);
}

void game_engine_draw()
{
    ClearBackground(PONG_DARK_GREEN);
    DrawRectangle(0, 0, PONG_SCREEN_WIDTH / 2, PONG_SCREEN_HEIGHT, PONG_GREEN);
    DrawCircle(PONG_SCREEN_WIDTH / 2, PONG_SCREEN_HEIGHT / 2, 75, PONG_LIGHT_GREEN);
    DrawLine(PONG_SCREEN_WIDTH / 2, 0, PONG_SCREEN_WIDTH / 2, PONG_SCREEN_HEIGHT, WHITE);
}

#endif // GAME_HEADER
