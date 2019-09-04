#include "assignment3.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 8000
#define MAX 500

static int cmpfunc(const void * a, const void * b) {
	return(*(int*)a - *(int*)b);
}

static void generateArray(int size, int min, int max, int *a) {
	int i, value;	
 
	for (i = 0; i < size; i++) {
		value = rand() % (max + 1);
		while (value < min) value = rand() % max; /*ensures that the value is never smaller than min and also */
		a[i] = value;
	}
}

HBnodePtr createHBlist(int n, int m) {
	int i, j;
	time_t t;
	srand(time(NULL));

	if (n <= 0) return NULL;

	int num_bottom[N]; /*this is an array for the random number of nodes for the bottom list*/
	int HBintegers[N];
	int SLintegers[N]; /*An array of random integer values for keys*/

	if (m > 0) generateArray(n, 0, m, num_bottom); /*only generate array for bottom lengths if m >0 */

	generateArray(n, 0, MAX, HBintegers);
	qsort(HBintegers, n, sizeof(int), cmpfunc);

	struct HBnode *L; /*sets list initially to empty*/
	struct SLnode *firstBottom;

	L = malloc(sizeof(struct HBnode));
	firstBottom = malloc(sizeof(struct SLnode));

	/*initiallizing the first item in the list*/
	L->key = HBintegers[0];
	L->next = NULL;

	if (m>0){
		generateArray(num_bottom[0], HBintegers[0], MAX, SLintegers);
		qsort(SLintegers, num_bottom[0], sizeof(int), cmpfunc);

		/*initializing the first item in the SL bottom list*/
		if (SLintegers == NULL){
			/*skip this key*/
		}
		else{
			firstBottom->key = SLintegers[0];
		}

		firstBottom->next = NULL;

		/*generating and linking the next lists*/
		for(j=1; j<num_bottom[0]; j++){
			struct SLnode *temporarySL;
			temporarySL = malloc(sizeof(struct SLnode));

			temporarySL->key = SLintegers[j];
			temporarySL->next = NULL;

			struct SLnode *currentSL = firstBottom;

			while (currentSL->next != NULL) {
				currentSL = currentSL->next;
			}

			currentSL->next = temporarySL;
		}

		L->bottom = firstBottom;
	}
	else{
		firstBottom = NULL;
		L->bottom = NULL;
	}

	/*This is for creating the linked list*/
	for (i = 1; i < n; i++){
		struct HBnode *tempHB;
		tempHB = malloc(sizeof(struct HBnode));

		tempHB->key = HBintegers[i];
		tempHB->next = NULL;

		struct SLnode *B = NULL;/*this is a list for the SL bottom lists*/
		B = malloc(sizeof(struct SLnode));

	    	if (m > 0){
	      		generateArray(num_bottom[i], HBintegers[i], MAX, SLintegers);
	      		qsort(SLintegers, num_bottom[i], sizeof(int), cmpfunc);

			if (num_bottom[i] == 0){
				/*if the number of items in the bottom list equals 0 then skip this key*/
			}
			else {
				B->key = SLintegers[0];
			}

			B->next = NULL;
	      
			for (j = 1; j < num_bottom[i]; j++){
				struct SLnode *tempSL;
				tempSL = malloc(sizeof(struct SLnode));

				tempSL->key = SLintegers[j];
				tempSL->next = NULL;

				struct SLnode *currentSL = B;		/*adds the created SL to the end of the current B*/

				while (currentSL->next != NULL) {
					currentSL = currentSL->next;
				}

				currentSL->next = tempSL;
			}
	      		tempHB->bottom = B;
		}
		else {
			tempHB->bottom = NULL;
		}

		struct HBnode *currentHB = L;	/*adds the created HB and SL to the end of the current L*/

		while (currentHB->next != NULL) {
			currentHB = currentHB->next;
		}

		currentHB->next = tempHB;
	}

	/*returns pointer to the HB list*/
	return L;
}

SLnodePtr flattenList(const HBnodePtr L) {
  
}

void freeSLlist(SLnodePtr L) {
	/*if there is only one item in the list, remove it*/
	if (L->next == NULL) {
		free(L);
	}

	/*get to the second last node in the list*/
	struct SLnode *current = L;
	while (current->next->next != NULL) {
		current = current->next;
	}

	/*removes the last item in the list*/
	free(current->next);
	current->next = NULL;
	/*calls on itself so that all elements of L are freed*/
	freeSLlist(L);
}

void freeHBlist(HBnodePtr L) {
	if (L->next == NULL) {
		if (L->bottom == NULL) {
			free(L);
		}
	}
	
	struct HBnode *current = L;
	while (current->next->next != NULL) {
		current = current->next;
	}

	freeSLlist(current->next->bottom);
	free(current->next);
	current->next = NULL;

	freeHBlist(L);
}

void printHBlist(const HBnodePtr L) {
	struct HBnode *current = L;

	while (current != NULL) {
		printf("%d->", current->key);
		printSLlist(current->bottom);
    		printf("\n");
		current = current->next;
	}
}

void printSLlist(const SLnodePtr L) {
	struct SLnode *current = L;

	while (current != NULL) {
		if (current->key == 0) break;
		else{
			printf("%d ", current->key);
			current = current->next;
		}
	}
}
