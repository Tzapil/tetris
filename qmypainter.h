#ifndef QMYPAINTER_H
#define QMYPAINTER_H

#include "painter.h"

#include <QtGlobal>
#include <QWidget>
#include <QPainter>

class QMyPainter : public Painter
{
public:
    QMyPainter(QWidget& wdg, uint rw, uint rh);
    ~QMyPainter();

    virtual void drawPoint(int x, int y);
    virtual void setColor(int r, int g, int b);
private:
    uint width_,
         height_;

    QPainter p_;
};

#endif // QMYPAINTER_H
