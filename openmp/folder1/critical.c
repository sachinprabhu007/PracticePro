#include<stdio.h>
#include<omp.h>

void main()
{
	int x=0;	
	#pragma omp parallel num_threads(300)
	{
		x=x+1;
	}

	printf("x=%d\n",x);
}
