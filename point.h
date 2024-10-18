// grid.h
// Kalpit Sharma
// 012633349
#ifndef POINT_H
#define POINT_H

#include "shape.h"
//defining class
class Point :public Shape
{
private:
    char m_char;
public:
    Point(int x, int y, char c);
    
    void draw(Grid &grid) override;
};

#endif