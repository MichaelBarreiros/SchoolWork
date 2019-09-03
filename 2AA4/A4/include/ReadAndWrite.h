/**
 * \file ReadAndWrite.h
 * \author Michael Barreiros barreirm
 * \brief Defining read and write functions responsible for reading from a file and outputting to a file
 * both specified by the user
 */
#ifndef READ_AND_WRITE_H
#define READ_AND_WRITE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include "BoardTypes.h"

/*
 * \breif Reads from an input file and returns a 2 dimensional vector to be used with the game
 * \details Reads a file name specified by the user
 * \throws runtime_error if file not found 
 * \throws invalid_argument if the number of cells read does not equal a MAX_DIMENSIONS x MAX_DIMENSIONS
 * 2d vector
 */
std::vector<std::vector<Cell>> read(std::string file);

/**
 * \brief Outputs a 2d vector to an output file
 * \details The name of the output file is specified by the user
 */
void write(std::vector<std::vector<Cell>> universe, std::string file);

#endif