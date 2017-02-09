#include<stdio.h>
#include<omp.h>

void main()
{
#pragma omp parallel sections num_threads(3)
{
	#pragma omp section
	{
		int tid;
		tid = omp_get_thread_num();
		printf("x -- Thread : %d hello world \n",tid);
	}

	#pragma omp section
	{
		int tid;
		tid = omp_get_thread_num();
		printf("y -- Thread : %d hello world \n",tid);
	}

	#pragma omp section
	{
		int tid;
		tid = omp_get_thread_num();
		printf("z -- Thread : %d hello world \n",tid);
	}
	

}
}
