#include<stdio.h>
#include<omp.h>

void main()
{
	int max_threads;
	
	max_threads = omp_get_max_threads();
	printf("Available Threads = %d\n",max_threads);

	omp_set_num_threads(max_threads);
	
	#pragma omp parallel 
	{
		int id = omp_get_thread_num();
		int tot = omp_get_num_threads();
		printf("Hello world by thread = %d out of %d\n",id,tot);
	}
}
