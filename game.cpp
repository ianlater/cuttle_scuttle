#include <QtGui/QApplication>
#include "mainwindow.h"
#include "cuttle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
Cuttle cuttle;
    w.show();

    return a.exec();
}
