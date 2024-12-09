#ifndef LEAVELOBBYCOMMAND_H
#define LEAVELOBBYCOMMAND_H

#include "HttpCommand.h"

class LeaveLobbyCommand : public HttpCommand
{
public:
	LeaveLobbyCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_lobbyId;
	std::string m_username;
};

#endif
