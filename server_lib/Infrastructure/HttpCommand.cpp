#include "HttpCommand.h"

HttpCommand::HttpCommand(const crow::json::rvalue& request) : m_request{ request }
{}
