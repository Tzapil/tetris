#include "figure.h"
#include "figures.h"

Figure::Figure(uint x, uint y, uint angle):type_((uint)rand() % 7),angle_(angle),x_(x),y_(y),color_(rand() % 20 + 1)
{
    copy_figure(type_);
}

Figure::Figure(const Figure &c_):type_(c_.type()),angle_(c_.angle()),x_(c_.x()),y_(c_.y()),color_(c_.color())
{
    copy_figure(type_);
}

Figure::~Figure()
{
    for(int i=0; i<4; ++i)
        delete[] map_[i];
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
    return (map_[angle_][x + y*4] != ' '? color_:0);
}

void Figure::rotation(Direction d)
{
    angle_ = (angle_ + d + 4)%4;
}

void Figure::copy_figure(uint n)
{
    for(int i=0; i<4; ++i)
    {
        map_[i] = new char[17];
        for(int j=0; map_[i][j] = figures[n][i][j]; ++j);
    }
}
