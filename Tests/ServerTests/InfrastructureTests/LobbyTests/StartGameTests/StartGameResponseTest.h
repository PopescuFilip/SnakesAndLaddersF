//
// Created by Andrei on 11/28/2024.
//

#ifndef STARTGAMERESPONSETEST_H
#define STARTGAMERESPONSETEST_H
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Infrastructure/Lobby/StartGame/StartGameResponse.h"

class MockStartGameResponse : public StartGameResponse {
    public:
    MockStartGameResponse(bool valid): StartGameResponse(valid) {}
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));
};

TEST(StartGameResponseTest,ConvertToJson) {

    MockStartGameResponse mockResponse{true};

    EXPECT_CALL(mockResponse, convertToJson()).Times(1);

    crow::json::wvalue response = mockResponse.convertToJson();

    EXPECT_FALSE(response.dump().empty());
}

#endif //STARTGAMERESPONSETEST_H
