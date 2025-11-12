#include "ball.h"
#include <raylib.h>
#include <vector>
#include "player1.h"
#include "player2.h"
    const int screen_width = 1280;
    const int screen_height = 800;
    Player1 player1;
    Player2 player2;
    extern int player1_score;
    extern int player2_score;
Ball::Ball() 
    : x(screen_width / 2)
    , y(screen_height / 2)
    , speedX(5)
    , speedY(5)
    , radius(20) 
{
}

void Ball::Reset()
{
    x = screen_height/2;
    y = screen_width/2;
}

void Ball::Update() 
{
    x += speedX;
    y += speedY;

    if((x + radius) >= screen_width)
    {
        player1_score += 1;
        Reset();
    } 
    if ((x - radius) <= 0) 
    {
        player2_score += 1;
        Reset();
    }

    if((y + radius) >= screen_height || (y - radius) <= 0)
    {
        speedY *= -1;
    }
    
}

void Ball::Draw() const
{
    DrawCircle(x, y, radius, WHITE);
}