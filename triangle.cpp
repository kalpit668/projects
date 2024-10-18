// triangle.cpp
// Kalpit Sharma
// 012633349
#include "triangle.h"
#include <iostream>
using namespace std;

//constructor
Triangle::Triangle(int x, int y) : Shape(x,y), m_char('+'){}

//Draw function
void Triangle::draw(Grid &grid){
    //initialising y-coordinate
    grid.set(m_x + 2, m_y, m_char);

        // Second row
        grid.set(m_x + 1, m_y + 1, m_char);
        grid.set(m_x + 3, m_y + 1, m_char);

        // Third row
        //Initialize at x-coordinate
        for (int i = 0; i <= 4; i++) {
            grid.set(m_x + i, m_y + 2, m_char);
        }

}
