#include<stdio.h>
#include<omp.h>

void main ()
{

	int prime[1000],i,j,n;
	int tid;
	int max_threads;

	max_threads = omp_get_max_threads();
	printf("available threads = %d\n",max_threads);

	omp_set_num_threads(max_threads);
	printf("\n In order to find prime no enter value from 1-n : enter n \n");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		prime[i]=1;
	}

	prime[1]=0;

	for(i=2;i*i<=n;i++)
	{
		printf("within for loop i : i= %d\n",i);

		//multithreading to remove multiples of prime no i from the array
		#pragma omp parallel 

		for(j=i*i;j<=n;j=j+i)
		{
			printf("within for loop j: j=%d \n",j);
			if(prime[j]==1)
				prime[j]=0;

			tid = omp_get_thread_num();
			printf("j:%d\t",j);
			printf("i:%d\t",i);
			printf("tid : %d\n",tid);
		}

	}

	printf("\n prime no from 1 to %d are \n",n);

	for(i=2;i<=n;i++)
	{
		if(prime[i] == 1)
		{
			printf("%d\t",i);
		}
	}
printf("\n");
}