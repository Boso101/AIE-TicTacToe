/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
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
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "DataFile.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    DataFile data;
    int currentRecordIdx = 0;

    data.Load("npc_data.dat");

    DataFile::Record* currentRecord = data.GetRecord(currentRecordIdx);
   
    //Have this so that we can cache the textures instead of having to load them over and over each time
    vector<Texture2D> loadedTextures;
  

    // Load up all textures first
    for (int i = 0; i < data.GetRecordCount() - 1; i++)
    {
        //Cache the texture
        loadedTextures.push_back(LoadTextureFromImage(data.GetRecord(i)->image));
    }

    Texture2D recordTexture = loadedTextures.at(0);
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        if (IsKeyPressed(KEY_LEFT))
        {
            currentRecordIdx--;
            if (currentRecordIdx < 0)
            {
                currentRecordIdx = 0;
            }
            currentRecord = data.GetRecord(currentRecordIdx);
            recordTexture = loadedTextures.at(currentRecordIdx);
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            currentRecordIdx++;
            // Make sure to start again if we go out of range
            if (currentRecordIdx > data.GetRecordCount() - 1)
            {
                currentRecordIdx = 0;
            }
            currentRecord = data.GetRecord(currentRecordIdx);
            recordTexture = loadedTextures.at(currentRecordIdx);

          
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(recordTexture, 300, 50, WHITE);

        DrawText("NAME", 10, 50, 20, LIGHTGRAY);
        DrawText(currentRecord->name.c_str(), 10, 80, 20, LIGHTGRAY);

        DrawText("AGE", 10, 120, 20, LIGHTGRAY);
        DrawText(to_string(currentRecord->age).c_str(), 10, 150, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}