/**
 * \file testReadAndWrite.cpp
 * \author Michael Barreiros barreirm
 * \brief Implementation of ReadAndWrite Tests
 */

#include <vector>
#include "BoardTypes.h"
#include "GameBoard.h"
#include "catch.h"
#include "ReadAndWrite.h"
using namespace std;

TEST_CASE( "Test for ReadAndWrite.cpp", "[ReadAndWrite]" ){

    SECTION( "Test read operates correctly" ){
        /* Note that the input.txt file currently contains this
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ # # # # # # # # # # _ _ _ _ _ 
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        */
        Universe universe = read("input.txt");

        for (nat n = 0; n < MAX_DIMENSIONS; n++){
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                if (n == 8 and m > 4 and m < 15) 
                    REQUIRE(universe[n][m].s == Alive);
                else
                    REQUIRE(universe[n][m].s == Dead);
            }
        }
    }

    SECTION( "Test read throws runtime_error" ){
        REQUIRE_THROWS_AS(read("notInput.txt"), runtime_error);    
    }

    SECTION( "Test read throws invalid argument" ){
        REQUIRE_THROWS_AS(read("badInput.txt"), invalid_argument);
    }

    SECTION( "Test write operates correctly" ){
        Universe universe = read("input.txt");
        write(universe, "test.txt");

        Universe test = read("test.txt");

        for (nat n = 0; n < MAX_DIMENSIONS; n++){
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                    REQUIRE(universe[n][m].s == test[n][m].s);
            }
        }
    }
}