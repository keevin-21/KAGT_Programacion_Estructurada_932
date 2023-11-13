#include "raylib.h"

#define NUM_FRAMES 1 // Number of frames (rectangles) for the button sprite texture

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite button");

    InitAudioDevice(); // Initialize audio device

    Sound fxButton = LoadSound("resources/buttonfx.wav");           // Load button sound
    Texture2D playButton = LoadTexture("resources/playbutton.png"); // Load button texture

    // Define frame rectangle for drawing
    float frameHeight = (float)playButton.height / NUM_FRAMES;
    Rectangle sourceRec = {0, 0, (float)playButton.width, frameHeight};

    // Define button bounds on screen
    Rectangle btnBounds = {screenWidth / 2.0f - playButton.width / 2.0f, screenHeight / 2.0f - playButton.height / NUM_FRAMES / 2.0f, (float)playButton.width, frameHeight};

    int btnState = 0;       // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false; // Button action should be activated

    Vector2 mousePoint = {0.0f, 0.0f};

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        mousePoint = GetMousePosition();
        btnAction = false;

        // Check button state
        if (CheckCollisionPointRec(mousePoint, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                btnState = 2;
            else
                btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                btnAction = true;
        }
        else
            btnState = 0;

        if (btnAction)
        {
            PlaySound(fxButton);

            // TODO: Any desired action
        }

        // Calculate button frame rectangle to draw depending on button state
        sourceRec.y = btnState * frameHeight;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureRec(playButton, sourceRec, (Vector2){btnBounds.x, btnBounds.y}, WHITE); // Draw button frame

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(playButton); // Unload button texture
    UnloadSound(fxButton);     // Unload sound

    CloseAudioDevice(); // Close audio device

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}