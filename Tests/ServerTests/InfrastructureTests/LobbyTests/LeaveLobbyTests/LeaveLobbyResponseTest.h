//
// Created by Andrei on 11/28/2024.
//

#ifndef LEAVELOBBYRESPONSETEST_H
#define LEAVELOBBYRESPONSETEST_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Infrastructure/Lobby/LeaveLobby/LeaveLobbyResponse.h"

class MockLeaveLobbyResponse : public LeaveLobbyResponse {
    public:
    MockLeaveLobbyResponse(bool result) : LeaveLobbyResponse(result) {}
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));;

};

TEST(LeaveLobbyResponseTest, ConvertToJson) {

    MockLeaveLobbyResponse mockResponse{true};

    EXPECT_CALL(mockResponse, convertToJson()).Times(1);

    crow::json::wvalue response = mockResponse.convertToJson();

    EXPECT_FALSE(response.dump().empty());
}

#endif //LEAVELOBBYRESPONSETEST_H
