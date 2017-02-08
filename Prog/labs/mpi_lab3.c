/********************************************************************************
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  ::mpi_lab3.c							*
*	Description :: Ring Topology						*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/

#include<stdio.h>
#include<mpi.h>

void main(int argc,char* argv[])
{
	//Declare variables for rank,size,value to be sent,expected value
	
	MPI_Status status;
	//Initialize MPI
	MPI_Init(&argc,&argv);
	//Get number of processes
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	//Get process number
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	//Initialize value to be sent
	if(rank==0)
	{
		//send value to process 1
		//MPI_Send(void* data, int count, MPI_Datatype datatype, int destination,int tag, MPI_Comm communicator)	
	}

	// Receive value from previous process
	if(rank!=0)
	{
		//Receive value from previous process
		//MPI_Recv(void* data, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm communicator, MPI_Status* status)
		//increment the value received

		//send incremented value to the next process
	}

	//Receive value from last process by first process
	if(rank==0)
	{
		//Receive value from last process

		//Check if received value is matched with expected value
	}

	//Finalize the MPI Communication
	MPI_Finalize();	

}//end of main
