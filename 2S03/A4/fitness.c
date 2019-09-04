#include "a4.h"
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  double distance = 0;
  double answer = 0;
  int i;
  
  for (i = 0; i < image_size; i++){
    distance += pow((A+i)->r - (B+i)->r,2) + pow((A+i)->g - (B+i)->g,2) + pow((A+i)->b - (B+i)->b,2);
  }
  return answer = sqrt(distance);
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
  int i;
  int image_size = individual->image.height * individual->image.width;
  for (i = 0; i < population_size; i++){ 
    (individual+i)->fitness = comp_distance(image, (individual+i)->image.data, image_size);
  }

}
