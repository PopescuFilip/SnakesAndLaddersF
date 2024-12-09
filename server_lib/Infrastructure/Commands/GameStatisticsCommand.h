#ifndef GAMESTATISTICSCOMMAND_H
#define GAMESTATISTICSCOMMAND_H

#include "HttpCommand.h"

class GameStatisticsCommand : public HttpCommand
{
public:
	GameStatisticsCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_gameId;
};

#endif