#ifndef STATUSLOBBYCOMMAND_H
#define STATUSLOBBYCOMMAND_H

#include "HttpCommand.h"

class StatusLobbyCommand : public HttpCommand
{
public:
	StatusLobbyCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_lobbyId;
};

#endif