#include <raylib.h>
#include "ball.h"
#include <iostream>
#include "player1.h"
#include "player2.h"
#include <cmath>

using namespace std;
int player1_score = 0;
int player2_score = 0;
int speed_Increase = 2;
float previous_player1_position; 
float previous_player2_position; 
int main() 
{
    
    const int screen_width = 1280;
    const int screen_height = 800;
    Ball ball;
    Player1 player1;
    Player2 player2;
    
    InitWindow(screen_width, screen_height, "My Pong Game!");
    SetTargetFPS(60);
    
    while (WindowShouldClose() == false) {
        BeginDrawing();

        // Update position
        ball.Update();
        player1.Update();
        player2.Update();

        DrawLine(screen_width / 2, 0,screen_width / 2, screen_height, WHITE);

        // Checks collition between ball and player
        if (CheckCollisionCircleRec({ball.x, ball.y}, 20, {player1.x, player1.y, player1.width, player1.height}))
        {
            int trajectory_Change = 2;
            // tripple ternary of doom, checks if player has moved paddle from previous iteration and adjusts speedY accordingly.
            // Tripple ternary to check if speedY is positive or negative
            ball.speedY += player1.y == previous_player1_position ? ball.speedY < 0 ? trajectory_Change : -trajectory_Change : ball.speedY < 0 ? -trajectory_Change : trajectory_Change;
            if (ball.speedX < 0)
            {
                ball.speedX -= speed_Increase;
            } else 
            {
                ball.speedX += speed_Increase;
            }
            // returns ball to opposite side
            ball.speedX *= -1;
        }
        if (CheckCollisionCircleRec({ball.x, ball.y}, 20, {player2.x, player2.y, player2.width, player2.height}))
        {
            int trajectory_Change = 2;
            ball.speedY += player2.y == previous_player2_position ? ball.speedY < 0 ? trajectory_Change : -trajectory_Change : ball.speedY < 0 ? -trajectory_Change : trajectory_Change;
            if (ball.speedX < 0)
            {
                ball.speedX -= speed_Increase;
            } else 
            {
                ball.speedX += speed_Increase;
            }
            ball.speedX *= -1;
        }
        // Stores Current position to check movement in next iteration
        previous_player1_position = player1.y;
        previous_player2_position = player2.y;
        // Clear previous drawing
        ClearBackground(PURPLE);
        // Drawing
        player1.Draw();
        player2.Draw();
        ball.Draw();
        // Display score
        DrawText(TextFormat("%i", player2_score), 780, 10, 80, WHITE);
        DrawText(TextFormat("%i", player1_score), 440, 10, 80, WHITE);
        // win con
        if (player1_score > 7)
        {
            DrawText(TextFormat("Player 1 won"), 500, screen_width / 2 - 500, 80, WHITE);
        } else if (player2_score > 7)
        {
            DrawText(TextFormat("Player 2 won"), 500, screen_width / 2 - 500, 80, WHITE);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}