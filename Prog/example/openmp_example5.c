/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example5.c						*
*	Description :: Solution for OMP_lab2.c using critical for sync		*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/

//Standard library
#include<stdio.h>
#include<malloc.h>
#include<omp.h>  
//Defines
#define size 40   //size of array

//User defined functions
long update_sum(int tid);

//Global variables
long *array, total=0,count;
int max_threads;

void main()
{
	//Variable Declarations
	long index;

	//Dynamic allocation of array	
	array=(long *)malloc(size*sizeof(*array));
	
	//Intializing
	for(index=0;index<size;index++)
		array[index]=index;

	//Get maximum available threads
	max_threads=omp_get_max_threads();

	//Use all the available threads
	omp_set_num_threads(max_threads);
	
	//Start parallel region
	#pragma omp parallel 
	{
		//Get thread id
		int tid=omp_get_thread_num();
	
		//Use critical for synchronization
		#pragma omp critical
		{
			update_sum(tid);
			//Print part_sum 
			printf("After thread %d entering critical section, total = %ld\n",tid,total);
		}
	}//End parallel region

	//Print the total
	printf("\n\n%ld is the sum of first %d numbers, calculated by %d threads\n",total,size,max_threads);
	printf("Expected sum=%d\n", (size-1)*size/2);
}

//Subroutine to add array elements
long update_sum(int tid)
{	
	for(count=tid;count<size;count=count+max_threads)
		total+=array[count];
		
}
