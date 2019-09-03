#include <iostream>
#include <vector>

#include "Output.h"

using namespace std;

void print(vector<vector<Cell>> universe, nat generation){
    cout << "Generation " << generation << endl;
    cout << "====================================" << endl;
    cout << endl;

    for (nat i = 0; i < MAX_DIMENSIONS; i++){
        for (nat j = 0; j < MAX_DIMENSIONS; j++){
            if (universe[i][j].s == Alive){
                if (j < MAX_DIMENSIONS - 1)  cout << "# ";
                else cout << "#"; 
            }
            if (universe[i][j].s == Dead){
                if (j < MAX_DIMENSIONS - 1) cout << "_ ";
                else cout << "_";   
            }
        }
        if (i < MAX_DIMENSIONS - 1) cout << endl;
    }
    cout << "\n" << endl;
}