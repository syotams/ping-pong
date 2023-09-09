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

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
Camera camera = {0};
Vector3 cubePosition = {0};

//------- Custom code by Yotam --------

//------- End of custom code by Yotam --------

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(Paddle *player, Ball *ball, Paddle *cpu_player); // Update and draw one frame

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int screenPadding = 10;

    InitWindow(screenWidth, screenHeight, "raylib");

    camera.position = (Vector3){10.0f, 10.0f, 8.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Paddle player = {.position = {0, screenHeight / 2 - PADDLE_HEIGHT / 2}, .speed = 5};
    Paddle cpu_player =
        {.position = {screenWidth - PADDLE_WIDTH, screenHeight / 2 - PADDLE_HEIGHT / 2}, .speed = 5};
    Ball ball = {.position = {screenHeight / 2, screenWidth / 2}, .speed = {6, 6}, 10};

    //--------------------------------------------------------------------------------------

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
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
    UpdateCamera(&camera, CAMERA_ORBITAL);
    //----------------------------------------------------------------------------------
    paddle_update(player);
    cpu_paddle_update(cpu_player, ball);
    ball_update(ball);

    detect_collision(ball, player);
    detect_collision(ball, cpu_player);

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    paddle_drawer(player);
    paddle_drawer(cpu_player);
    ball_drawer(ball);

    // DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}