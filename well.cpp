#include "well.h"

namespace{
    typedef unsigned uint;
}

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

void Well::addFigure(/*Figure*/)
{
}

bool Well::isCollision(/*Figure*/) const
{
    return true;
}

void Well::checkLines()
{

}
