#include "raylib.h"

int main() {
    // Initialize the window
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "3D base");

    // Define the 3D camera
    Camera3D camera = { 0 };
    camera.position = Vector3{ -3.0f, 6, 5.0f }; // Camera position
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };   // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };       // Camera up vector (normalized)
    camera.fovy = 90.0f;                           // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;        // Camera mode: perspective

    // -----------------------------------------------------------------------------------------------------
    // MODELS
    // --------------------------------------------------------------------------------------------------------
    Mesh meshCube = GenMeshCube(1.0f, 1.0f, 1.0f);      // Cube mesh
    Mesh meshCylinder = GenMeshCylinder(1.0f, 2.0f, 20); // Cylinder mesh (radius, height, sides)

    Model modelCube = LoadModelFromMesh(meshCube);        // Load model from cube mesh
    Model modelCylinder = LoadModelFromMesh(meshCylinder); // Load model from cylinder mesh

    // -----------------------------------------------------------------------------------------------------
    // TEXTURES
    // --------------------------------------------------------------------------------------------------------
    Image image = GenImageGradientLinear(20, 20, 1, RED, YELLOW);  // Create a gradient image
    Texture texture = LoadTextureFromImage(image);                 // Load texture from image
    UnloadImage(image);                                             // Unload the image after creating the texture
    // -----------------------------------------------------------------------------------------------------
    // MOVEMENTS
    // --------------------------------------------------------------------------------------------------------
    Vector3 pos={};
    // Assign texture to the cylinder model's material
    if (modelCylinder.materials[0].maps[MATERIAL_MAP_ALBEDO].texture.id == 0) {
        SetMaterialTexture(&modelCylinder.materials[0], MATERIAL_MAP_ALBEDO, texture);
    }

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
        DrawGrid(10, 1.0f);



        // Draw the cube and cylinder models with transformations
        // DrawModel(modelCube, Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, BLUE);
        DrawModel(modelCylinder, pos, 1.0f, ORANGE);

        pos.x+=2*dt;

        // Draw a line in 3D space
        DrawLine3D(Vector3{ -4.0f, 0.0f, -1.0f }, Vector3{ 5.0f, 2.0f, 3.0f }, BLACK);

        // End 3D mode
        EndMode3D();

        // End drawing
        EndDrawing();
    }

    // Close the window and clean up resources
    CloseWindow(); // Close the window and OpenGL context

    return 0;
}
