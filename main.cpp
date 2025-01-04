#include "raylib.h"

int main() {
    // Initialize the window
    InitWindow(1920, 1080, "3D imports");

    // Define the camera
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 5.0f, 5.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // #MODELS
    // Model ship=LoadModel("./models/ship.glb");
    Model rupee=LoadModel("./models/rupee.gltf");
    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        // Begin drawing
        BeginDrawing();
        
        ClearBackground(WHITE);

        // Begin 3D mode
        BeginMode3D(camera);

        // Draw the grid
        DrawGrid(10, 1.0f);

        // DrawModel(ship,Vector3(),1,WHITE);
        DrawModel(rupee,Vector3(),1,WHITE);

        // End 3D mode
        EndMode3D();

        // End drawing
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
