#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(const QString& message, DialogType type, QWidget *parent)
    : QDialog(parent, Qt::FramelessWindowHint)
    , ui(new Ui::InfoDialog)
{
    ui->setupUi(this);

    ui->label_message->setText(message);

    if (type == DialogType::Information) {
        ui->pushButton_yes->hide();
        ui->pushButton_no->hide();
        ui->pushButton_ok->show();
    } else if (type == DialogType::Confirmation) {
        ui->pushButton_ok->hide();
        ui->pushButton_yes->show();
        ui->pushButton_no->show();
    }
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_pushButton_closeButton_clicked() {
    this->reject();
}

void InfoDialog::on_pushButton_ok_clicked() {
    this->accept();
}

void InfoDialog::on_pushButton_yes_clicked() {
    this->accept();
}

void InfoDialog::on_pushButton_no_clicked() {
    this->reject();
}
