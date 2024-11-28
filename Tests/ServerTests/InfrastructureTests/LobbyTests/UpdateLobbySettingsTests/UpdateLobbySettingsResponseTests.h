//
// Created by Andrei on 11/28/2024.
//

#ifndef UPDATELOBBYSETTINGSRESPONSETESTS_H
#define UPDATELOBBYSETTINGSRESPONSETESTS_H
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsResponse.h"

class MockUpdateSettingsResponse : public UpdateSettingsResponse {
    public:
    MockUpdateSettingsResponse(bool valid): UpdateSettingsResponse(valid) {}
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));
};

TEST(UpdateSettingsResponseTest, convertToJson) {
    MockUpdateSettingsResponse mockResponse{true};

    EXPECT_CALL(mockResponse, convertToJson()).WillOnce(::testing::Return(true));
    crow::json::wvalue response = mockResponse.convertToJson();

    EXPECT_FALSE(response.dump().empty());
}

#endif //UPDATELOBBYSETTINGSRESPONSETESTS_H
