#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int i,j,first,last,middle,n,search,array[100000];

	double start; 
	srand(time(NULL));	
	
	printf("Enter no of elements\n");	
	scanf("%d",&n);	
	//	printf("Enter %d integers\n",n);
	
	for(i=0;i<n;i++)
	{	
		int c=0;
		array[i]=rand()%100;
	}
	for(i=0;i<n;i++)
	{		
		printf("%d\t",array[i]);	
	}
	printf("\nElements added !\n");
	
  printf("Enter value to find\n");
   scanf("%d", &search);

	start = omp_get_wtime();
	first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
printf("time consumed= %15.10lf",omp_get_wtime()-start);
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);
 
   return 0;   
}
