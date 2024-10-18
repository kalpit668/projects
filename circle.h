// circle.h
// Kalpit Sharma
// 012633349
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
//defining class
class Circle :public Shape
{
private:
    char m_char;
public:
    Circle(int x, int y);
    void draw(Grid &grid) override;
};

#endif