#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <crow/json.h>

class BaseObject {
public:
    virtual ~BaseObject() = default;
    virtual crow::json::wvalue convertToJson() const = 0;
};

#endif //BASEOBJECT_H
