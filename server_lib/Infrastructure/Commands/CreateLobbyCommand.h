#ifndef CREATELOBBYCOMMAND_H
#define CREATELOBBYCOMMAND_H

#include "HttpCommand.h"
#include "GameManagement/Objects/MapTypeEnum.h"

class CreateLobbyCommand : public HttpCommand
{
public:
	CreateLobbyCommand(const crow::json::rvalue& request);

protected:
	virtual BaseResponse execute() override;
	virtual BaseResponse checkCanExecute() const override;

private:
	std::string m_strAdminUsername;
	int m_iMaxPlayers;
	MapType m_mapType;
};

#endif // CREATELOBBYCOMMAND_H