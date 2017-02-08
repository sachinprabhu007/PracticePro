/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example8.c						*
*	Description :: Understanding OpenMP ordered clause				*
*										*
*  ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Standard library
#include<stdio.h>
#include<omp.h>  

//Defines
#define size 9		//Number of iterations
#define chunk 3

//User defined functions


void main()
{
	//Using 3 threads
	omp_set_num_threads(3);
	int count=0;
	printf("tid\titer\n");
	//Start parallel region
	#pragma omp parallel 
	{
		//Get thread id
		int tid=omp_get_thread_num();
		
		//Using ordered for
		#pragma omp for schedule(static,chunk) ordered
		for(count=0;count<size;count++)
		{	
		#pragma omp ordered
		{
			if((count%chunk)==0)
			printf("\n%d\t",tid);
			printf("%d ",count);
		}
		}
	}//End parallel region
printf("\n\n");	
}


