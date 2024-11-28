#include "statsview.h"
#include "ui_statsview.h"

StatsView::StatsView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StatsView)
{
    ui->setupUi(this);
}

StatsView::~StatsView()
{
    delete ui;
}
