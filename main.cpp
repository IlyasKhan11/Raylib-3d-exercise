#include "raylib.h"

int main() {
    // Initialize window and camera
    InitWindow(1920, 1080, "3D collisions");

    // Define the camera
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 50.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Load player model (small sphere)
    Model player = LoadModelFromMesh(GenMeshSphere(0.5f, 16, 16)); // Smaller sphere
    Vector3 playerPos = { 0.0f, 0.0f, 0.0f };
    Vector3 direction = { 0.0f, 0.0f, 0.0f };
    float speed = 5.0f;

    // Load obstacle model (large sphere)
    Model obstacle = LoadModelFromMesh(GenMeshSphere(2.0f, 32, 32)); // Larger sphere
    Vector3 obstaclePos = { 3.0f, 0.0f, 0.0f };

    // Main game loop
    while (!WindowShouldClose()) {
        // Input handling for movement
        direction.x = (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT));
        direction.z = (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP));

        // Movement
        float dt = GetFrameTime();
        playerPos.x += direction.x * speed * dt;
        playerPos.z += direction.z * speed * dt;

        // Drawing the scene
        BeginDrawing();
        ClearBackground(WHITE);

        // Begin 3D mode
        BeginMode3D(camera);

        // Draw the grid
        DrawGrid(10, 1.0f);

        // Draw player and obstacle models
        DrawModel(player, playerPos, 1.0f, RED);     // Player sphere
        DrawModel(obstacle, obstaclePos, 1.0f, GRAY); // Obstacle sphere

        // End 3D mode
        EndMode3D();

        // End drawing
        EndDrawing();
    }

    // Unload models
    UnloadModel(player);
    UnloadModel(obstacle);

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
