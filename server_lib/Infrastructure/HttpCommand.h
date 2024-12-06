#ifndef HTTPCOMMAND_H
#define HTTPCOMMAND_H

#include <crow/json.h>
#include "RequestWrapper.h"
#include "BaseResponse.h"

class HttpCommand
{
public:
	HttpCommand(const crow::json::rvalue& request);
	virtual BaseResponse execute() = 0;
	
	virtual ~HttpCommand() = default;
protected:
	RequestWrapper m_request;
};

#endif // HTTPCOMMAND_H

