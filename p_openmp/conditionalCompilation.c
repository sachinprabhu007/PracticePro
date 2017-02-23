#include<stdio.h>
#include<omp.h>

int main()
{

	printf("Hello world!!\n");

	#pragma omp parallel
	{
		// NOTE THIS NOTE AN ifndef just and ifdef

		#ifdef _OPENMP
			printf("Hello from core %i \n", omp_get_thread_num() );
		#endif
	}
 	return 0;
}

/*

output :
Hello world!!
Hello from core 0 
Hello from core 2 
Hello from core 3 
Hello from core 1 

*/
