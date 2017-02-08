/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example4.c						*
*	Description :: Solution for OMP_lab2.c using subroutine			*
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
long add_array(long int *arr,int length);

void main()
{
	//Variable Declarations
	long index, *array, total=0;

	//Dynamic allocation of array	
	array=(long *)malloc(size*sizeof(*array));
	for(index=0;index<size;index++)
		array[index]=index;

	//Get maximum available threads
	int max_threads=omp_get_max_threads();

	//Use all the available threads
	omp_set_num_threads(max_threads);
	 
	//Create a sum-array of length number of threads we are using
	long sum[max_threads];
	
	//Intialization of sum-array to 0
	for(index=0;index<omp_get_max_threads();index++)
			sum[index]=0;

	//Start parallel region
	#pragma omp parallel
	{
		//Get thread id
		int tid=omp_get_thread_num();
	
		//Parallelize for loop
		sum[tid]=add_array(array,size);
	
		//Print individual sum calculated, it should be different for every thread
		printf(" In thread %d Sum[%d] = %ld\n",tid,tid,sum[tid]);
	}//End parallel region


	//Add sum-array elements for final sum
	for(index=0;index<max_threads;index++)
		total=add_array(sum,max_threads);

	//Print the total
	printf("%ld is the sum of first %d numbers, calculated by %d threads\n",total,size,max_threads);
}

//Subroutine to add array elements
long add_array(long int *arr,int length)
{	
	long count,add=0;
	#pragma omp for
	for(count=0;count<length;count++)
	 		add+=arr[count];
	 return add;
}
