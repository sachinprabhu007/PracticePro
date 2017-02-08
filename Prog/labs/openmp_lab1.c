/********************************************************************************
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_lab1.c						*
*	Description :: OpenMP Hello world Excercise		  		*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Standard library
#include<stdio.h>
//OMP library
#include<omp.h>  

void main()
{
	//Variable Declarations
	int max_threads;
	
	//Get Avialable threads
	
	printf("Available Threads =%d \n",max_threads);

	//Set number of threads to use.//Note: by default uses all available threads
	

	//Start parallel region
	#pragma omp parallel
	{
		//Print "Helloworld" By each thread and its thread number and total available threads
		//Get thread id
		int id =;
		//Get number of threads we are using
		int tot = ;
		//print "hello world" by each thread
	}	

}
