#include <stdio.h>

int main(){
	
	int n, one_previous, two_previous, next_int;
	int div_by_2, div_by_3, div_by_5, div_by_6, div_by_10, div_by_15, not_div_by_previous;
	printf("Enter a positive integer : ");
	scanf("%d", &n);
	do{
		if(n <= 0){//makes sure correct input is acquired
			printf("\nERROR: Number was not a positive integer\n");
			printf("Enter n (n must be greater than 0): ");
			scanf("%d", &n);
		}
	}while(n <= 0);
	
	one_previous = 1;
	two_previous = 1;
	div_by_2 = 0;
	div_by_3 = 0;
	div_by_5 = 0;
	div_by_6 = 0;
	div_by_10 = 0;
	div_by_15 = 0;
	not_div_by_previous = 2;
	printf("1, 1, ");
	
	do{
		next_int = two_previous + one_previous;
		if(next_int < n){
			printf("%d, ", next_int);
			two_previous = one_previous;
			one_previous = next_int;
			
			if(next_int % 2 == 0)
				div_by_2 ++;
			if(next_int % 3 == 0)
				div_by_3 ++;
			if(next_int % 5 == 0)
				div_by_5 ++;
			if(next_int % 6 == 0)
				div_by_6 ++;
			if(next_int % 10 == 0)
				div_by_10 ++;
			if(next_int % 15 == 0)
				div_by_15 ++;
			if(next_int % 2 != 0 && next_int % 3 != 0 && next_int % 5 != 0 && next_int % 6 != 0 && next_int % 10 != 0 && next_int % 15 != 0)
				not_div_by_previous ++;
		}
	}while(next_int < n);
	
	printf("\n\ndivisibley by:\n");
	printf("2\t\t%d\n", div_by_2);
	printf("3\t\t%d\n", div_by_3);
	printf("5\t\t%d\n", div_by_5);
	printf("6\t\t%d\n", div_by_6);
	printf("10\t\t%d\n", div_by_10);
	printf("15\t\t%d\n", div_by_15);
	printf("-\t\t%d\n", not_div_by_previous);
	return 0;
}
