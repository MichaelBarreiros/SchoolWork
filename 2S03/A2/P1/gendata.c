#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void genmatrix(int n, double A[]){
  	int i;
	srand(time(NULL));	

	for(i = 0; i < n*n; i++){
    		A[i] = rand();
		printf("A[%d]: %lf\n",i, A[i]);
  	}
	

}

void genvector(int n, double b[]){
	int i;
	for(i = 0; i < n; i++){
		b[i] = rand();
  	}
}

