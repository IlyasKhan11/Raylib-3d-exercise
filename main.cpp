#include "raylib.h"

int main() {
    // Initialize the window
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "3D base");

    // Define the 3D camera
    Camera3D camera = { 0 };
    camera.position = Vector3{ 0, 0.5f, 0.5f }; // Camera position
    camera.target = Vector3(); // Camera looking at point
    camera.up = Vector3{ 0.0f, 10, 0.0f };       // Camera up vector (normalized)
    camera.fovy = 90;                           // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;        // Camera mode: perspective

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Get delta time
        float dt = GetFrameTime();

        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // Begin 3D mode
        BeginMode3D(camera);

        // Draw a grid
        DrawGrid(10, 0.5);

        // End 3D mode
        EndMode3D();

        // End drawing
        EndDrawing();
    }

    // Close the window and clean up resources
    CloseWindow();

    return 0;
}
