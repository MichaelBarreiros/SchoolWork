/**
 * \file output.h
 * \author Michael Barreiros barreirm
 * \breif Defining the a function responsible for outputting generations to the console
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "BoardTypes.h"
#include <vector>

/**
 * \breif Outputs a 2d vector to the console
 * \details Takes a 2d vector of Cells as a parameter as well as the generation number to print to the screen
 */
void print(std::vector<std::vector<Cell>> universe, nat generation);

#endif