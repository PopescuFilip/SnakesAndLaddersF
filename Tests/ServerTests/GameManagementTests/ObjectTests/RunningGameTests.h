//
// Created by Andrei on 11/21/2024.
//

#ifndef RUNNINGGAMETESTS_H
#define RUNNINGGAMETESTS_H
#include <gtest/gtest.h>

TEST(RunningGameTest,GetGameId_Validation) {
    Lobby lobby={1,"gigel",MapType::MAP_01,4};
    RunningGame rng = RunningGame(lobby);
    ASSERT_TRUE(rng.getGameId()==1);
}

#endif //RUNNINGGAMETESTS_H
