// grid.cpp
// Kalpit Sharma
// 012633349
#include "grid.h"
#include<iostream>
using namespace std;
// Constructor
 Grid::Grid(){
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            m_grid[i][j] = ' ';
        }
    }
}
//set
void Grid::set(int x, int y, char c){
    if (x>=0 && x<COLS && y>=0 && y<ROWS)
    {
        m_grid[x][y] = c;
    }
}
//print
void Grid::print(){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {  
            cout<<m_grid[j][i];  
        }
        cout<<endl;
    }
}