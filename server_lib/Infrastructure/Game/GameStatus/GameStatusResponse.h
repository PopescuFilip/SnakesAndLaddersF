#ifndef GAMESTATUSRESPONSE_H
#define GAMESTATUSRESPONSE_H

#include <optional>
#include "GameManagement/Objects/RunningGame.h"
#include "Infrastructure/BaseResponse.h"


class GameStatusResponse : public BaseResponse {
public:
    GameStatusResponse(const RunningGame& game);
    GameStatusResponse(const std::string& message);

    RunningGame getGame() const;

    crow::json::wvalue convertToJson() const override;
private:
    std::optional<RunningGame> m_Game;
};



#endif //GAMESTATUSRESPONSE_H
