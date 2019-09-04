#define M_PI 3.14159265358979323846
#include <math.h>
#include <stdio.h>

double sinc(double x){
	double answer = 0.0;
	if (x == 0)
		return 1;
	else{
		answer = (sin(M_PI * x))/(M_PI * x);
		return answer;
	}
}

double comph(int N){
	double answer = 0.0;
	answer = M_PI/(sqrt(2 * N));
	return answer;
}

double comprho(double x, double a, double b){
	double answer = 0.0;
	answer = (x - a) / (b - x);
	return answer;
}

double complambda(double x, double h, double a, double b, int j){
	double answer = 0.0;
	answer = sinc((log(comprho(x,a,b)) - j * h) / h);
	return answer;
}

void wj(double x, double a, double b, int N, double *w){
	int i, k, count = 0;
	int negN = -N;
	double answer = 0.0;
	double sum;
	double h = comph(N);
	

	for(i = negN; i <= N; i++){
		/*Following if statement covers the first function of wj*/	
		if(i == negN){
			sum = 0.0; /*make sure sum is 0 for this iteration*/
			/*for loop covers the summation in the first function*/
			for(k = negN + 1; k <= N; k++){
				sum += complambda(x,h,a,b,k)/(1 + exp(k * h));
			}
			answer = (1 + exp(-N * h)) * (1 / (1 + comprho(x,a,b)) - sum);
			w[count] = answer;
		}
		else if(i == N){
			sum = 0.0; /*make sure sum is 0 for this iteration */
			/*for loop that covers the summation in the third function*/
			for(k = negN; k < N; k++){
				sum += (exp(k * h) * complambda(x,h,a,b,k)) / (1 + exp(k * h));
			}
			answer = (1 + exp(-N * h)) * (comprho(x,a,b)/(1 + comprho(x,a,b)) - sum);
			w[count] = answer;
		}
		else{
			answer = complambda(x,h,a,b,i);
			w[count] = answer;
		}
		count++;
	}
}
