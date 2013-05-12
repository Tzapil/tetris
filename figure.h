#ifndef FIGURE_H
#define FIGURE_H

#include <string.h>
#include <stdlib.h>

#include "painter.h"

namespace{
    typedef unsigned uint;
}

class Painter;

//класс падающей фигуры
class Figure
{
public:
    enum Direction{Rigth = -1, Left = 1};           // множество направлений вращения

    Figure(uint x = 3, uint y = 0, uint angle = 0);
    Figure(const Figure &c_);
    ~Figure();

    void move(int dx = 0, int dy = 0);              // сдвинуть фигуру
    void rotation(Direction d);                     // поворот

    void draw(Painter &p);                          // рисование

    int map(uint x, uint y) const;                  // вернуть значение поля фигуры(true-поле занято, false - свободно)

    inline int x() const {return x_;}
    inline int y() const {return y_;}
    inline uint angle() const{return angle_;}
    inline uint type() const{return type_;}
    inline int color() const{return color_;}
protected:
    void copy_figure(uint n);                       //метод-утилита, используется для копирования фигуры из массива figures

private:
    char *map_;                                     //задание фигуры строкой

    uint angle_,                                    //угол поворота (0-3)
         type_;

    int x_,y_;                                      //координаты (левый верхний угол блока 4*4)

    int color_;                                     //цвет фигуры
};

#endif // FIGURE_H
