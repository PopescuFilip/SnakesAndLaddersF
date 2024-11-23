#ifndef ROLLDICEREQUEST_H
#define ROLLDICEREQUEST_H
#include <string>


class RollDiceRequest {
public:
    RollDiceRequest(int gameId, const std::string& strPlayerName);

    int getGameId() const;
    const std::string& getPlayerName() const;
private:
    int m_GameId;
    std::string m_strPlayerName;
};



#endif //ROLLDICEREQUEST_H
