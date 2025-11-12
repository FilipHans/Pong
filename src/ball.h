#pragma once

class Ball
{
public:
    Ball();
    void Update();
    void Draw() const;
    void Reset();
    float x;
    float y;
    int speedX;
    int speedY;

private:
    int radius;
};