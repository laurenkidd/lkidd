#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifndef NUMBER_OF_POINTS
#define NUMBER_OF_POINTS 20000
#endif

typedef struct { //struct to hold coordinates for each ordered-pair.
  double x,y;
} points;




int main(int argc, char **argv)
{

  srand(time(NULL));
  int *index_array = (int*) malloc(NUMBER_OF_POINTS * sizeof( int ));
  if (index_array == NULL ) { puts("Cannot Allocate Result Array.");exit(1);}
  points *p = (points*) malloc(NUMBER_OF_POINTS * sizeof(points));
  if (p == NULL ) { puts("Cannot Allocate points.");exit(1);}


 
// Populate plane with points and write locations of points.
    for (int i = 0 ; i < NUMBER_OF_POINTS ; i++){
      p[i].x = rand()/(double)RAND_MAX;    
      p[i].y = rand()/(double)RAND_MAX;    
    }



// Find nearest neighbor
  for (int i = 0 ; i < NUMBER_OF_POINTS ; i++){
//  Loop over all points
//  set initial distance to use to as distance comparison; large value to ensure it will 
//  be larger than all actual distances
    double dist1 = 10.0; 
    for (int j = 0; j < NUMBER_OF_POINTS; j++){
      if (j != i){
	double dist = fabs(sqrt(pow(p[i].x,2)+pow(p[i].y,2))-sqrt(pow(p[j].x,2)+pow(p[j].y,2)));
	if (dist < dist1){
          dist1 = dist; //new smallest distance to compare to distances of other indices
          index_array[i] = j;
        }
      }
    }
  }


  
// Write out indices of nearest neighbor to ith point.
  for (int i = 0; i < NUMBER_OF_POINTS ; i++){
    printf("%s %d %s %d\n","index ", i, "  nearest neighbor ", index_array[i]);
  }


// Clean up allocated memory
  free(index_array);
  free(p);
  return 0;
}
