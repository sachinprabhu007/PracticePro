#include<stdio.h>
#include<omp.h>
int c=0;
void foo(int threadID)
{
printf("\n=========+Function foo+==========\n");
	printf("\n Thread in foo %d",threadID); 
}

void foo1(int id,int a[])
{
printf("\n=========+Function foo1+==========\n");
	int i;
	printf("\n Thread in foo1 %d \n",id);
	for(i = 0;i<5;i++)
	{
		//a[i]=c++;
		a[i]=id;
		printf("a[%d] = %d\t",i,a[i]);
	}	
}

void main()
{
int array[5];
	printf("=========+This is parallel program+==========");
	#pragma omp parallel 
	{
		int threadID ;
		threadID = omp_get_thread_num();
		foo(threadID);
		printf("\n Thread in main %d ",threadID);
		foo1(threadID,array);	
	}
printf("\n end of threads\n");
}
