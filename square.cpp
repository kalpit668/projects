// square.cpp
// Kalpit Sharma
// 012633349
#include "square.h"
#include <iostream>
using namespace std;

Square::Square(int x, int y, int size) : Shape(x,y), m_char('*'), m_size(size){}
void Square::draw(Grid &grid){
//set starts at x,y and set a square for the given size
    for (int i = 0; i < m_size; i++) {
            for (int j = 0; j < m_size; j++) {
                // If we are on the border, set '+', else set space in the middle
                if (i == 0 || i == m_size - 1 || j == 0 || j == m_size - 1) {
                    grid.set(m_x + j, m_y + i, m_char);
                } 
            }
        }

}
