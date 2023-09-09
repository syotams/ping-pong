/*******************************************************************************************
 *
 *   raylib [core] example - Basic 3d example
 *
 *   Welcome to raylib!
 *
 *   To compile example, just press F5.
 *   Note that compiled executable is placed in the same folder as .c file
 *
 *   You can find all basic examples on C:\raylib\raylib\examples folder or
 *   raylib official webpage: www.raylib.com
 *
 *   Enjoy using raylib. :)
 *
 *   This example has been created using raylib 1.0 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
 *
 *   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/
#include "raylib.h"
#include "models/paddle.h"
#include "models/cpu_paddle.h"
#include "models/ball.h"
#include "models/game_logic.h"
#include "models/game_constans.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(Paddle *player, Ball *ball, Paddle *cpu_player); // Update and draw one frame

bool Paused = false;

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(PONG_SCREEN_WIDTH, PONG_SCREEN_HEIGHT, "Ping Pong");

    // {.box = {0, PONG_SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2,}, .speed = 5}
    Paddle player = paddle_create(0, PONG_SCREEN_HEIGHT / 2 - PADDLE_HEIGHT, 5);
    Paddle cpu_player = paddle_create(PONG_SCREEN_WIDTH - PADDLE_WIDTH, PONG_SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, 5);
    Ball ball = ball_create(PONG_SCREEN_HEIGHT / 2, PONG_SCREEN_WIDTH / 2, 6, 6);

    //--------------------------------------------------------------------------------------

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            Paused = !Paused;
        }
        UpdateDrawFrame(&player, &ball, &cpu_player);
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(Paddle *player, Ball *ball, Paddle *cpu_player)
{
    // Update
    //----------------------------------------------------------------------------------
    if (!Paused)
    {
        paddle_update(player);
        cpu_paddle_update(cpu_player, ball);
        ball_update(ball);

        detect_collision(ball, player);
        detect_collision(ball, cpu_player);
        update_score(ball);
    }

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    game_engine_draw();
    paddle_drawer(player);
    paddle_drawer(cpu_player);
    ball_drawer(ball);
    game_engine_draw_score();

    if (Paused)
    {
        DrawText("Paused", PONG_SCREEN_WIDTH / 2 - 72, PONG_SCREEN_HEIGHT / 2 - 20, 40, Green);
    }
    // DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}