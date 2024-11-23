//
// Created by Alexandru Pestritu on 21.11.2024.
//

#ifndef VIEWOBSERVER_H
#define VIEWOBSERVER_H
#include <QWidget>
#include <string>
#include "../widgets/InfoDialog/infodialog.h"

#include "Observer.h"


class ViewObserver : public Observer {
public:
    explicit ViewObserver(QWidget* parent = nullptr);
    ~ViewObserver() override = default;

    void update(const std::string& message) override;

protected:
    QWidget* parentWidget;
};

#endif //VIEWOBSERVER_H
