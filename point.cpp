// point.cpp
// Kalpit Sharma
// 012633349
#include "point.h"
//constructor
Point::Point(int x, int y, char c) : Shape(x,y), m_char(c){}

//Draw function overloading
void Point::draw(Grid &grid){
    grid.set(m_x, m_y, m_char);
}