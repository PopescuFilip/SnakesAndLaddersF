//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <algorithm>

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers(const std::string& message);

private:
    std::vector<Observer*> observers;
};

#endif //SUBJECT_H
