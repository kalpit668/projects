// triangle.h
// Kalpit Sharma
// 012633349
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
class Triangle :public Shape
{
private:
    char m_char;
public:
    Triangle(int x, int y);
    void draw(Grid &grid) override;
};

#endif