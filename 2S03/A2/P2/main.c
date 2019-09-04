#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8000

void genmatrix(int n, double A[]);
void genvector(int n, double b[]);
void checkresult(int n, int flag, double A[], double b[], double x[]) ;
int linsolve(int n, double A[], double b[], double x[]);
double gettime();
double A[N * N], b[N], x[N];

int main(){
  	int n;
	
	for(n=1000; n<=N; n*=2){
		genmatrix(n, A);
 		genvector(n, b);

		double t = gettime();
		int success = linsolve(n,A,b,x);
		printf("success %d: %8d   % 1e \n", success, n,gettime()-t);
	}
  	return 0;
}
