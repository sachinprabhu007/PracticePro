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
	max_threads=//== >get maximum threads
	
	printf("%d is the maximum threads\n",max_threads );
	
	//Use 4 threads
	//==>set number of threads to 4
	
	//==> Add Pragma to parallelize
	
	{	//Thread id
		int cnt;		//Private to all threads
		int tid= //==>Get thread id of each thread
		 nthreads= //==>Get number of threads used
		
		//For loop to add array
	 	for(cnt=tid;cnt<size;cnt+=nthreads)
	 	{
		//==> Add array elements using atomic for synchronization 
		}
		printf(" In thread %d Sum = %ld\n",tid,sum);
			
	}
	expected_sum=((size)*(size-1))/2;
	
	//Print the result
	printf("%ld is the sum of first %d numbers, calculated by %d threads\n",sum,size,nthreads);
	printf("\n\n Expected sum is %ld\n\n",expected_sum);
 }
