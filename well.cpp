#include "well.h"

Well::~Well()
{
    for(uint i=0; i<width_; ++i)
        delete[] map_[i];
    delete[] map_;
}

Well::Well(uint w, uint h):width_(w),height_(h)
{
    map_ = new bool*[height_];
    for(uint y=0; y<height_; ++y)
    {
        map_[y] = new bool[width_];
        for(uint x=0; x<width_; ++x)
            map_[y][x] = false;
    }
}

void Well::addFigure(const Figure &f)
{
    for(int y=0; y<4; ++y)
        for(int x=0; x<4; ++x)
        {
            int wx = x + f.x(),
                wy = y + f.y();
            if(wx >= 0 && wx < width_ && wy >= 0 && wy < height_ )
                map_[wy][wx] = map_[wy][wx] || f.map(x, y);
        }
}

bool Well::isCollision(const Figure &f) const
{
    for(int y=0; y<4; ++y)
        for(int x=0; x<4; ++x)
        {
            if(f.map(x, y))
            {
                int wx = x + f.x(),
                    wy = y + f.y();
                if(wx < 0 || wx >= width_ || wy < 0 || wy >= height_  || map_[wy][wx])
                    return true;
            }
        }
    return false;
}

uint Well::checkLines()
{
    int result = 0;
    for(int y=0; y<height_; ++y)
    {
        bool solid = true;
        for(int x=0; x<width_; ++x)
        {
            if(!map_[y][x])
            {
                solid = false;
                break;
            }
        }

        if(solid)
        {
            ++result;
            for(int yy=y; yy>0; --yy)
                for(int xx=0; xx<width_; ++xx)
                    map_[yy][xx] = map_[yy-1][xx];
            for(int xx=0; xx<width_; ++xx)
                map_[0][xx] = false;
        }
    }

    return result;
}
