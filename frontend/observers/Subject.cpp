//
// Created by Alexandru Pestritu on 18.11.2024.
//
#include "Subject.h"

void Subject::addObserver(Observer* observer) {
    if (std::find(observers.begin(), observers.end(), observer) == observers.end()) {
        observers.push_back(observer);
    }
}

void Subject::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notifyObservers(const std::string& message) {
    for (Observer* observer : observers) {
        observer->update(message);
    }
}
