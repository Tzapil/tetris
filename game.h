#ifndef GAME_H
#define GAME_H

#include "well.h"
#include "figure.h"
#include "painter.h"

namespace{
    typedef unsigned uint;
}

class Game
{
public:
    enum Direction{Up, Down, Left, Right};

    Game(uint w = 10, uint h = 20);
    ~Game();

    void move();
    void reset();

    void draw(Painter &p);

    void keyEvent(Direction d);

    inline uint score() const {return score_;}

private:
    Well *well_;
    Figure *figure_;

    uint score_;
};

#endif // GAME_H
