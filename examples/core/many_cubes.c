/*******************************************************************************************
 *
 *   raylib [core] example - World to screen
 *
 *   This example has been created using raylib 1.3 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *for details)
 *
 *   Copyright (c) 2015 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h"
#include <stdio.h>
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - 3d camera free");

  // Define the camera to look into our 3d world
  Camera camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
  Vector2 cubeScreenPosition = {0.0f, 0.0f};

  SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------
  int i = 1;
  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    UpdateCamera(&camera); // Update camera

    // Calculate cube screen space position (with a little offset to be in top)
    cubeScreenPosition = GetWorldToScreen(
        (Vector3){cubePosition.x, cubePosition.y + 2.5f, cubePosition.z},
        camera);
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera);
    for (int j = 0; j < i; ++j) {
      float x1 = GetRandomValue(-10, 10);
      float y1 = GetRandomValue(-10, 10);
      float z1 = GetRandomValue(-10, 10);
      float x2 = GetRandomValue(-10, 10);
      float y2 = GetRandomValue(-10, 10);
      float z2 = GetRandomValue(-10, 10);
      DrawLine3D((Vector3){x1, y1, z1}, (Vector3){x2, y2, z2}, BLACK);
      /*DrawCube((Vector3){x, y, z}, 2.0f, 2.0f, 2.0f, RED);*/
    }

    for (int j = 0; j < i; ++j) {
      float x1 = GetRandomValue(-10, 10);
      float y1 = GetRandomValue(-10, 10);
      float z1 = GetRandomValue(-10, 10);
      DrawCube((Vector3){x1, y1, z1}, 2.0, 2.f, 2.f, RED);
    }

    EndMode3D();
    EndDrawing();
    printf("%i\n", i);
    i += 10;
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
