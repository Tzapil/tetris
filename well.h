#ifndef WELL_H
#define WELL_H

#include "figure.h"
#include "painter.h"

namespace{
    typedef unsigned uint;
}

class Figure;
class Painter;

// Класс "колодца"
class Well
{
public:
    Well(uint w = 10, uint h = 20);
    ~Well();

    void addFigure(const Figure &f);         // Добавление фигуры в колодец
    bool isCollision(const Figure &f) const; // Проверка коллизий фигуры

    void draw(Painter &p);

    uint checkLines();                       // Проверка и удаление заполненных строк
private:
    uint width_;
    uint height_;
    bool **map_;                             //Собственно колодец
};

#endif // WELL_H
