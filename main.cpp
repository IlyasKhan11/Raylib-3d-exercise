#include <iostream>
#include <raylib.h>

using namespace std;

int main() {
    // Initialize the window
    InitWindow(1000, 700, "Raylib Follow Along");

    // Load the texture
    Texture2D spaceship = LoadTexture("spaceship.png"); // Ensure the path is correct
    Vector2 spaceshipMovement = { 100, 100 }; // Initial position of the spaceship

    // Set the movement speed
    int speed=10;

    while (!WindowShouldClose()) {
        // Update spaceship position based on arrow key input
        
        DrawTextureV(spaceship,GetMousePosition(),WHITE);

        // Drawing begins
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the spaceship texture at its updated position
        DrawTextureV(spaceship, spaceshipMovement, WHITE);

        EndDrawing();
    }

    // Unload the texture and close the window
    UnloadTexture(spaceship);
    CloseWindow();

    return 0;
}
