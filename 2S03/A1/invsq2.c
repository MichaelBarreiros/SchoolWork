#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main (){
	double a, x0, xi, ei;
	
	printf("Enter a : " );
	scanf("%lf", &a);
	do{
		if(a <= 0){//makes sure correct input is acquired
			printf("\nERROR: Number(s) entered was outside boundary\n");
			printf("Enter a (a must be greater than 0): ");
			scanf("%lf", &a);
		}
	}while(a <= 0);
	
	xi = 2/(1+a);
	
	do{
		
		xi = xi*(1.5-0.5*a*xi*xi); //Newton's Method Formula
		printf("%.15e ", xi);
		
		
		ei = fabs(xi - 1/sqrt(a))*sqrt(a);
		printf("%.2e\n", ei);		
	}while(ei > (1/pow(10,13))); //does this loop as long as the error is less than 10^-13
	
	return 0;
}
