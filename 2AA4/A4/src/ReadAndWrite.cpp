#include <stdexcept> 

#include "ReadAndWrite.h"
using namespace std;

vector<vector<Cell>> read(string file){
    string line;
    vector<vector<Cell>> universe;
    ifstream input;
    input.open(file);
    if (input.fail()){
        throw runtime_error("File not found");
    }
    if (input.is_open()){
        while (getline(input, line)){
            vector<Cell> row;
            for (nat i = 0; i < line.size(); i++){
                Cell temp;
                if (line[i] == '_'){
                    temp = { Dead };
                    row.push_back(temp);
                }
                else if (line[i] == '#'){
                    temp = {Alive};
                    row.push_back(temp);
                }
            }
            if (row.size() > MAX_DIMENSIONS) throw invalid_argument("Too many cells in row");
            if (row.size() < MAX_DIMENSIONS) throw invalid_argument("Too few cells in row");
            universe.push_back(row);
        }
        input.close();
    }
    if (universe.size() < MAX_DIMENSIONS) throw invalid_argument("Too few rows of cells");
    if (universe.size() > MAX_DIMENSIONS) throw invalid_argument("Too many rows of cells");
    return universe;
};

void write(vector<vector<Cell>> universe, string file){
    ofstream output;
    output.open(file);
    for (nat i = 0; i < MAX_DIMENSIONS; i++){
        for (nat j = 0; j < MAX_DIMENSIONS; j++){
            if (universe[i][j].s == Alive){
                if (j < MAX_DIMENSIONS - 1) output << "# ";
                else output << "#"; 
            }
            if (universe[i][j].s == Dead){
                if (j < MAX_DIMENSIONS - 1) output << "_ ";
                else output << "_";   
            }
        }
        if (i < MAX_DIMENSIONS - 1)output << endl;
    }
    output.close();
}