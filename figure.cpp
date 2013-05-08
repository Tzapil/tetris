#include "figure.h"
#include "figures.h"

Figure::Figure(uint x, uint y, uint angle):angle_(angle),x_(x),y_(y)
{
    copy_figure((uint)rand()%7);
}

Figure::~Figure()
{
    delete[] map_;
}

void Figure::move(uint dx, uint dy)
{
    x_ += dx;
    y_ += dy;
}

bool Figure::map(uint x, uint y) const
{
    static const struct
    {
      int x, y;
    } ROTATE[][16] = {
      {
        { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 },
        { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 },
        { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 },
        { 3, 0 }, { 3, 1 }, { 3, 2 }, { 3, 3 }
      },
      {
        { 3, 0 }, { 2, 0 }, { 1, 0 }, { 0, 0 },
        { 3, 1 }, { 2, 1 }, { 1, 1 }, { 0, 1 },
        { 3, 2 }, { 2, 2 }, { 1, 2 }, { 0, 2 },
        { 3, 3 }, { 2, 3 }, { 1, 3 }, { 0, 3 }
      },
      {
        { 3, 3 }, { 3, 2 }, { 3, 1 }, { 3, 0 },
        { 2, 3 }, { 2, 2 }, { 2, 1 }, { 2, 0 },
        { 1, 3 }, { 1, 2 }, { 1, 1 }, { 1, 0 },
        { 0, 3 }, { 0, 2 }, { 0, 1 }, { 0, 0 }
      },
      {
        { 0, 3 }, { 1, 3 }, { 2, 3 }, { 3, 3 },
        { 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 },
        { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 },
        { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }
      }
    };
    return map_[ROTATE[angle_][y * 4 + x].y * 4 +
                ROTATE[angle_][y * 4 + x].x] != ' ';
}

void Figure::rotation(Direction d)
{
    angle_ = (angle_ + d + 4)%4;
}

void Figure::copy_figure(uint n)
{
    int l = strlen(figures[n]);
    map_ = new char[l];
    for(int i=0; map_[i] = figures[n][i]; ++i);
}

uint Figure::length(const char *str) const
{
    uint l = 0;
    for(;str[l++];);

    return l;
}
