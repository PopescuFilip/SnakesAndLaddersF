#ifndef GAMESTATUSCOMMAND_H
#define GAMESTATUSCOMMAND_H

#include "HttpCommand.h"

class GameStatusCommand : public HttpCommand
{
public:
	GameStatusCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_gameId;
};

#endif