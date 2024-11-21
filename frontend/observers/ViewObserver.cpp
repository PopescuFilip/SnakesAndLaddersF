//
// Created by Alexandru Pestritu on 21.11.2024.
//
#include "ViewObserver.h"

#include <iostream>

ViewObserver::ViewObserver(QWidget* parent)
    : parentWidget(parent) {}

void ViewObserver::update(const std::string& message) {
    if (parentWidget) {
        if (message.find("SUCCESS") != std::string::npos) {
            QMessageBox::information(parentWidget, "Success", QString::fromStdString(message));
        } else if (message.find("ERROR") != std::string::npos) {
            QMessageBox::warning(parentWidget, "Error", QString::fromStdString(message));
        } else {
            QMessageBox::information(parentWidget, "Info", QString::fromStdString(message));
        }
    }
}

