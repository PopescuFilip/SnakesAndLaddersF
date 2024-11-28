
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>



#include "GameManagementTests/GameManagementTests.h"

#include "InfrastructureTests/InfrastructureTests.h"



int main(int argc, char** argv)
    {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

