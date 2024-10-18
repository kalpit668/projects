// shape.h
// Kalpit Sharma
// 012633349

#ifndef SHAPE_H
#define SHAPE_H

#include "grid.h"
//defining shape class
class Shape {
  public:
    Shape(int x, int y);
    ~Shape();
    virtual void draw(Grid &grid) = 0;

  protected:
    int m_x;
    int m_y;
};

#endif
