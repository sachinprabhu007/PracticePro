/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example3.c						*
*	Description :: Solution for OMP_lab2.c using array for synch		*
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
	long *array,index,expected_sum,sum[4],total_sum=0;  
	int max_threads, nthreads;
	
	for(index=0;index<4;index++)		//Intializing sum to 0, used by each thread to update local sum
		sum[index]=0;
	

	//Dynamic allocation of array and intialization	
	array=(long *)malloc(size*sizeof(*array));
	for(index=0;index<size;index++)
		array[index]=index;

	//Get maximum threads available
	max_threads=omp_get_max_threads();
	
	printf("%d is the maximum threads\n",max_threads );
	
	//Use 4 threads
	omp_set_num_threads(4);		

	//Pragma to parallelize
	#pragma omp parallel
	{	//Thread id
                int cnt;
		int tid=omp_get_thread_num();
		nthreads=omp_get_num_threads();
		
		//For loop to add array
	 	for(cnt=tid;cnt<size;cnt+=nthreads)
	 	{
			sum[tid]+=array[cnt];
		}		
		printf(" In thread %d Sum = %ld\n",tid,sum[tid]);
			
	}
	
	for(index=0;index<nthreads;index++)
	{
		total_sum+=sum[index];
	}
	
	expected_sum=((size)*(size-1))/2;
	
	//Print the result
	printf("%ld is the sum of first %d numbers, calculated by %d threads\n",total_sum,size,nthreads);
	printf("\n\n Expected sum is %ld\n\n",expected_sum);
 }


/*
4 is the maximum threads
 In thread 0 Sum = 3218
 In thread 3 Sum = 4950
 In thread 1 Sum = 4950
 In thread 2 Sum = 4392
4950 is the sum of first 100 numbers, calculated by 4 threads


Expected sum is 4950

*/
