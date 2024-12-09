#ifndef LEAVEGAMECOMMAND_H
#define LEAVEGAMECOMMAND_H

#include "HttpCommand.h"

class LeaveGameCommand : public HttpCommand
{
public:
	LeaveGameCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_gameId;
	std::string m_username;
};

#endif
