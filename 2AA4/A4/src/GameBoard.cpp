#include <iostream>
#include <stdexcept>

#include "GameBoard.h"
using namespace std;

GameBoard::GameBoard(){
    this->U = init_uni();
}

GameBoard::GameBoard(Universe U){
    this->U = U;
}

Universe GameBoard::init_uni(){
    Universe temp;
    for (nat n = 0; n < this->HEIGHT; n++){
        vector<Cell> row;
        for (nat m = 0; m < this->WIDTH; m++){
            Cell cell = { Dead };
            row.push_back(cell);
        }
        temp.push_back(row);
    }
    return temp;
}

bool GameBoard::hasNeighbours(nat n, nat m){
    if (n >= this->HEIGHT) throw invalid_argument("The n parameter for the row position exceeds the Max Dimensions");
    if (m >= this->WIDTH) throw invalid_argument("The m parameter for the column position exceeds the Max Dimensions");

    if (n > 0){
        if (m > 0)
            if (this->U[n - 1][m - 1].s == Alive) return true;
        if (this->U[n - 1][m].s == Alive) return true;
        if (m < this->WIDTH - 1)
            if (this->U[n - 1][m + 1].s == Alive) return true;
    }
    if (m < this->WIDTH - 1)
        if (this->U[n][m + 1].s == Alive) return true;
    if (m > 0)
        if (this->U[n][m - 1].s == Alive) return true;
    if (n < this->HEIGHT - 1){
        if(m > 0)
            if (this->U[n + 1][m - 1].s == Alive) return true;
        if (this->U[n + 1][m].s == Alive) return true;
        if (m < this->WIDTH - 1)
            if (this->U[n + 1][m + 1].s == Alive) return true;
    }
    return false;
}

nat GameBoard::numOfNeighbours(nat n, nat m){
    if (n >= this->HEIGHT) throw invalid_argument("The n parameter for the row position exceeds the Max Dimensions");
    if (m >= this->WIDTH) throw invalid_argument("The m parameter for the column position exceeds the Max Dimensions");

    nat neighbours = 0;
    if (n > 0){
        if (m > 0)
            if (this->U[n - 1][m - 1].s == Alive) neighbours++;
        if (this->U[n - 1][m].s == Alive) neighbours++;
        if (m < this->WIDTH - 1)
            if (this->U[n - 1][m + 1].s == Alive) neighbours++;
    }
    if (m < this->WIDTH - 1)
        if (this->U[n][m + 1].s == Alive) neighbours++;
    if (m > 0)
        if (this->U[n][m - 1].s == Alive) neighbours++;
    if (n < this->HEIGHT - 1){
        if (m > 0)
            if (this->U[n + 1][m - 1].s == Alive) neighbours++;
        if (this->U[n + 1][m].s == Alive) neighbours++;
        if (m < this->WIDTH - 1)
            if (this->U[n + 1][m + 1].s == Alive) neighbours++;
    }
    return neighbours;
}

Cell GameBoard::getCell(nat n, nat m){
    if (n >= this->HEIGHT) throw invalid_argument("The n parameter for the row position exceeds the Max Dimensions");
    if (m >= this->WIDTH) throw invalid_argument("The m parameter for the column position exceeds the Max Dimensions");

    return this->U[n][m];
}

bool GameBoard::gameOver(){
    for (nat n = 0; n < this->HEIGHT; n++){
        for (nat m = 0; m < this->WIDTH; m++){
            if (this->hasNeighbours(n, m)) return false;
        }
    }
    return true;
}

Universe GameBoard::getUniverse(){
    return this->U;
}

void GameBoard::nextState(){
    Universe nextState = this->init_uni();

    for (nat n = 0; n < this->HEIGHT; n++){
        for (nat m = 0; m < this->WIDTH; m++){
            nat neighbours = numOfNeighbours(n,m);
            if (this->U[n][m].s == Alive){
                if (!this->hasNeighbours(n, m)) 
                    nextState[n][m] = Cell {Dead};
                if (neighbours >= 2 and neighbours <= 3) 
                    nextState[n][m] = Cell {Alive};
                if (neighbours > 3) 
                    nextState[n][m] = Cell {Dead};
            }
            if (this->U[n][m].s == Dead){
                if (neighbours == 3) nextState[n][m] = Cell {Alive};
            }
        }
    }
    this->U = nextState;
}