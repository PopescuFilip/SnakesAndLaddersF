#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

enum class DialogType {
    Information,
    Confirmation
};

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(const QString& message, DialogType type, QWidget *parent = nullptr);
    ~InfoDialog();

private:
    Ui::InfoDialog *ui;

private slots:
    void on_pushButton_closeButton_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_yes_clicked();
    void on_pushButton_no_clicked();
};

#endif // INFODIALOG_H
