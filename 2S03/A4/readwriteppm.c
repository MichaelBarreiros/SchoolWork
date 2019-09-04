#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RGB_COMPONENT_COLOR 255

//Reads a PPM image file and returns pointer to a PPM_IMAGE structure
PPM_IMAGE *read_ppm(const char *file_name){
  //I put this srand here to seed the random number generator only one time and since this is the
  //first function called I put it here to avoid modifying the main file
  srand(time(NULL));
  char buff[3];
  int i,j;
  PPM_IMAGE *image;
  FILE *fp = fopen(file_name, "r");

  if (!fp){
    fprintf(stderr,"Unable to open file '%s'\n", file_name);
    exit(EXIT_FAILURE);
  }

  //read image format 
  if (!fgets(buff,sizeof(buff),fp)){
    perror(file_name);
    exit(EXIT_FAILURE);
  }

  //check image format
  if (buff[0] != 'P' || buff[1] != '3'){
    fprintf(stderr, "Invalid image format (must be 'P3')\n");
    exit(EXIT_FAILURE);
  }

  //allocate memory for the image
  image = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
  if (!image){
    fprintf(stderr, "Unable to allocate memory");
    exit(EXIT_FAILURE);
  }

  //read image size information
  if (fscanf(fp, "%d %d", &image->width, &image->height) != 2){
    fprintf(stderr, "Invalid image size for '%s'\n", file_name);
    exit(EXIT_FAILURE);
  }
  
  //read rgb component
  if (fscanf(fp, "%d", &image->max_color) != 1){
    fprintf(stderr, "Invalid rgb component (error loading '%s')\n", file_name);
    exit(EXIT_FAILURE);
  }

  // rgb component depth
  if (image->max_color != RGB_COMPONENT_COLOR){
    fprintf(stderr, "'%s' does not have 8-bit components \n", file_name);
    exit(EXIT_FAILURE);
  }

  //memory allocation for pixel data
  image->data = (PIXEL*)malloc(image->width * image->height * sizeof(PIXEL));

  if (!image->data){
    fprintf(stderr, "Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < image->height; i++){
	for (j = 0; j < image->width; j++){
		if(fscanf(fp, "%hhu %hhu %hhu ", &((image->data + image->width*i + j)->r), 
		  &((image->data + image->width*i + j)->g), &((image->data + image->width*i + j)->b)) != 3){
			fprintf(stderr, "Unable to successfully read pixel data from '%s' \n", file_name);
			exit(EXIT_FAILURE);
		}
	}
	if (fscanf(fp,"\n") != 1);	
  }
  
  fclose(fp);
  return image;
}

//writes a PPM image into a file in PPM format
void write_ppm(const char *file_name, const PPM_IMAGE *image){
  int i, j;
  FILE *fp = fopen(file_name, "w");

  if (!fp){
    fprintf(stderr, "Unable to open file '%s'\n", file_name);
    exit(EXIT_FAILURE);
  }

  //Write the header file
  //image format
  fprintf(fp, "P3\n");

  //image size
  fprintf(fp, "%d %d\n", image->width, image->height);

  //rgb component depth
  fprintf(fp, "%d\n", RGB_COMPONENT_COLOR);

  //pixel data
  for (i = 0; i < image->height; i++){ 
	for (j = 0; j < image->width; j++){
		fprintf(fp, "%hhu %hhu %hhu ", (image->data + image->width*i + j)->r, 
		  (image->data + image->width*i + j)->g, (image->data + image->width*i + j)->b);
	}
	if(fprintf(fp, "\n") != 1);
  }
  fclose(fp);
}

