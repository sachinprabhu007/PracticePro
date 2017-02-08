#include<stdio.h>
#include<omp.h>

int tid,i,nthreads;
float dot_prod(int *a,int *b,int N)
{
	int sum = 0.0;
	
	printf("\nin func\n");
	tid = omp_get_thread_num();
	
		for(i=0;i<N;i++)
	{
			sum+= a[i] * b[i];
	printf("tid =%d sum = %d\n",tid,sum);
	nthreads=omp_get_num_threads();
	}	
printf("no of threads=%d\t",nthreads);

return sum;
}

int foo(int *a,int *b,int N)
{
	int sum=1;
	 omp_set_num_threads(4);
	
	#pragma omp parallel for reduction(*:sum) 
		
		for(i=0;i<N;i++)
		{
			sum *= a[i] * b[i];
			printf("tid =%d sum = %d\n",omp_get_thread_num(),sum);
		}

return sum;	
}
void main()
{
	
	int a[10],b[10],result;
	for(i=0;i<10;i++)
	{
		a[i]=1;
		b[i]=2;
	}
	printf("[");
	for(int i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("]");

	printf("\n");
	printf("[");
		for(int i=0;i<10;i++)
	{
		printf("%d\t",b[i]);
	}
	printf("]");

//	result = dot_prod(a,b,9);
	result = foo(a,b,10);
	printf("result = %d\n",result);
	
}
