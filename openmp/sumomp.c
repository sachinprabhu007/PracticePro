#include<stdio.h>
#include<omp.h>
#define size 100
void main()
{
	long *array,expected_sum=0;
	int max_threads=0,nthreads=0;
	long sum = 0;
	
	// allocate memory and initialize

	omp_set_num_threads(4);
	printf("sum=%ld\n",sum);
	#pragma omp parallel
	{	
		
		int cnt,tid = omp_get_thread_num();	
		int nthreads = omp_get_num_threads();
		for(cnt=tid;cnt<size;cnt+=nthreads)
		{
			#pragma omp atomic
			sum+= array[cnt];
	printf("sum=%ld\n",sum);

		}
	printf(" In thread %d sum = %ld\n",tid,sum);
	}
	expected_sum = ((size)*(size-1))/2;
	printf("%ld is the sum of the fist %d numbers, calculated by %d threads\n",sum,size,nthreads);
	printf("\n\n Expected sum is %ld\n\n",expected_sum);
	
}
