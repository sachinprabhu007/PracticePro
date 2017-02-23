#include<stdio.h>
#include<omp.h>


int main()
{

	int N =10;

	#pragma omp parallel for schedule(dynamic,1)	
	for(int i = 0; i < N; i++)
	{
		printf("Thread %i, itr = %i \n", omp_get_thread_num(), i);
	}

	return 0;
}
/*
Thread 0, itr = 3 
Thread 0, itr = 4 
Thread 0, itr = 5 
Thread 0, itr = 6 
Thread 0, itr = 7 
Thread 0, itr = 8 
Thread 0, itr = 9 
Thread 3, itr = 1 
Thread 2, itr = 2 
Thread 1, itr = 0 

*/
