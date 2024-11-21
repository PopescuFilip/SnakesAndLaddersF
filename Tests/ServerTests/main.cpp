#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "GameManagementTests/LobbyManagerTests/MockLobbyManager.h"
#include "GameManagementTests/GameManagerTests/MockGameManager.h"


    int main(int argc, char** argv)
    {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

