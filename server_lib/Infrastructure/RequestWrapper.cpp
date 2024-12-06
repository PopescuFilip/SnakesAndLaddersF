#include "RequestWrapper.h"

RequestWrapper::RequestWrapper(const crow::json::rvalue& request) : m_request{ request }
{}
