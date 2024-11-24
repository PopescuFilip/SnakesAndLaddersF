#include "homeview.h"

#include <iostream>

#include "ui_homeview.h"
#include "../../utils/Logger.h"
#include "../../widgets/InfoDialog/infodialog.h"

HomeView::HomeView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeView)
{
    ui->setupUi(this);
}

HomeView::~HomeView()
{
    delete ui;
}

void HomeView::setCurrentUser() {
    std::string username = ui->lineEdit_username->text().toUtf8().constData();
    validateUsername(username);
    UserState::getInstance().setUsername(username);
}

void HomeView::validateUsername(const std::string &username) {
    if (username.empty()) {
        throw std::invalid_argument("Username cannot be empty.");
    }
    if (username.find(' ') != std::string::npos) {
        throw std::invalid_argument("Username cannot contain spaces.");
    }
}

void HomeView::on_pushButton_createGame_clicked() {
    try {
        setCurrentUser();
        emit windowPositionChanged(this->pos());
        emit goToCreateGameView();
        this->hide();
    }
    catch(const std::exception& e) {
        Logger::logError(e.what());
        InfoDialog infoDialog(e.what(), DialogType::Information);
        infoDialog.exec();
    }
}

void HomeView::on_pushButton_joinGame_clicked() {
    try {
        setCurrentUser();
        emit windowPositionChanged(this->pos());
        emit goToJoinGameView();
        this->hide();
    }
    catch(const std::exception& e) {
        Logger::logError(e.what());
        InfoDialog infoDialog(e.what(), DialogType::Information);
        infoDialog.exec();
    }
}
