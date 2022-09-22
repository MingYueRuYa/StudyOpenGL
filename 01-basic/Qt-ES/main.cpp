#include "QtES.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtES w;
    w.show();
    return a.exec();
}
