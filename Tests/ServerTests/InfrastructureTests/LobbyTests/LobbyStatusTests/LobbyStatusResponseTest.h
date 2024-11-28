//
// Created by Andrei on 11/28/2024.
//

#ifndef LOBBYSTATUSRESPONSETEST_H
#define LOBBYSTATUSRESPONSETEST_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Infrastructure/Lobby/LobbyStatus/LobbyStatusResponse.h"

class MockLobbyStatusResponse : public LobbyStatusResponse {
    public:
    MockLobbyStatusResponse(const Lobby& lobby) : LobbyStatusResponse(lobby) {}
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));;


};


TEST(LobbyStatusResponseTest, convertToJson) {
    Lobby lobby = {1,"Gigel",MapType::MAP_01,4};
    MockLobbyStatusResponse mockResponse{lobby};

    EXPECT_CALL(mockResponse,convertToJson()).Times(1);

    crow::json::wvalue response = mockResponse.convertToJson();

    EXPECT_FALSE(response.dump().empty());
}

#endif //LOBBYSTATUSRESPONSETEST_H
