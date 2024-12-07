#include "HttpCommand.h"

HttpCommand::HttpCommand(const crow::json::rvalue& request) : m_request{ request }
{}

BaseResponse HttpCommand::executeWithCheck()
{
    if (BaseResponse response(checkCanExecute()); !response)
        return response;

    return execute();
}
