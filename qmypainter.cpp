#include "qmypainter.h"

QMyPainter::QMyPainter(QWidget& wdg, uint x, uint y, uint rw, uint rh, QPainter *p):width_(rw), height_(rh),x_(x),y_(y)
{
    if(p)
    {
        p_ = p;
        del_p_ = false;
    }
    else
    {
        p_ = new QPainter();
        p_->begin(&wdg);
        del_p_ = true;
    }
    p_->setPen(QColor(0, 0, 0));
}

QMyPainter::~QMyPainter()
{
    if(del_p_)
    {
        p_->end();
        delete p_;
    }
}

void QMyPainter::drawPoint(int x, int y)
{
    p_->drawRect(x_ + x*width_, y_ + y*height_, width_, height_);
}

void QMyPainter::setColor(int r, int g, int b)
{
    p_->setBrush(QBrush(QColor(r, g, b)));
}

void QMyPainter::setColor(int color)
{
    p_->setBrush(QBrush(QColor(static_cast<Qt::GlobalColor>(color))));
}
