#include "Canvas.h"
#include <iostream>
bool on_the_borders(int lin, int col, int x, int y, int r)
{
    return ((lin-x)*(lin-x)+(col-y)*(col-y) >= r*(r-1)) && ((lin-x)*(lin-x)+(col-y)*(col-y) <= r*(r+1));
}
Canvas::Canvas(int width, int height)
{
    this -> w = width;
    this -> h = height;

    this->mat = new char*[height];
    for (int ind = 0; ind < height; ind++)
    {
        this->mat[ind] = new char[width];
    }
}
void Canvas::DrawCircle(int x, int y, int r, char ch)
{
    for (int lin = 0; lin < this->h; lin++)
    {
        for (int col = 0; col < this->w; col++)
        {
            if (on_the_borders(lin, col, x, y, r))
            {
                this->mat[lin][col] = ch;
            }
            else
            {
                this->mat[lin][col] = ' ';
            }
        }
    }
}
void Canvas::FillCircle(int x, int y, int r, char ch)
{
    for (int lin = 0; lin < this->h; lin++)
    {
        for (int col = 0; col < this->w; col++)
        {
            if ((lin - x) * (lin - x) + (col - y) * (col - y) <= r * r && !on_the_borders(lin, col, x, y, r))
            {
                this->mat[lin][col] = ch; 
            }
        }
    }
}
void Canvas::Print()
{
    for (int lin = 0; lin < this->h; lin++)
    {
        for (int col = 0; col < this->w; col++)
        {
            std::cout << this->mat[lin][col] << ' ';
        }
        std::cout << '\n';
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int lin = 0; lin < this->h; lin++)
    {
        for (int col = 0; col < this->w; col++)
        {
            if ((col >= left && col <= right) && (lin == top || lin == bottom) ||
            (lin >= top && lin <= bottom) && (col == left || col == right))
            {
                mat[lin][col] = ch;
            }
            else
            {
                mat[lin][col] = ' ';
            }
        }
    }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int lin = 0; lin < this->h; lin++)
    {
        for (int col = 0; col < this->w; col++)
        {
            if (lin < bottom && lin > top && col > left && col < right)
            {
                mat[lin][col] = ch;
            }
            else if (!((col >= left && col <= right) && (lin == top || lin == bottom) ||
            (lin >= top && lin <= bottom) && (col == left || col == right)))
            {
                mat[lin][col] = ' ';
            }
        }
    }
}
void Canvas::SetPoint(int x, int y, char ch)
{
    mat[x][y] = ch;
}
void Canvas::Clear()
{
    for (int lin = 0; lin < this->h; lin++)
    {
        for (int col = 0; col < this->w; col++)
        {
            mat[lin][col] = ' ';
        }
    }
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int error = dx + dy, e2;
    
    while (true)
    {
        this->SetPoint(x1, y1, ch);
        e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x1 == x2)
            {
                break;
            }
            error = error + dy;
            x1 = x1 + sx;
        }
        if (e2 <= dx)
        {
            if (y1 == y2)
            {
                break;
            }
            error = error + dx;
            y1 = y1 + sy;
        }
    }
}