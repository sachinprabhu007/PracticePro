/********************************************************************************
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_pi.c							*
*	Description :: Computing pi value using area under curve method		*
*										*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Standard library
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

//Defines
#define SEED 35791246		//Seed to generate random number
#define ITER 1000000		//Number of iterations
#define PI 3.141592653589793	//Original PI value


void main()
{
	double pi;
	/* initialize random numbers */
	srand(SEED);
	
	int cnt,count=0;
	
	//Get maximum available threads
	int max_threads=omp_get_max_threads();
	
	//Use maximum available threads
	omp_set_num_threads(max_threads);
	
	//Start parallel region
	#pragma omp parallel 
	{
	//x and y co-ordinates private to each thread
	double x,y;
	
	//Add count value of all threads
	#pragma omp for reduction(+:count)
	for (cnt=0; cnt<ITER;cnt++)
	{
		//Select X and Y randomly in 1st quad
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		
		//Check if it falls under the curve of radius 1 unit
		if ((x*x+y*y)<=1)
			count++;
	}
	}
	
	//pi=Number of points falling under curve/Total points * Number of quadrants
	pi=(double)count/ITER*4;
	
	printf("\nFor %d iterations by %d threads\n",ITER,max_threads);
	printf("computed pi value =\t\t%lf \n",pi);
	printf("Difference from original PI =\t\t%lf\n\n",PI-pi);
}

