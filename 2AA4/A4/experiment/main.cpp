/*
 * Use this file for experimenting with your code,
 * testing things that don't work, debugging, etc.
 *
 * You can compile and run this via 'make experiment'
 *
 * This file will not be graded
 */
#include <algorithm>
#include <iostream>
#include <vector>

#include "ReadAndWrite.h"
#include "BoardTypes.h"
#include "Output.h"
#include "GameBoard.h"

using namespace std;

int main() {
  cout << "'make experiment' will run this main" << endl;
  
  Universe universe = read("input.txt");
  GameBoard board = GameBoard(universe);

  nat generation = 0;
  do{
    if (generation == 100) break;
    write(board.getUniverse(), "output.txt");
    print(board.getUniverse(), generation);
    board.nextState();
    generation++;
  }while(!board.gameOver());
  return 0;
}
