/********************************************************************************
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program ::mm_seq.c							*
*	Description :: Matrix multiplication in sequence			*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Header files
#include <stdio.h>
#include <stdlib.h>

//Defines
#define PRINT
#define ROWA 10                 // number of rows in matrix A 
#define COLA 10                 // number of columns in matrix A 
#define COLB 10                 // number of columns in matrix B 

//User defined function

//Dynamic allocation of 2D matrix 
double** MallocM(long row,long col) 
{
	int rw;
	double **Mat;
	Mat=(double **)malloc(row*sizeof(**Mat));
	for(rw=0;rw<row;rw++) 
	{	Mat[rw]=(double *)malloc(col*sizeof(*Mat[rw]));
  	}
  	return Mat;
}

//Free allocated memory for matrix
void FreeM(double **Mat, long row) 
{
	int rw;
	for(rw=0;rw<row;rw++) 
		free(Mat[rw]);
	free(Mat);
	Mat=NULL;
}

int main (int argc, char *argv[]) 
{

	int	row,column,column1;
	double	**in_A,           // matrix A to be multiplied 
		**in_B,           // matrix B to be multiplied 
		**out_C;          // result matrix C 

	//Allocated memory for matrices
	in_A=MallocM(ROWA,COLA);
	in_B=MallocM(COLA,COLB);
	out_C=MallocM(ROWA,COLB);

	// Initialize matrices 

		for (row=0; row<ROWA; row++)
			for (column=0; column<COLA; column++)
			#ifdef PRINT
				in_A[row][column]=1.0;
			#else
	  			in_A[row][column]=rand();
	  		#endif
	  
		for (row=0; row<COLA; row++)
			for (column=0; column<COLB; column++)
	      			#ifdef PRINT
				in_B[row][column]=1.0;
			#else
	  			in_B[row][column]=rand();
	  		#endif
		for (row=0; row<ROWA; row++)
	    		for (column=0; column<COLB; column++)
	      		#ifdef PRINT
				out_C[row][column]=0;
			#else
	  			out_C[row][column]=0;
	  		#endif
	      
	//Multiply 
	  	for (row=0; row<ROWA; row++) 
	    		for (column=0; column<COLB; column++)      
	       			for (column1=0; column1<COLA; column1++)
					out_C[row][column] += in_A[row][column1] * in_B[column1][column];

	  
	//Print results
	#ifdef PRINT
	{
	for (row=0; row<ROWA; row++)
	{ 	for (column=0; column<COLB; column++)
	    		printf("%6.2f   ",out_C[row][column]);
	  	printf("\n"); 
	}
	}
	#endif

	//Free Allocated memory
	FreeM(in_A,ROWA); 
	FreeM(in_B,COLA); 
	FreeM(out_C,ROWA); 
	printf("Multiplied sequentially\n\n");
}

