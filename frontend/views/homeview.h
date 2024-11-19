#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QMainWindow>

namespace Ui {
class HomeView;
}

class HomeView : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeView(QWidget *parent = nullptr);
    ~HomeView();

private:
    Ui::HomeView *ui;
};

#endif // HOMEVIEW_H
