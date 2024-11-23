//
// Created by Alexandru Pestritu on 21.11.2024.
//
#include "ViewObserver.h"

#include <iostream>

ViewObserver::ViewObserver(QWidget* parent)
    : parentWidget(parent) {}

void ViewObserver::update(const std::string& message) {
    if (parentWidget) {
        if (!message.empty()) {
            InfoDialog infoDialog(QString::fromStdString(message), DialogType::Information);
            infoDialog.exec();
        }
    }
}

