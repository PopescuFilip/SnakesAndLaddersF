#ifndef STARTGAMECOMMAND_H
#define STARTGAMECOMMAND_H

#include "HttpCommand.h"

class StartGameCommand : public HttpCommand
{
public:
	StartGameCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_lobbyId;
	std::string m_username;
};

#endif