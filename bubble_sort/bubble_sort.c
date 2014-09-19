#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef NUMBER_OF_POINTS
#define NUMBER_OF_POINTS 10
#endif
double* bubble_sort(double* array, int N);

int main() {
  srand(time(NULL));
  //create pointer to array
  double *array = (double*) malloc(NUMBER_OF_POINTS * sizeof( double ));
  if (array == NULL ) { puts("Cannot Allocate Result Array.");exit(1);}
  
  //create array of random numbers to use to test bubble sort
  for (int i = 0 ; i < NUMBER_OF_POINTS ; i++){
      array[i] = rand()/(double)RAND_MAX;
  }
  
  // call bubble_sort to sort
  array = bubble_sort(array, NUMBER_OF_POINTS);
  //print the sorted array
  for (int i = 0 ; i < NUMBER_OF_POINTS ; i++){
    printf("%f\n", array[i]);
  }  
  
  // Clean up allocated memory
  free(array);
  return 0;
}

////////////////// end of main////////////////////

double* bubble_sort(double* array, int N){
 // User must input number of indices in array (N).
 // Function assumes input array is a pointer, and elements are type double.

  for (int j = 0 ; j < N ; j++){
    //interate through all points past the current index
    for (int i = 0 ; i < N-j-1 ; i++){
      if (array[i] > array[i+1]){
        double low = array[i+1];
        double hi = array[i];
        //printf("%f %f\n", low, hi);
	array[i] = low;
        array[i+1] = hi;
      }
    }
  }
  return array;
}
