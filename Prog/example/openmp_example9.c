/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: omp_example9.c						*
*	Description :: Array sum using lock					*
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
	long *array,index,sum=0,expected_sum;
	int max_threads, nthreads;
	//Allocate memory
	array=(long *)malloc(size*sizeof(*array));
	for(index=0;index<size;index++)
	//Initialize
		array[index]=index;
	omp_lock_t updatelock; 	//Declaring lock variable
	omp_init_lock(&updatelock);    //Initializing lock 
	//Parallelize
	#pragma omp parallel
	{	int cnt;	
		int tid=omp_get_thread_num();
		nthreads=omp_get_num_threads();
	 	for(cnt=tid;cnt<size;cnt+=nthreads) 	
	 	{
	 		//Lock the below
	 		omp_set_lock(&updatelock);
			sum+=array[cnt];
			//Release lock
			omp_unset_lock(&updatelock);
		}		
		printf(" In thread %d Sum = %ld\n",tid,sum);
		omp_destroy_lock(&updatelock);	
	}
	expected_sum=((size)*(size-1))/2;	
	printf("%ld is the sum of first %d numbers, calculated by %d threads\n",sum,size,nthreads);
	printf("\n\n Expected sum is %ld\n\n",expected_sum);  
	
}//end of main
