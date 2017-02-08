#include<omp.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
	int tid,nthreads;
	#pragma omp parallel 
	{
		tid = omp_get_thread_num();
		nthreads = omp_get_num_threads();
	
		printf("hi from thread = %d out of %d\n",tid,nthreads);

		
	}
	printf("\n outside  : nthreads = %d\n",nthreads);
		
}
