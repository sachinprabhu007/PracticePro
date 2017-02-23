/*#include<iostream>
#include<omp.h>

using std::cout;
using std::endl;

int main()
{
	int N = 10;

	double * x = new double[N];

	#pragma omp parallel
	{
		
		int len = (N)/( omp_get_num_threads() );
		int rank = omp_get_thread_num();

		#pragma omp for
		for(int i = rank*len; i < (rank+1)*len; i++)
		{
			cout << "Thread id = " << omp_get_thread_num()
			     << " Itr = " << i << endl;
			x[i] = i;		
		}
	}


	return 0;
}*/

#include<stdio.h>
#include<omp.h>

int main()
{
	int N=10;
	double x[10];
	
	#pragma omp parallel 
	{
		int len = (N)/( omp_get_num_threads() );
		int rank = omp_get_thread_num();

		#pragma omp for
		for(int i = rank*len; i < (rank+1)*len; i++)
		{
			printf("Thread id = %d , Itr = %d ",omp_get_thread_num(),i);
			x[i] = i;		
		}
	}	
	return 0;
}
