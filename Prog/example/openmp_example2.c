/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example2.c						*
*	Description :: Solution for OMP_lab2.c using atomic for synch		*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Standard library
#include<stdio.h>
#include<malloc.h>
#include<omp.h>  

//Defines
#define size 100 //size of array

 
void main()
 {
 
	//Variable Declarations
	long *array,index,sum=0,expected_sum;
	int max_threads, nthreads;

	//Dynamic allocation of array and intialization	
	array=(long *)malloc(size*sizeof(*array));
	for(index=0;index<size;index++)
		array[index]=index;

	//Get maximum threads available
	max_threads=omp_get_max_threads();
	
	printf("%d is the maximum threads\n",max_threads );
	
	//Use maximum threads available
	omp_set_num_threads(max_threads);	
	
	//Pragma to parallelize
	#pragma omp parallel
	{	//Thread id
                int cnt;	//Private to all threads
		int tid=omp_get_thread_num();
				
		//For loop to add array
	 	for(cnt=tid;cnt<size;cnt+=max_threads)
	 	{
		#pragma omp atomic
			sum+=array[cnt];
		}		
		printf(" In thread %d Sum = %ld\n",tid,sum);
		fflush(0);	
	}
	expected_sum=((size)*(size-1))/2;
	
	//Print the result
	printf("%ld is the sum of first %d numbers, calculated by %d threads\n",sum,size,max_threads);
	printf("\n\nExpected sum is %ld\n\n",expected_sum);
 }
