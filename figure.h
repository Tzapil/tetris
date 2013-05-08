#ifndef FIGURE_H
#define FIGURE_H

#include <string.h>
#include <stdlib.h>

namespace{
    typedef unsigned uint;
}

//класс падающей фигуры
class Figure
{
public:
    enum Direction{Rigth = -1, Left = 1};           // множество направлений вращения

    Figure(uint x = 3, uint y = 0, uint angle = 0);
    ~Figure();

    void move(uint dx = 0, uint dy = 0);            // сдвинуть фигуру
    void rotation(Direction d);                     // поворот

    bool map(uint x, uint y) const;                 // вернуть значение поля фигуры(true-поле занято, false - свободно)

    inline uint x() const {return x_;}
    inline uint y() const {return y_;}

protected:
    void copy_figure(uint n);
    uint length(const char *str) const;

private:
    char *map_;

    uint angle_,
         x_,y_;
};

#endif // FIGURE_H
