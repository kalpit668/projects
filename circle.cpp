#include "circle.h"
#include <iostream>
using namespace std;

Circle::Circle(int x, int y) : Shape(x,y), m_char('o'){}
void Circle::draw(Grid &grid){

    // First row
        // First row (no horizontal gap)
grid.set(m_x + 1, m_y, m_char);
grid.set(m_x + 2, m_y, m_char);

// Second row (characters closer together)
grid.set(m_x , m_y + 1, m_char);
grid.set(m_x + 3, m_y + 1, m_char);

// Third row (same as second row, no horizontal gap)
grid.set(m_x , m_y + 2, m_char);
grid.set(m_x + 3, m_y + 2, m_char);

// Fourth row (same as the first row, no horizontal gap)
grid.set(m_x + 1, m_y + 3, m_char);
grid.set(m_x + 2, m_y + 3, m_char);


}
