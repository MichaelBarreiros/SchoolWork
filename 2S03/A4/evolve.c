#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

int cmpfunc(const void *a, const void *b) {
	Individual *fitnessA = (Individual *)a;
	Individual *fitnessB = (Individual *)b;

        return(fitnessA->fitness - fitnessB->fitness);
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
  int i;

  //Generate a random population of population_size
  Individual *population = generate_population(population_size, image->width, image->height, image->max_color);

  //Compute the fitness of each individual
  comp_fitness_population(image->data, population, population_size);

  //Sort the individuals in non-decreasing order of fitness, first individual will have the closest distance to og image, it is the most "fitted"
  qsort(population, population_size, sizeof(Individual),cmpfunc);

  //For Generation 1 to number_generations
  for (i = 1; i <= num_generations; i++){
    //a) do a crossover on the population
    crossover(population, population_size);
    //b)mutate individuals from pop_size/4 to pop_size-1. The -1 is taken into account in the mutate_population function
    mutate_population(population, population_size, rate);
    //c) compute the fitness of each individual
    comp_fitness_population(image->data, population, population_size);
    //d) sort the individuals in non-decreasing order of fitness value
    qsort(population, population_size, sizeof(Individual),cmpfunc);
    //printf("Generation %d's best fitness value %f\n", i, (population)->fitness);
  }
  //Returns a pointer to a PPM_IMAGE containing the fittest image, the one with the smallest fitness value
  PPM_IMAGE *img = (PPM_IMAGE*)malloc(sizeof(PPM_IMAGE));
  img->data = population->image.data;
  img->height = population->image.height;
  img->width = population->image.width;
  img->max_color = population->image.max_color;

  //Deallocate all individuals and their data
  for (i = population_size-1; i >= 1; i--){
        free(((population+i)->image.data));
  }
  free(population);
  return img;
}

void free_image(PPM_IMAGE *p){
  free(p->data);
  free(p);
}

