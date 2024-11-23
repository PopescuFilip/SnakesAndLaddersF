#include "playerinfowidget.h"
#include "ui_playerinfowidget.h"

PlayerInfoWidget::PlayerInfoWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayerInfoWidget)
{
    ui->setupUi(this);
}

PlayerInfoWidget::~PlayerInfoWidget()
{
    delete ui;
}
