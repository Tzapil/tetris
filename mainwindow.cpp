#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(300, 400);
    timer.setInterval(1000);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer.start();
}

MainWindow::~MainWindow()
{
    timer.stop();
}

void MainWindow::timeout()
{
    game_.move();
    update();
}

void MainWindow::keyPressEvent ( QKeyEvent * event )
{
    switch(event->key())
    {
    case Qt::Key_Down:
        game_.keyEvent(Game::Down);
        break;
    case Qt::Key_Up:
        game_.keyEvent(Game::Up);
        break;
    case Qt::Key_Left:
        game_.keyEvent(Game::Left);
        break;
    case Qt::Key_Right:
        game_.keyEvent(Game::Right);
    }
    update();
}

void MainWindow::paintEvent ( QPaintEvent * event )
{
    const uint width_       = this->width() - 100,
               height_      = this->height(),
               fld_width_   = 10,
               fld_height_  = 20,
               rect_width_  = width_/fld_width_,
               rect_height_ = height_/fld_height_;

    QPainter pp;
    pp.begin(this);
        pp.setPen(QColor(0, 0, 0));
        pp.drawRect(0, 0, width_, height_);
        pp.drawText(width_+20, 20, QString("score:") + QString::number(game_.score()*100));
    pp.end();
    QMyPainter p(*this, 0, 0, rect_width_, rect_height_);
    game_.draw(p);
}
