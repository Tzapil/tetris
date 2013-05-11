#include "game.h"

Game::Game(uint w, uint h):score_(0),well_(new Well(w, h)),figure_(new Figure())
{}

Game::~Game()
{
    delete figure_;
    delete well_;
}

void Game::draw(Painter &p)
{
    figure_->draw(p);
    well_->draw(p);
}

void Game::move()
{
    Figure *fg_ = new Figure(*figure_);
    fg_->move(0, 1);
    if(well_->isCollision(*fg_))
    {
        well_->addFigure(*figure_);
        score_ += well_->checkLines();

        delete figure_;
        figure_ = new Figure();

        if(well_->isCollision(*figure_))
            reset();
    }
    else
    {
        Figure *a_ = fg_;
        fg_ = figure_;
        figure_ = a_;
    }

    delete fg_;
}

void Game::reset()
{
    delete well_;
    delete figure_;

    well_ = new Well();
    figure_ = new Figure();
}

void Game::keyEvent(Direction d)
{
    Figure *fg_ = new Figure(*figure_);
    switch(d)
    {
        case Up:
            fg_->rotation(Figure::Left);
            break;
        case Down:
            fg_->move(0, 1);
            break;
        case Left:
            fg_->move(-1, 0);
            break;
        case Right:
            fg_->move(1, 0);
    }

    if(!well_->isCollision(*fg_))
    {
        Figure *a_ = fg_;
        fg_ = figure_;
        figure_ = a_;
    }

    delete fg_;
}
