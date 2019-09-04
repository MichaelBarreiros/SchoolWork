#include <stdio.h>
#include <math.h>
/* Sources used for this function include the psuedocode from "www.math-cd.gordon.edu/cources/ma342/handouts/gauss.pdf" and the logic from "homepage.divms.uiowa.edu/~atkinson/m171.dir/sec_8-1.pdf"*/
int linsolve(int n, double A[], double b[], double x[]){
	int i, j, k;
	double element;
	double multiplier;
	double det=1;
	
	/*Gaussian Elimination to produce Upper Triangle Matrix*/
	for(k = 0; k < n-1; k++){
		for(i = k + 1; i < n; i++){
			/*makes sure output doesnt go to infinity, if it does then there would be no solution*/
			if(A[n*k+k] == 0){
				return 0;
			}
			multiplier = A[n*i+k]/A[n*k+k];
			
			b[i] = b[i] - multiplier * b[k];			

			for(j = k; j < n; j++){
				A[n*i+j] = A[n*i+j] - multiplier * A[n*k+j];
			}
		}	
	}

	/*Backward Substitution*/

	x[n-1] = b[n-1]/A[n*n-1];

	for(i = n-2; i >= 0; i--){
		element = 0;
		for (j = i+1; j < n; j++){
			element = element + A[n*i+j] * x[j];
		}

		x[i] = (b[i] - element) / A[n*i+i];
	}

	/*Calculate the determinant of new matrix*/
	for(i=0;i<n;i++){
		det *= A[n*i+i];
	}

	/*Determines if A is singular, this returns 0 if it is singular and 1 if not singular*/
	for(i=0;i<n;i++){
		if (isnan(x[i]) || det == 0 || isnan(det)){
			return 0;
		}
		else{
			return 1;
		}
	}
	return 0;
}
