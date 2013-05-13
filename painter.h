#ifndef PAINTER_H
#define PAINTER_H

// Абстрактный класс для рисования
class Painter
{
public:
    virtual void drawPoint(int x, int y) = 0;           // нарисовать точку
    virtual void setColor(int r, int g, int b) = 0;     // сменить цвет
    virtual void setColor(int color) = 0;               //
};

#endif // PAINTER_H
