/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example6.c						*
*	Description :: Sum of n fibbonacci numbers, using ordered		*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Standard library
#include<stdio.h>
#include<malloc.h>
#include<omp.h>  
//Defines
#define size 45   //size of array

//User defined functions

//Global variables
long *array, total=0;
int max_threads;

void main()
{
	//Variable Declarations
	long index,expected_sum,count;

	//Dynamic allocation of array	
	array=(long *)malloc(size*sizeof(*array));
	
	//Get maximum available threads
	max_threads=omp_get_max_threads();
	long sum[max_threads];
	for(index=0;index<max_threads;index++)
		sum[index]=0;
	//Use all the available threads
	omp_set_num_threads(max_threads);
	
	//Fibonnaci numbers intialization
	array[0]=0;
	array[1]=1;
	
	
	//Start parallel region
	#pragma omp parallel 
	{
		//Get thread id
		int tid=omp_get_thread_num();
		//Use ordered for synchronization
		#pragma omp for ordered
		for(count=2;count<size;count++)
		{	
			//Intialize and print sequentially using order
			#pragma omp ordered
			{
				array[count]=array[count-1]+array[count-2];
				printf("%ld\t",array[count]);
			}
			//Individual sum for all the threads
			sum[tid]+=array[count];
		}
		 
		
		
	}//End parallel region
	
	//Expected sum using formula
	expected_sum=2*array[size-1]+array[size-2]-1;
	
	//Add the part sum
	for(index=0;index<max_threads;index++)
		total+=sum[index];

	//Add 0th and 1st element of series
		total=total+array[1]+array[0];
	
	//Print the total
	printf("\n\n%ld is the sum of first %d fibbonacci numbers, calculated by %d threads\n",total,size,max_threads);
	printf("Expected sum=%ld\n", expected_sum);
}

