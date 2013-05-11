#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(200, 400);
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
    const uint width_       = this->width(),
               height_      = this->height(),
               fld_width_   = 10,
               fld_height_  = 20,
               rect_width_  = width_/fld_width_,
               rect_height_ = height_/fld_height_;

    //функция рисования квадрата с координатами x, y
    /*std::function<void (QPainter &, int, int)> drawRect =
    [rect_width_, rect_height_](QPainter &p_, int x, int y)
    {
        p_.drawRect(x*rect_width_, y*rect_height_, rect_width_, rect_height_);
    };

    QPainter p;
    p.begin(this);
    p.setBrush(QBrush(QColor(255, 0, 0)));
        p.setPen(QColor(0, 0, 0));
        drawRect(p, 5, 10);
        drawRect(p, 4, 10);
        drawRect(p, 3, 10);
    p.end();*/

    QMyPainter p(*this, rect_width_, rect_height_);
    p.setColor(255, 0, 0);
    game_.draw(p);
}
