#include "raylib.h"
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include <algorithm> 
#include<math.h>

struct Circle {
    Vector2 position;
    float radius;
    Color color;
};

int main() {
    // Initialization
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Camera");
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    // Player
    Vector2 playerPos = { 0.0f, 0.0f };
    float playerRadius = 50.0f;
    Vector2 direction = { 0.0f, 0.0f };
    float speed = 400.0f;

    // Circles
    std::vector<Circle> circles;
    for (int i = 0; i < 100; ++i) {
        Circle circle;
        circle.position = { static_cast<float>(rand() % 4000 - 2000), static_cast<float>(rand() % 2000 - 1000) };
        circle.radius = static_cast<float>(rand() % 151 + 50); // Random radius between 50 and 200

        // Random color
        switch (rand() % 5) {
            case 0: circle.color = RED; break;
            case 1: circle.color = GREEN; break;
            case 2: circle.color = BLUE; break;
            case 3: circle.color = YELLOW; break;
            case 4: circle.color = ORANGE; break;
        }

        circles.push_back(circle);
    }

    // Camera
    Camera2D camera = { 0 };
    camera.target = playerPos;
    camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60); // Lock FPS to 60

    while (!WindowShouldClose()) {
        // Input
        direction.x = (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT));
        direction.y = (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP));

        // Normalize direction
        float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
        if (magnitude != 0.0f) {
            direction.x /= magnitude;
            direction.y /= magnitude;
        }

        // Movement
        float dt = GetFrameTime();
        playerPos.x += direction.x * speed * dt;
        playerPos.y += direction.y * speed * dt;

        // Camera updates
        float rotateDirection = (IsKeyDown(KEY_S) - IsKeyDown(KEY_A));
        camera.rotation += rotateDirection * dt * 50.0f;

        float zoomDirection = (IsKeyDown(KEY_W) - IsKeyDown(KEY_Q));
        camera.zoom += zoomDirection * dt * 2.0f;
        camera.zoom = std::max(0.2f, std::min(2.0f, camera.zoom)); // Clamp zoom between 0.2 and 2.0

        camera.target = playerPos;

        // Drawing
        BeginDrawing();
        ClearBackground(WHITE);

        BeginMode2D(camera);
        for (const Circle& circle : circles) {
            DrawCircleV(circle.position, circle.radius, circle.color);
        }
        DrawCircleV(playerPos, playerRadius, BLACK);
        EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
