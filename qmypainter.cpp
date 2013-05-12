#include "qmypainter.h"

QMyPainter::QMyPainter(QWidget& wdg, uint rw, uint rh):width_(rw), height_(rh),p_(&wdg)
{
    p_.setPen(QColor(0, 0, 0));
}

QMyPainter::~QMyPainter()
{
    p_.end();
}

void QMyPainter::drawPoint(int x, int y)
{
    p_.drawRect(x*width_, y*height_, width_, height_);
}

void QMyPainter::setColor(int r, int g, int b)
{
    p_.setBrush(QBrush(QColor(r, g, b)));
}

void QMyPainter::setColor(int color)
{
    p_.setBrush(QBrush(QColor(static_cast<Qt::GlobalColor>(color))));
}
