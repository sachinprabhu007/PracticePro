/********************************************************************************
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program ::openmp_mm.c							*
*	Description :: 2 Matrix multiplication using OpenMP			*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 
//Include standard library
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

//Include user libraries

//Defines
#define PRINT
#define ROWA 5                 /* number of rows in matrix A */
#define COLA 5                 /* number of columns in matrix A */
#define COLB 5                 /* number of columns in matrix B */

int main (int argc, char *argv[]) 
{
	int	row,column,column1;
	double	in_A[ROWA][COLA],in_B[COLA][COLB],out_C[ROWA][COLB];  //Input matrices A & B and output matrix C
	int	tid, nthreads, max_threads, chunk=10;		//Thread ID, number of threads and loop size

	//Get max threads
	max_threads=omp_get_max_threads();

	#ifdef PRINT   
		printf("Matrix multiplication has started with %d threads.\n",max_threads);
	#endif

	//Start Parallel region
	#pragma omp parallel shared(in_A,in_B,out_C, nthreads,chunk) private(tid,row,column,column1)
	{
		tid = omp_get_thread_num();
		nthreads=omp_get_num_threads();
	
		/*** Initialize matrices ***/
		#pragma omp for schedule (static, chunk)
			for (row=0; row<ROWA; row++)
				for (column=0; column<COLA; column++)
					#ifdef PRINT
		   	 		 	in_A[row][column]= 1.0; 
		   			#else
		   	 		 	in_A[row][column]= (double)rand();
					#endif
	  
		#pragma omp for schedule (static, chunk) 
			for (row=0; row<COLA; row++)
				for (column=0; column<COLB; column++)
					#ifdef PRINT
		   	  			in_B[row][column]= 1.0; 
		   			#else
		   	 		 	in_B[row][column]= (double)rand();
					#endif

		 #pragma omp for schedule (static, chunk) 
			for (row=0; row<ROWA; row++)
				for (column=0; column<COLB; column++)
					out_C[row][column]=0;
	      
		/*****Multiply*****/
		#pragma omp for schedule (static, chunk) 
		for (row=0; row<ROWA; row++) 
	    		for (column=0; column<COLB; column++)      
				for (column1=0; column1<COLA; column1++)
					out_C[row][column] += in_A[row][column1] * in_B[column1][column];

	}  
	/*** Print results ***/
	#ifdef PRINT
	 {     
	 	printf("\n******************************************************\n");
	 	for (row=0; row<ROWA; row++)
	      	{
			printf("\n"); 
		 	for (column=0; column<COLB; column++) 
		    		printf("%6.2f   ", out_C[row][column]);
	      	}
	      
	      printf("\n******************************************************\n");
	 }  
	#endif

	printf("Multiplied using %d Threads\n\n",nthreads);
}

