#include "raylib.h"


int main()
{
    //window dimensions
    int width{800};
    int height{450};
    InitWindow(width,height,"Raya");

    //circle cordinats
    int circle_x{200};
    int circle_y{200};

    //axe cordinats
    int axe_x{400};
    int axe_y{0};

    int direction{10};

    SetTargetFPS(60);
     while (WindowShouldClose() == false )
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //Game logig begins

        DrawCircle (circle_x,circle_y,25,BLUE);
          }
        DrawRectangle(axe_x,axe_y,50,50,RED);

        //move the axe

        axe_y += direction;
        if (axe_y > 450)
        {
            direction = -direction;
        }
        

        if (IsKeyDown(KEY_D) && circle_x < 350)
        {
            circle_x += 10;
        }
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }
        DrawRectangle(axe_x,axe_y,50,50,RED);
        //move the axe
        axe_y += 10;
        
        

        //Her Game logig ends

        EndDrawing();
    }
   
}