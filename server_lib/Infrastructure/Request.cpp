#include "Request.h"

Request::Request(const crow::json::rvalue& request) : m_request{ request }
{}
