/*******************************************************************************
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program ::mm_mpi.c							*
*	Description ::Matrix multiplication using MPI				*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 
//Include standard library
#include <stdio.h>
#include <mpi.h>
#include <malloc.h>

//Include user libraries

//Defines
#define PRINT
#define ROWA 5                 // number of rows in matrix A 
#define COLA 5                 // number of columns in matrix A 
#define COLB 5                 // number of columns in matrix B 
#define MASTER 0               // taskid of first task 
#define FROM_MASTER 1
#define FROM_WORKER 2
#define PRINT

//Global variables



int main (int argc, char *argv[])
{
	int	numtasks,              // number of tasks in partition 
		taskid,                // a task identifier 
		numworkers,            // number of worker tasks 
		source,                // task id of message source 
		dest,                  // task id of message destination 
		tag,                 // message type 
		rows,                  // rows of matrix A sent to each worker 
		averow, extra, offset, // used to determine rows sent to each worker 
		row,column,column1, rc,	worker;           // misc 
	
	 // matrix B to be multiplied
	double	in_B[COLA][COLB];           
	
	//To send and receive message
	MPI_Status status;  

	//Intialize MPI
	MPI_Init(&argc,&argv);

	//Get values for taskid and size
	MPI_Comm_rank(MPI_COMM_WORLD,&taskid);	
	MPI_Comm_size(MPI_COMM_WORLD,&numtasks);

	//Note: To run parallely atleast two nodes are required
	if (numtasks < 2 ) 
	{
	  	printf("Need at least two MPI tasks. Quitting...\n");
	  	MPI_Abort(MPI_COMM_WORLD, rc);
	  	return 1;
	}
	  
	numworkers = numtasks-1;


	//*************************** master task-1 ***********************************
	if (taskid == MASTER)
	{

		double	in_A[ROWA][COLA];
		#ifdef PRINT   
			printf("Matrix multiplication has started with %d tasks.\n",numtasks);
		      	printf("Initializing arrays...\n");
		 #endif


		//Intialize matrices in_A & in_B to random number
	     	for (row=0; row<ROWA; row++)
		 	for (column=0; column<COLA; column++)
		   	{ 
			   	#ifdef PRINT
			   	  in_A[row][column]= 1.0; 
			   	#else
			   	  in_A[row][column]= (double)rand();
				#endif
		 	}
		 	
	      	for (row=0; row<COLA; row++)
		 	for (column=0; column<COLB; column++)
		   	{
			   	 #ifdef PRINT
			   	  in_B[row][column]= 1.0; 
			   	#else
			   	  in_B[row][column]= (double)rand();
				#endif
		 	}

		// Distribute matrix data to the worker tasks 
		averow = ROWA/numworkers;
	      	extra = ROWA%numworkers;
	      	offset = 0;
	      	tag = FROM_MASTER;
	      	
	      	for (dest=1; dest<=numworkers; dest++)
	      	{
	      		//Number of rows of matrix in_A to Send to each worker
	      		rows = (dest <= extra) ? averow+1 : averow;   	
	      		#ifdef PRINT	
	      			printf("Sending %d rows to task %d offset=%d\n",rows,dest,offset);
	      		#endif
	      		
	      		MPI_Send(&offset, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
	      		MPI_Send(&rows, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
	      		MPI_Send(&in_A[offset][0],COLA*rows, MPI_DOUBLE, dest, tag,MPI_COMM_WORLD);
			offset = offset + rows;
	      	}
	      	
	}//End of master task-1
	      
	      


	//Broadcast matrix in_B as it is required for all the tasks
	MPI_Bcast(&(in_B[0][0]),COLA*COLB, MPI_DOUBLE, MASTER, MPI_COMM_WORLD);
	




	//*************************** worker task ***********************************
	if (taskid > MASTER)
	{
		//Receive data from master
	 	tag = FROM_MASTER;
	      	MPI_Recv(&offset, 1, MPI_INT, MASTER, tag, MPI_COMM_WORLD, &status);
	      	MPI_Recv(&rows, 1, MPI_INT, MASTER, tag, MPI_COMM_WORLD, &status);
	      
		//Input matrix A and out put matrix C
		double in_A[rows][COLA],out_C[rows][COLB];

		//Receive required data from master
	      	MPI_Recv(&in_A[0][0], COLA*rows, MPI_DOUBLE, MASTER, tag, MPI_COMM_WORLD, &status);
	
		//Compute out_C
	     	for (row=0; row<rows; row++) 
	   		for (column=0; column<COLB; column++)      
	       		{ 
	       			out_C[row][column]=0; 
				for (column1=0; column1<COLB; column1++)
					out_C[row][column] += in_A[row][column1] * in_B[column1][column];
	       		}
	       			
		//Send out_C to master
	      	tag = FROM_WORKER;
	      	MPI_Send(&offset, 1, MPI_INT, MASTER, tag, MPI_COMM_WORLD);
	      	MPI_Send(&rows, 1, MPI_INT, MASTER, tag, MPI_COMM_WORLD);
	      	MPI_Send(&out_C[0][0], rows*COLB, MPI_DOUBLE, MASTER, tag, MPI_COMM_WORLD);
	      	

	}


	//***********************master-2***************
	if(taskid==MASTER)
	{	
		//Resultant matrix	
		double out_C[ROWA][COLB];
	
		//Receive results from worker tasks 
	      	tag = FROM_WORKER;
	      	for (worker=1; worker<=numworkers; worker++)
	      	{
		 	MPI_Recv(&offset, 1, MPI_INT, worker, tag, MPI_COMM_WORLD, &status);
		 	MPI_Recv(&rows, 1, MPI_INT, worker, tag, MPI_COMM_WORLD, &status);
		 	MPI_Recv(&out_C[offset][0], rows*COLB, MPI_DOUBLE, worker, tag,MPI_COMM_WORLD, &status);
		 	printf("Received results from task %d\n",worker);
	      	}
	      	 
		#ifdef PRINT
	 	{     
		 	// Print results  
		 	printf("\n******************************************************\n");
		 	for (row=0; row<ROWA; row++)
		      	{
				printf("\n"); 
			 	for (column=0; column<COLB; column++) 
			    		printf("%6.2f   ", out_C[row][column]);
		      	}
		      
		      	printf("\n******************************************************\n");
		      	printf ("Multiplied using %d process.\n",numtasks);
	 	}  
		#endif

	}
	//End of master task-2


	//Finalize MPI
	MPI_Finalize();
}

