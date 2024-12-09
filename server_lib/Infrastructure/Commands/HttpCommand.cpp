#include "HttpCommand.h"

HttpCommand::HttpCommand(const crow::json::rvalue& request) : m_request{ request }
{}

BaseResponsePtr HttpCommand::executeWithCheck()
{
    if (BaseResponse response(checkCanExecute()); !response)
        return std::make_unique<BaseResponse>(response);

    return execute();
}
