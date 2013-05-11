#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>

#include "game.h"
#include "qmypainter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent ( QPaintEvent * event );
    void keyPressEvent ( QKeyEvent * event );
protected slots:
    void timeout();
private:
    Game game_;
    QTimer timer;
};

#endif // MAINWINDOW_H
