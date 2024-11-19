#ifndef CREATEGAMEVIEW_H
#define CREATEGAMEVIEW_H

#include <QMainWindow>

namespace Ui {
class CreateGameView;
}

class CreateGameView : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateGameView(QWidget *parent = nullptr);
    ~CreateGameView();

private:
    Ui::CreateGameView *ui;
};

#endif // CREATEGAMEVIEW_H
