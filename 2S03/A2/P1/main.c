#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8000

void genmatrix(int n, double A[]);
void genvector(int n, double b[]);
void checkresult(int n, int flag, double A[], double b[], double x[]) ;
int linsolve(int n, double A[], double b[], double x[]);
double A[N * N], B[N*N], b[N], c[N], x[N];

int main(int argc, char **argv){
	if (argc != 2){
		printf ("Usage: main n\n");
    		return 1;
  	}
  	int n = atoi(argv[1]);
  	if (n > N){
   		 printf ("n = %d must be <= %d\n" , n, N) ;
    		return 2;
  	}
  	genmatrix(n, A);
 	genvector(n, b);
  	/* Save A and b so we use it to check the result.*/
  	memmove(B,A,n*n*sizeof(double));
  	memmove(c,b,n*sizeof(double));
  	/* You can overwrite A and b.*/
  	int success = linsolve(n, A, b ,x);
  	checkresult(n, success, B, c, x);
  	return 0;
}
