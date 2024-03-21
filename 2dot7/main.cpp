#include "win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    win w;
    //komm
    w.show();
    return a.exec();
}
