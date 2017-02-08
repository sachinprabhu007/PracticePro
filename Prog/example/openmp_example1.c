/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example1.c						*
*	Description :: OpenMP Hello world Excercise		  		*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Standard library
#include<stdio.h>
//OpenMP library
#include<omp.h>  

void main()
{
	//Variable Declarations
	int max_threads;
	
	//Get Avialable threads
	max_threads=omp_get_max_threads();
	printf("Available Threads =%d \n",max_threads);

	//Set number of threads to use.//Note: by default uses all available threads
	omp_set_num_threads(max_threads);

	//Start parallel region
	#pragma omp parallel
	{
		//Print "Helloworld" By each thread and its thread number and total available threads
		//Get thread id
		int id =omp_get_thread_num();
		//Get number of threads we are using
		int tot = omp_get_num_threads();
		printf("Hello world by Thread = %d out of %d\n",id, tot);			
	}	

}
