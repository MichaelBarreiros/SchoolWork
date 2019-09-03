/**
 * \file testGameBoard.cpp
 * \author Michael Barreiros barreirm
 * \brief Implementation of GameBoard Tests
 */

#include <vector>
#include "BoardTypes.h"
#include "GameBoard.h"
#include "catch.h"
using namespace std;

TEST_CASE( "Tests for GameBoard.cpp", "[GameBoard]" ){

    SECTION( "Test GameBoard default constructor" ){
        GameBoard board = GameBoard();
        REQUIRE(board.getUniverse().size() == MAX_DIMENSIONS);
        for (nat n = 0; n < MAX_DIMENSIONS; n++){
            REQUIRE((board.getUniverse())[n].size() == MAX_DIMENSIONS);
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                REQUIRE (board.getCell(nat(n),m).s == Dead);
            }
        }
    }

    SECTION( "Test GameBoard constructor" ){
        //build universe
        Universe universe;
        for (nat n  = 0; n < MAX_DIMENSIONS; n++){
            vector<Cell> row;
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                row.push_back(Cell{Alive});
            }
            universe.push_back(row);
        }

        GameBoard board = GameBoard(universe);

        REQUIRE(board.getUniverse().size() == MAX_DIMENSIONS);
        for (int n = 0; n < int(MAX_DIMENSIONS); n++){
            REQUIRE((board.getUniverse())[n].size() == MAX_DIMENSIONS);
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                REQUIRE (board.getCell(nat(n),m).s == Alive);
            }
        }
    }

    SECTION( "Test hasNeighours function operates properly" ){
        //build universe
        Universe universe;
        for (nat n  = 0; n < MAX_DIMENSIONS; n++){
            vector<Cell> row;
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                row.push_back(Cell{Alive});
            }
            universe.push_back(row);
        }

        GameBoard dead = GameBoard();
        GameBoard alive = GameBoard(universe);

        for (nat n = 0; n < MAX_DIMENSIONS; n++){
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                REQUIRE(!dead.hasNeighbours(n,m));
                REQUIRE(alive.hasNeighbours(n,m));
            }
        }
    }

    SECTION( "Test hasNeighbours function throws invalid argument" ){
        GameBoard dead = GameBoard();
        REQUIRE_THROWS_AS(dead.hasNeighbours(MAX_DIMENSIONS + 1, 0), invalid_argument);
        REQUIRE_THROWS_AS(dead.hasNeighbours(0, MAX_DIMENSIONS + 1), invalid_argument);
        REQUIRE_THROWS_AS(dead.hasNeighbours(-5, 0), invalid_argument);
        REQUIRE_THROWS_AS(dead.hasNeighbours(0, -5), invalid_argument);
    }

    SECTION( "Test numOfNeighbours function operates properly" ){
        //build universe
        Universe universe;
        for (nat n  = 0; n < MAX_DIMENSIONS; n++){
            vector<Cell> row;
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                row.push_back(Cell{Alive});
            }
            universe.push_back(row);
        }

        GameBoard dead = GameBoard();
        GameBoard alive = GameBoard(universe);

        for (nat n = 0; n < MAX_DIMENSIONS; n++){
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                REQUIRE(dead.numOfNeighbours(n,m) == 0);
                //Inside bondary-1 have 8 neighbours 
                if (n > 0 and m > 0 and n < MAX_DIMENSIONS - 1 and m < MAX_DIMENSIONS - 1)
                    REQUIRE(alive.numOfNeighbours(n,m) == 8);
                //Corners only have 3 neighbours
                if (n == 0 and m == 0 or n == MAX_DIMENSIONS - 1 and m == MAX_DIMENSIONS - 1 
                    or n == 0 and m == MAX_DIMENSIONS - 1 or n == MAX_DIMENSIONS - 1 and m == 0)
                    REQUIRE(alive.numOfNeighbours(n,m) == 3);
                //Side Cells have 5 neighbours
                if (n == 0 and m > 0 and m < MAX_DIMENSIONS - 1
                    or n == MAX_DIMENSIONS - 1 and m > 0 and m < MAX_DIMENSIONS - 1
                    or m == 0 and n > 0 and n < MAX_DIMENSIONS - 1
                    or m == MAX_DIMENSIONS - 1 and n > 0 and n < MAX_DIMENSIONS - 1)
                    REQUIRE(alive.numOfNeighbours(n,m) == 5);
            }
        }
    }

    SECTION( "Test numOfNeighbours function throws invalid argument" ){
        GameBoard dead = GameBoard();
        REQUIRE_THROWS_AS(dead.numOfNeighbours(MAX_DIMENSIONS + 1, 0), invalid_argument);
        REQUIRE_THROWS_AS(dead.numOfNeighbours(0, MAX_DIMENSIONS + 1), invalid_argument);
        REQUIRE_THROWS_AS(dead.numOfNeighbours(-5, 0), invalid_argument);
        REQUIRE_THROWS_AS(dead.numOfNeighbours(0, -5), invalid_argument);
    }

    SECTION( "Test getCell function operates properly" ){
        //build universe
        Universe universe;
        for (nat n  = 0; n < MAX_DIMENSIONS; n++){
            vector<Cell> row;
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                row.push_back(Cell{Alive});
            }
            universe.push_back(row);
        }

        GameBoard dead = GameBoard();
        GameBoard alive = GameBoard(universe);

        REQUIRE(dead.getCell(0,0).s == Dead);
        REQUIRE(alive.getCell(0,0).s == Alive);
    }

    SECTION( "Test getCell function throws invalid argument" ){
        GameBoard dead = GameBoard();
        REQUIRE_THROWS_AS(dead.getCell(MAX_DIMENSIONS + 1, 0), invalid_argument);
        REQUIRE_THROWS_AS(dead.getCell(0, MAX_DIMENSIONS + 1), invalid_argument);
        REQUIRE_THROWS_AS(dead.getCell(-5, 0), invalid_argument);
        REQUIRE_THROWS_AS(dead.getCell(0, -5), invalid_argument);
    }

    SECTION( "Test gameOver function operates properly" ){
        //build universe
        Universe universe;
        for (nat n  = 0; n < MAX_DIMENSIONS; n++){
            vector<Cell> row;
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                row.push_back(Cell{Alive});
            }
            universe.push_back(row);
        }

        GameBoard dead = GameBoard();
        GameBoard alive = GameBoard(universe);

        REQUIRE(dead.gameOver());
        REQUIRE(!alive.gameOver());
    }


    SECTION( "Test getUniverse function operates properly" ){
        //build universe
        Universe universe;
        for (nat n  = 0; n < MAX_DIMENSIONS; n++){
            vector<Cell> row;
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                row.push_back(Cell{Alive});
            }
            universe.push_back(row);
        }

        GameBoard alive = GameBoard(universe);
        Universe test = alive.getUniverse();

        for (nat n = 0; n < MAX_DIMENSIONS; n++){
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                REQUIRE(universe[n][m].s == test[n][m].s);
            }
        }
    }

    SECTION( "Test nextState function operates properly" ){
        //build universe
        Universe universe;
        for (nat n  = 0; n < MAX_DIMENSIONS; n++){
            vector<Cell> row;
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                if (n >= 0 and n < 2 and m >= 0 and m < 2) 
                    row.push_back(Cell{Alive});
                else
                    row.push_back(Cell{Dead});
            }
            universe.push_back(row);
        }

        GameBoard stable = GameBoard(universe);
        stable.nextState();
        Universe test = stable.getUniverse();
        
        for (nat n = 0; n < MAX_DIMENSIONS; n++){
            for (nat m = 0; m < MAX_DIMENSIONS; m++){
                REQUIRE(universe[n][m].s == test[n][m].s);
            }
        }
    }
} 