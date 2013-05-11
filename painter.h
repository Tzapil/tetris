#ifndef PAINTER_H
#define PAINTER_H

class Painter
{
public:
    virtual void drawPoint(int x, int y) = 0;
    virtual void setColor(int r, int g, int b) = 0;
};

#endif // PAINTER_H
