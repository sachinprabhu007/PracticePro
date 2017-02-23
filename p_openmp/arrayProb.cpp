#include<iostream>
#include<omp.h>

using std::cout;
using std::endl;

// This program fills an array from 0 -> N-1, then adds up the entries
// i.e. sum = 0 + 1 + ... + N-1 
// Then waits for the threads to syncrohnize and then adds one
// NOTE:  Parallel answer will be +1 of the serial answer

int main()
{
	int N = 10;
	int * x = new int[N];
	double sum = 0.0;	

	#pragma omp parallel shared(x)
	{
		// It will still work without schedule, but prints wont be nice
		#pragma omp for schedule(static,5)
		for(int i = 0; i < N; i++)
		{
			#ifdef _OPENMP
			cout << "Thread id = " << omp_get_thread_num() 
			     << " itr = " << i << endl;
			#endif 
			x[i] = i;
		}
		
		#pragma omp barrier
		// Make sure all threads are done
		
		#pragma omp for reduction(+:sum)
		for(int i = 0; i < N; i++)
		{
			sum = sum + x[i];
		}
	
		#pragma omp atomic
		sum += 1;	
	}

	for(int i = 0; i < N; i++)
		cout << x[i] << endl;
	
	cout << "sum = " << sum << endl;
	return 0;
}

/*
output:
Thread id = Thread id = 01 itr = 0 itr = 5
Thread id = 0 itr = 1
Thread id = 0 itr = 2
Thread id = 0 itr = 3
Thread id = 0 itr = 4

Thread id = 1 itr = 6
Thread id = 1 itr = 7
Thread id = 1 itr = 8
Thread id = 1 itr = 9
0
1
2
3
4
5
6
7
8
9
sum = 49

*/
		
