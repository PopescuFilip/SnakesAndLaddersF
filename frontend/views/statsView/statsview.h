#ifndef STATSVIEW_H
#define STATSVIEW_H

#include <QMainWindow>

namespace Ui {
class StatsView;
}

class StatsView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StatsView(QWidget *parent = nullptr);
    ~StatsView();

private:
    Ui::StatsView *ui;
};

#endif // STATSVIEW_H
