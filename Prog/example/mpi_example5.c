/********************************************************************************
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  ::mpi_example5.c						*
*	Description :: Ring Topology						*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/

#include<stdio.h>
#include<mpi.h>

void main(int argc,char* argv[])
{
	int rank,size,val,expectedval;
	
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	
	if(rank==0)
	{
		val=9;
		expectedval=val+(size-1);
		//send to process 1
		MPI_Send(&val,1,MPI_INT,1,rank+1,MPI_COMM_WORLD);
		printf("%d: Val=%d sent to process %d\n",rank,val,rank+1);
			
	}

	// Receive value from previous process
	if(rank!=0)
	{
		MPI_Recv(&val,1,MPI_INT,rank-1,rank,MPI_COMM_WORLD,&status);
		printf("%d: Received %d from rank = %d\n",rank,val,rank-1);
		
		//increment the value received
		val=val+1;

		MPI_Send(&val,1,MPI_INT,(rank+1)%size,rank+1,MPI_COMM_WORLD);
		printf("%d: sent %d to rank = %d\n",rank,val,(rank+1)%size);
	}

	//Receive value from last process
	if(rank==0)
	{
		MPI_Recv(&val,1,MPI_INT,size-1,size,MPI_COMM_WORLD,&status);
		printf("%d: Received %d from rank = %d \n",rank,val,size-1);
		if(val==expectedval)
			printf("%d: Final Value(%d) Matched with Expected Value(%d)\n",rank,val,expectedval);
	}

	MPI_Finalize();	

}//end of main
