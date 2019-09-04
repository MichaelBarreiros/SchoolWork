#include "a4.h"
#include <stdlib.h>

//returns pointer to an array of width*height pixels
PIXEL *generate_random_image(int width, int height, int max_color){
  int i,j;
  int mod = max_color + 1;
  PIXEL *random = (PIXEL*)malloc(width * height * sizeof(PIXEL));  
  
  for (i = 0; i < height; i++){
    for (j = 0; j < width; j++){
      (random + width*i + j)->r = rand() % mod;
      (random + width*i + j)->g  = rand() % mod;
      (random + width*i + j)->b = rand() % mod;
    }
  }
  return random;
}

//returns a pointer to an array of size pop_size. each entry is a struct of type individual
Individual *generate_population(int population_size, int width, int height, int max_color){
  int i;
  Individual *ind = (Individual*)malloc(population_size*sizeof(Individual));

  for (i = 0; i < population_size; i++){
    (ind+i)->image.max_color = max_color;
    (ind+i)->image.width = width;
    (ind+i)->image.height = height;
    (ind+i)->image.data = generate_random_image(width,height,max_color);
  }
  return ind;
}
