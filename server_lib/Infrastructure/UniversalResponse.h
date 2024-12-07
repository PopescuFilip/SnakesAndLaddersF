#ifndef UNIVERSALRESPONSE_H
#define UNIVERSALRESPONSE_H

#include <optional>
#include "BaseResponse.h"

class UniversalResponse : public BaseResponse
{
public:
	UniversalResponse(int lobbyId);

	virtual crow::json::wvalue convertToJson() const override;
private:
	std::optional<int> m_lobbyId;
};

#endif // UNIVERSALRESPONSE_H
