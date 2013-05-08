#ifndef GAME_H
#define GAME_H

#include "well.h"
#include "figure.h"

class Game
{
public:
    Game();
    ~Game();

    void move();
    void reset();
private:
    Well *well_;
    Figure *figure_;
};

#endif // GAME_H
