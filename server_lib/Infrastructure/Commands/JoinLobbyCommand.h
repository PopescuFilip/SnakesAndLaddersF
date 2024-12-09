#ifndef JOINLOBBYCOMMAND_H
#define JOINLOBBYCOMMAND_H

#include "HttpCommand.h"

class JoinLobbyCommand : public HttpCommand
{
public:
	JoinLobbyCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_lobbyId;
	std::string m_username;
};

#endif