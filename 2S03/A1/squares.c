#include <stdio.h>

int main (){
	int number_of_squares, number_of_rows, number_of_columns;

	printf("Enter number of squares (must be between 1 and 50): ");//asks user for input
	scanf("%d", &number_of_squares);//stores input
	
	do{
		if(number_of_squares < 1 || number_of_squares > 50){//makes sure correct input is acquired
			printf("\nERROR: Number entered was outside boundary\n");
			printf("Enter number of squares (must be between 1 and 50): ");
			scanf("%d", &number_of_squares);
		}
	}while(number_of_squares < 1 || number_of_squares > 50);
	
	if(number_of_squares < 5)//Makes sure at least 1 row of squares will print
		number_of_rows = 0;
	else
		number_of_rows = number_of_squares / 5;
	
	number_of_columns = number_of_squares % 5;
	
	for(int i = 0; i < number_of_rows; i++){ //prints full rows
		printf("### ### ### ### ### \n");
		printf("### ### ### ### ### \n");
		printf("### ### ### ### ### \n\n");
	}
	
	if (number_of_columns == 4){
		printf("### ### ### ### \n");
		printf("### ### ### ### \n");
		printf("### ### ### ### \n\n");
	}else if(number_of_columns == 3){
		printf("### ### ### \n");
		printf("### ### ### \n");
		printf("### ### ### \n\n");
	}else if(number_of_columns == 2){
		printf("### ### \n");
		printf("### ### \n");
		printf("### ### \n\n");
	}else if(number_of_columns == 1){
		printf("### \n");
		printf("### \n");
		printf("### \n\n");
	}
}
