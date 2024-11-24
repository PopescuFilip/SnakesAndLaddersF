#ifndef BASECONTEXT_H
#define BASECONTEXT_H
#include "ValidationResponse.h"

template <typename RequestType, typename ResponseType>
class BaseContext {
public:
    virtual ~BaseContext() = default;
    virtual ResponseType HandleRequest(const RequestType& request) = 0;

protected:
    virtual ResponseType ApplyChanges(const RequestType& request) = 0;
    virtual ValidationResponse ValidateRequest(const RequestType& request) = 0;
};

#endif //BASECONTEXT_H
