#include "mainwindow.h"
#include <QApplication>

int aa[10];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    aa[1000] = 50;

    return a.exec();
}
