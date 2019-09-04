#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void genmatrix(int n, double A[]){
  	int i;
	srand(time(NULL));
	
	for(i = 0; i < n*n; i++){
    		A[i] = rand();

  	}
	

}

void genvector(int n, double b[]){
	int i;
	for(i = 0; i < n; i++){
		b[i] = rand();
  	}
}

