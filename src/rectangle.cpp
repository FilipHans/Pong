#include "player1.h"
#include "player2.h"
#include <raylib.h>

    const int screen_width = 1280;
    const int screen_height = 800;

Player1::Player1()
    :y(screen_height / 2 - 60)
    ,x(10)
    ,height(120)
    ,width(25)
{

}

Player2::Player2()
    :y(screen_height / 2 - 60)
    ,x(screen_width - 35)
    ,height(120)
    ,width(25)

{

}

void Player2::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        y <= 0 ? y = y : y -= 8;
    }
    if(IsKeyDown(KEY_DOWN))
    {
        y + 120 >= 800 ? y = y : y += 8 ;
    }
  
}
void Player1::Update()
{
    if (IsKeyDown(KEY_W))
    {
        y <= 0 ? y = y : y -= 8;
    }
    if(IsKeyDown(KEY_S))
    {
        y + 120 >= 800 ? y = y : y += 8 ;
    }
  
}

void Player1::Draw() const
{
    DrawRectangle(x, y, width, height, WHITE);

}


void Player2::Draw() const
{
    DrawRectangle(x, y, width, height, WHITE);
}
