#ifndef PLAYERINFOWIDGET_H
#define PLAYERINFOWIDGET_H

#include <QWidget>

namespace Ui {
class PlayerInfoWidget;
}

class PlayerInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerInfoWidget(QWidget *parent = nullptr);
    ~PlayerInfoWidget();

private:
    Ui::PlayerInfoWidget *ui;
};

#endif // PLAYERINFOWIDGET_H
