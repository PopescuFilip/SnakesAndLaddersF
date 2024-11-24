#include <QApplication>
#include "resources/FontManager.h"
#include "utils/ViewManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/icon.ico"));
    registerFonts();
    ViewManager viewManager;
    viewManager.showHomeView();
    return a.exec();
}
