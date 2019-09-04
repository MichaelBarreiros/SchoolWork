#include <stdio.h>
#include <stdlib.h>

extern void wj(double x, double a, double b, int N, double *w);

int main(int argc, char **argv){
	if(argc !=5){
		printf("\n Usage sinc N a b x \n");
		return 1;
	}
	int N =  atoi(argv[1]);
	double a = atof(argv[2]);
	double b = atof(argv[3]);
	double x = atof(argv[4]);

	double w[2 * N + 1];
	wj(x, a, b, N, w);
	int i;
	for(i = 0; i < 2*N+1; i++)
		printf("% 3i  % e\n", i, w[i]);
	return 0;
}
