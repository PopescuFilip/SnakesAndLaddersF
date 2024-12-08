#ifndef HTTPCOMMAND_H
#define HTTPCOMMAND_H

#include <crow/json.h>
#include "Infrastructure/Request.h"
#include "Infrastructure/BaseResponse.h"

class HttpCommand
{
public:
	HttpCommand(const crow::json::rvalue& request);

	virtual BaseResponse executeWithCheck();

	virtual ~HttpCommand() = default;
protected:
	virtual BaseResponse checkCanExecute() const { return BaseResponse(true); };
	virtual BaseResponse execute() = 0;

protected:
	Request m_request;
};

#endif // HTTPCOMMAND_H

