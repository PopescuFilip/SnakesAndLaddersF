#ifndef HTTPCOMMAND_H
#define HTTPCOMMAND_H

#include <crow/json.h>
#include <memory>
#include "Infrastructure/Request.h"
#include "Infrastructure/BaseResponse.h"

using BaseResponsePtr = std::unique_ptr<BaseResponse>;

class HttpCommand
{
public:
	HttpCommand(const crow::json::rvalue& request);

	virtual BaseResponsePtr executeWithCheck();

	virtual ~HttpCommand() = default;
protected:
	virtual BaseResponse checkCanExecute() const { return BaseResponse(true); };
	virtual BaseResponsePtr execute() = 0;

protected:
	Request m_request;
};

#endif // HTTPCOMMAND_H

