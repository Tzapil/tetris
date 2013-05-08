#ifndef WELL_H
#define WELL_H

#include "figure.h"

namespace{
    typedef unsigned uint;
}

class Figure;

// Класс "колодца"
class Well
{
public:
    Well(uint w = 10, uint h = 20);
    ~Well();

    void addFigure(/*Figure*/);         // Добавление фигуры в колодец
    bool isCollision(/*Figure*/) const; // Проверка коллизий фигуры

    void checkLines();                  // Проверка и удаление заполненных строк
private:
    uint width_;
    uint height_;
    bool **map_;           //Собственно колодец
};

#endif // WELL_H
