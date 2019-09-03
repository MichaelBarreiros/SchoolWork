/**
 * \file BoardTypes.h
 * \author Michael Barreiros barreirm
 * \brief Defining the different types and constants that will be used to build cells and 
 * the gameboard
 */
#ifndef A4_BOARD_TYPES_H
#define A4_BOARD_TYPES_H

#define MAX_DIMENSIONS 20

/**
 * \brief Defining nat (natural number) for understandability in code
 */
typedef unsigned short int nat;

/**
 * \brief Enumerate Type defining the 2 different status' of a cell, either dead or alive
 */
enum Status{ Alive, Dead };

/**
 * \brief A struct defining what a cell is, it has a status of being alive or dead
 */
struct Cell{
    Status s;
};

#endif