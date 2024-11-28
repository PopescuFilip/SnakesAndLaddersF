//
// Created by Andrei on 11/28/2024.
//

#ifndef JOINLOBBYRESPONSETEST_H
#define JOINLOBBYRESPONSETEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Infrastructure/Lobby/JoinLobby/JoinLobbyResponse.h"


class MockJoinLobbyResponseTest : public JoinLobbyResponse {

    public:
    MockJoinLobbyResponseTest(const std::string& message): JoinLobbyResponse(message) {}
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));;


};

TEST(JoinLobbyResponse, convertToJson) {

    MockJoinLobbyResponseTest mockResponse{"testing"};

    EXPECT_CALL(mockResponse, convertToJson()).Times(1);

    crow::json::wvalue response = mockResponse.convertToJson();

    ASSERT_FALSE(response.dump().empty());
}
#endif //JOINLOBBYRESPONSETEST_H
