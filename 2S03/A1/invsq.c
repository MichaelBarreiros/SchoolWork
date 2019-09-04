#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main (){
	double a, x0, xi, ei;
	int n, i;
	
	printf("Enter a, x0, and n: " );
	scanf("%lf %lf %d", &a, &x0, &n);
	do{
		if(a <= 0 || x0 <= 0){//makes sure correct input is acquired
			printf("\nERROR: Number(s) entered was outside boundary\n");
			printf("Enter a, x0, and n (a and x0 must be greater than 0 and n must be an integer): ");
			scanf("%lf %lf %d", &a, &x0, &n);
		}
	}while(a <= 0 || x0 <= 0);
	
	xi = x0;
	
	for(i = 0; i < n; i++){
		printf("%d ", i + 1);
		xi = xi * (1.5 - 0.5 * a * xi * xi); //Newton's Method Formula
		printf("%.15e ", xi);
		
		
		ei = fabs(xi - 1/sqrt(a)) * sqrt(a);
		printf("%.2e\n", ei);		
	}
	return 0;
}

