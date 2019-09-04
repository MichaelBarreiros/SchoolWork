#include "a4.h"
#include <stdlib.h>

void mutate(Individual *individual, double rate){
  int n = individual->image.height*individual->image.width;
  int range = (int)(rate/100*n);
  int i, randomPixel;
  int mod = n + 1;
	
  for (i = 0; i < range; i++){
    randomPixel = rand() % mod;
    (individual->image.data+randomPixel)->r = rand() % (256);
    (individual->image.data+randomPixel)->g = rand() % (256);
    (individual->image.data+randomPixel)->r = rand() % (256);
  }  
}

//Mutates all individuals starting from index pop_size/4 to the end of the pop. (individual + popsize/4)
void mutate_population(Individual *individual, int population_size, double rate){
  int index = population_size/4;
  int i;

  for (i = index; i < population_size; i++){
    mutate((individual + i), rate);
  }
}
