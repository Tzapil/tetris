#include "figure.h"
#include "figures.h"

Figure::Figure(uint x, uint y, uint angle):type_((uint)rand() % 7),angle_(angle),x_(x),y_(y),color_(rand() % 19 + 1)
{
    copy_figure(type_);
}

Figure::Figure(const Figure &c_):type_(c_.type()),angle_(c_.angle()),x_(c_.x()),y_(c_.y()),color_(c_.color())
{
    copy_figure(type_);
}

Figure::~Figure()
{
    delete[] map_;
}

void Figure::draw(Painter &p)
{
    p.setColor(color_);
    for(int y=0; y<4; ++y)
        for(int x=0; x<4; ++x)
        {
            if(map(x, y))
                p.drawPoint(x_ + x, y_ + y);
        }
}

void Figure::move(int dx, int dy)
{
    x_ += dx;
    y_ += dy;
}

int Figure::map(uint x, uint y) const
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
    return (map_[ROTATE[angle_][y * 4 + x].y * 4 +
                ROTATE[angle_][y * 4 + x].x] != ' '? color_:0);
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
