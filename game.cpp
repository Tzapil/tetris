#include "game.h"

Game::Game()
{
}

Game::~Game()
{
    delete figure_;
    delete well_;
}

void Game::move()
{

}

void Game::reset()
{
    delete well_;
    delete figure_;

    well_ = new Well();
    figure_ = new Figure();
}
