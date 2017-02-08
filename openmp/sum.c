#include<stdio.h>
#include<omp.h>
#define size 100
void main(){
	int sum=0,expected=0;
	omp_set_num_threads(5);
	#pragma omp parallel
	{
		int i,tid=omp_get_thread_num();
		int nthreads=omp_get_num_threads();
		for(i=tid;i<size;i+=nthreads)
		{
			#pragma omp atomic
			sum+=i;
		}
		printf("in thread %d sum = %ld\n",tid,sum);
		
	}
	expected=((size)*(size-1))/2;
	printf("Expected sum : %ld",expected);
	printf("Parallel sum : %ld",sum);
}
