/**
 * \file GameBoard.h
 * \author Michael Barreiros barreirm
 * \brief Abstract Data Type of a Gameboard for Conway's game of life
 */ 

#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include "BoardTypes.h"

/**
 * \brief A typedef for Universe to help with code readability
 */
typedef std::vector<std::vector<Cell>> Universe;

/**
 * \brief Class for representing the gameboard of a game of Conway's game of life
 * \details Representing the state of the game as well as functions for playing the game and 
 * determining the next state of the game
 */
class GameBoard{
    private:
        Universe U;

        const nat WIDTH = MAX_DIMENSIONS;
        const nat HEIGHT = MAX_DIMENSIONS;

        Universe init_uni();

    public:
        /**
         * \brief A default Gameboard constructor
         * \details Creates a new instance of a gameboard with all cells dead
         */
        GameBoard();

        /**
         * \brief Constructs a new game of Life gameboard from a given 2d vector of cells
         * \details Create a new instance of a gameboard from a 2d vector of cells, the game
         * of life can now be played
         * \param U A universe (2d vector of cells) to be used when setting up the gameboard
         */
        GameBoard(Universe U);

        /**
         * \brief Checks if a cell has any neighbours
         * \details Checks surrounding 8 cells (left, right, up, down, 4 corners) to see if there
         * are any live cells around
         * \returns Whether there are any live cells around this cell
         * \throws invalid_argument if n or m is outside the bounds of the gameboard
         */
        bool hasNeighbours(nat n, nat m);

        /**
         * \brief Checks and returns how many neighbours a given cell has
         * \details Checks all 8 surrounding cells to see if they are alive
         * \return A natural number for the number of neighbouring cells that are alive
         * this value ranges from 0 - 8\
         * \throws invalid_argument if n or m is outside the bounds of the gameboard
         */
        nat numOfNeighbours(nat n, nat m);

        /**
         * \brief Get the Cell associated with a (n,m) coordinate (row n, column m)
         * \return A Cell object associated with a (n,m) coordinate on the Gameboard
         * \throws invalid_argument if n or m is outside the bounds of the gameboard
         */
        Cell getCell(nat n, nat m);

        /**
         * \brief Determines whether or not the game is over
         * \details Determines this by checking if all cells on the board are dead
         * \return Whether or not the game is in a dead state
         */
        bool gameOver();

        /**
         * \brief Gets the universe associated with this gameboard
         * \return A 2d vector of cells 
         */
        Universe getUniverse();

        /**
         * \brief Determines the next state of the gameboard
         * \details Does this by going through every cell and running the rules of the game to
         * determine whether or not the cell will be dead or alive in the next state of the
         * gameboard
         */
        void nextState();
};

#endif