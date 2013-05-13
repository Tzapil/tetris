#ifndef GAME_H
#define GAME_H

#include "well.h"
#include "figure.h"
#include "painter.h"

namespace{
    typedef unsigned uint;
}

// класс игры
class Game
{
public:
    enum Direction{Up, Down, Left, Right};      // множество клавиш, влияющих на игру

    Game(uint w = 10, uint h = 20);
    ~Game();

    void move();                                // сделать следующий шаг
    void reset();                               // перезапустить игру

    void draw(Painter &p);                      // нарисовать игру на painter

    void keyEvent(Direction d);                 // обработка нажатий клавиш

    inline uint score() const {return score_;}

private:
    Well *well_;                                // колодец
    Figure *figure_;                            // фигура

    uint score_;                                // счет
};

#endif // GAME_H
