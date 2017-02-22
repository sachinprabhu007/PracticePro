#include<stdio.h>
#include<omp.h>

int fib(int n)
{
	if(n<2) return n;
	int x,y;
#pragma omp task shared(x)
	x = fib(n-1);
#pragma omp task shared(y)
	y = fib(n-2);
#pragma omp taskwait
	return x+y;
}

int fact(int n)
{
	int x,y;

	if(n==0) return 1;
	else 
	if(n==1) return 1;
	else 
	{
	#pragma omp task shared(x);
	x = fact(n-1);
	
	#pragma omp taskwait
	return n*x;
	/*
		#pragma omp task shared(x)
		x = fact(n-1);
		#pragma omp task shared(y)
		y = fact(n);
	#pragma omp taskwait
	return x*y;*/
	}

}
void main()
{
int n;
int res;
printf("Enter value for n\n");
scanf("%d",&n);

res = fact(n);

printf("factorial of %d is = %d\n",n,res);

}
