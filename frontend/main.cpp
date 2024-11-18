#include <QApplication>
#include "views/homeview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeView w;
    w.show();
    return a.exec();
}
