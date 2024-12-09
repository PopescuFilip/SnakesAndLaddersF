#ifndef ROLLDICECOMMAND_H
#define ROLLDICECOMMAND_H

#include "HttpCommand.h"

class RollDiceCommand : public HttpCommand
{
public:
	RollDiceCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_gameId;
	std::string m_username;
};

#endif