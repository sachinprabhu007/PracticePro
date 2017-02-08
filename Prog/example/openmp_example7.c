/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example7.c						*
*	Description :: Sum and product of n numbers using barrier		*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Standard library
#include<stdio.h>
#include<malloc.h>
#include<omp.h>  

//Defines
#define size 20 //size of array

 
void main()
 {
 
	//Variable Declarations
	long *array;	
	long index,total_sum=0;
	unsigned long factorial=1;  
	int max_threads;
	
	//Dynamic allocation of array and intialization	
	array=(long *)malloc(size*sizeof(*array));
	
	//Intialization
	for(index=1;index<=size;index++)
		array[index]=index;

	//Get maximum threads available
	max_threads=omp_get_max_threads();
	
	//Use maximum threads
	omp_set_num_threads(max_threads);		
	
	//Variables for partial sum and product for each thread
	long sum[max_threads];
	unsigned long prod[max_threads]; 			
	
		
	//Pragma to parallelize
	#pragma omp parallel
	{	
		int cnt;
		//Thread id
                int tid=omp_get_thread_num();
                
                //Intialization for partial sum and produc
		sum[tid]=0;
		prod[tid]=1;
		
		//For loop to add array
	 	#pragma omp for
	 	for(cnt=1;cnt<=size;cnt++)
	 	{
			sum[tid]+=array[cnt];
		}
		printf(" In thread %d, Sum = %ld\n",tid,sum[tid]);
		
		//Wait till all the threads complete addition
		#pragma omp barrier	
		//For loop for partial product 	
		#pragma omp for
	 	for(cnt=1;cnt<=size;cnt++)
	 	{	
	 		prod[tid]*=array[cnt];
		}
		printf(" In thread %d, product = %ld\n",tid,prod[tid]);
		
			
	}
	
	//Integrate partial sum and product
	for(index=0;index<max_threads;index++)
	{
		total_sum+=sum[index];
		factorial*=prod[index];
	}
	
	//Calculate product sequentially, verification
	unsigned long expected_factorial=1;
	long expected_sum=0;
	for(index=1;index<=size;index++)
	{	
	 		expected_factorial*=array[index];
	}
	
	
	//Calculate sum using formula, verification
	expected_sum=((size)*(size+1))/2;
	
	//Print the result
	printf("\n\nCalculated by %d threads\n",max_threads);
	printf("Sum of %d numbers =\t%ld\n",size,total_sum);
	printf("Expected sum =\t %ld\n\n",expected_sum);
	printf("Factorial of %d =\t%ld\n",size,factorial);
	printf("Expected factorial =\t%ld\n\n",expected_factorial);
 
 }
