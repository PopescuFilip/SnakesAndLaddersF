#include <QApplication>
#include "utils/ViewManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewManager viewManager;
    viewManager.showHomeView();
    return a.exec();
}
