
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "GameManagementTests/LobbyManagerTests/MockLobbyManager.h"

#include "GameManagementTests/GameManagerTests/MockGameManager.h"
#include "GameManagementTests/ObjectTests/LobbyTests.h"
#include "GameManagementTests/ObjectTests/PlayerTests.h"
#include "GameManagementTests/ObjectTests/RunningGameTests.h"
#include "InfrastructureTests/LobbyTests/CreatLobbyTests/CreateLobbyRequestTest.h"
#include "InfrastructureTests/LobbyTests/CreatLobbyTests/CreateLobbyResponseTests.h"
#include "InfrastructureTests/LobbyTests/CreatLobbyTests/CreateLobbyContextTest.h"
#include "InfrastructureTests/LobbyTests/JoinLobbyTests/JoinLobbyContextTest.h"
#include "InfrastructureTests/LobbyTests/JoinLobbyTests/JoinLobbyRequestTest.h"
#include "InfrastructureTests/LobbyTests/JoinLobbyTests/JoinLobbyResponseTest.h"
#include "InfrastructureTests/LobbyTests/LeaveLobbyTests/LeaveLobbyContextTest.h"
#include "InfrastructureTests/LobbyTests/LeaveLobbyTests/LeaveLobbyRequestTest.h"
#include "InfrastructureTests/LobbyTests/LeaveLobbyTests/LeaveLobbyResponseTest.h"
#include "InfrastructureTests/LobbyTests/LobbyStatusTests/LobbyStatusContextTest.h"
#include "InfrastructureTests/LobbyTests/LobbyStatusTests/LobbyStatusRequestTest.h"
#include "InfrastructureTests/LobbyTests/LobbyStatusTests/LobbyStatusResponseTest.h"
    int main(int argc, char** argv)
    {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

