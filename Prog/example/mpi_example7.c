/********************************************************************************
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: mpi_example7.c						*
*	Description :: Sum of array elements using MPI scatter gather		*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

//Include standard header files
#include <stdio.h>
#include <mpi.h>

//Include user defined header files
//Defines
//Global variables

//Pass argc and argv for main
int main (int argc, char *argv[])
 {
	//Int variables for Process number & number of processes .
	int  rank,row, size;

	//Intialize MPI
	MPI_Init (&argc, &argv);
	//Get number of processes
	MPI_Comm_size (MPI_COMM_WORLD, &size);
	//Get processes  number 
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	//Array size = 10*np
	int arr_size=size*10;
	int master=0,worker,array[arr_size];

	//Variables to store the sum
	int total[size],total1=0;
	//Master task		
	if(rank==master)
	{	//Intialize
		for(row=0;row<=arr_size;row++)
			array[row]=row;
	
	}
	
	//Scatter 10 elements to all the process
	MPI_Scatter(array,10,MPI_INT,array,10,MPI_INT,0,MPI_COMM_WORLD);
	
	//Add, by all the process
	total[rank]=0;
	for(row=0;row<10;row++)
		total[rank]+=array[row];
	printf("%d is the partial sum computed by rank %d\n",total[rank],rank);	
	
	//Gather partial sum from all the process
	MPI_Gather(&total[rank],1,MPI_INT,total,1,MPI_INT,0,MPI_COMM_WORLD);
	
	//In master
	if(rank==master)
	{
		//Integrate partial sum
		for(row=0;row<=size;row++)
			total1+=total[row];
		printf("%d is the sum of %d numbers computed by %d process\n",total1,arr_size,size);	
		//Check for accuracy
		printf ("expected sum = %d\n", arr_size*(arr_size-1)/2);	
	}
	
	//Finalize MPI
	MPI_Finalize ();
	return 0;
 }

