#include "raylib.h"


int main()
{
    //window dimensions
    int width{800};
    int height{450};
    InitWindow(width,height,"Axe_Game");

    //circle cordinats
    int circle_x{300};
    int circle_y{300};
    int circle_radius{35};

    //circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};


    //axe cordinats
    int axe_x{500};
    int axe_y{0};
    int axe_lenght{60};

    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_lenght};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_lenght};

    int direction{10};

    bool collision_with_axe = 
                       (b_axe_y >= u_circle_y) && 
                       (u_axe_y <= b_circle_y) && 
                       (r_axe_x >= l_circle_x) &&
                       (l_axe_x <= r_circle_x);

    SetTargetFPS(70);
     while (WindowShouldClose() == false )
    {
        BeginDrawing();
        ClearBackground(WHITE);
        if (collision_with_axe)
        {
            DrawText("Game Over!",400,200,20,RED);
        }
        else
        {
                //Game logig begins

                //update the edges
                l_circle_x = circle_x - circle_radius;
                r_circle_x = circle_x + circle_radius;
                u_circle_y = circle_y - circle_radius;
                b_circle_y = circle_y + circle_radius;

                l_axe_x = axe_x;
                r_axe_x = axe_x + axe_lenght;
                u_axe_y = axe_y;
                b_axe_y = axe_y + axe_lenght;

                //update collision_with_axe
                collision_with_axe = 
                       (b_axe_y >= u_circle_y) && 
                       (u_axe_y <= b_circle_y) && 
                       (r_axe_x >= l_circle_x) &&
                       (l_axe_x <= r_circle_x);


            DrawCircle (circle_x,circle_y,circle_radius,BLUE);
            DrawRectangle(axe_x,axe_y,axe_lenght,axe_lenght,RED);

            //move the axe

            axe_y = axe_y + direction;
            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }
            
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x = circle_x + 10;
            } 

            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x = circle_x - 10;
            }
        

            //Her Game logig ends
        }


        EndDrawing();
     }
    }
