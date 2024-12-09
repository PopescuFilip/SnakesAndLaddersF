#ifndef CHANGELOBBYSETTINGSCOMMAND_H
#define CHANGELOBBYSETTINGSCOMMAND_H

#include "HttpCommand.h"
#include "GameManagement/Objects/MapTypeEnum.h"

class ChangeLobbySettingsCommand : public HttpCommand
{
public:
	ChangeLobbySettingsCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponsePtr execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	int m_lobbyId;
	int m_maxPlayers;
	std::string m_playerUsername;
	MapType m_mapType;
};

#endif // CREATELOBBYCOMMAND_H