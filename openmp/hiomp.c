#include<stdio.h>
#include<omp.h>

void main()
{
	//parallel code here
	#pragma omp parallel 
	{
		printf("No of processors : ",omp_get_num_procs(),"\n");
		int tid;
		tid = omp_get_thread_num();
		printf("Thread %d : Hello Welcome to parallel world \n",tid);
	}
}
