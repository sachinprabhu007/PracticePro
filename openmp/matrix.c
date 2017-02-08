#include<stdio.h>
#include<omp.h>
#include<time.h>
#define size  100

int a[size][size];
int b[size][size];
int c[size][size];
clock_t start,stop;
int i,j,m,n,p,q;
//double start=0,stop=0;
int main()
{


printf("Enter the number of rows and columns of first matrix\n");
scanf("%d%d", &m, &n);


	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		{
			a[i][j]=1;
		}
	}

/*for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
printf("\n");
	}
*/

printf("Enter the number of rows and columns of second matrix\n");
scanf("%d%d", &p, &q);

	for(i=0;i<p;i++){
		for(j=0;j<q;j++)
		{
			b[i][j]=2;
		}
	}
/*printf("====\n");
for(i=0;i<p;i++){
		for(j=0;j<q;j++)
		{
			printf("%d\t",b[i][j]);
		}
printf("\n");
	}
printf("**\n");
*/

//	start=clock();

start = omp_get_wtime();

#pragma omp parallel 
for(int i=0;i<m;i++){
	for(int j=0;j<q;j++){
		for(int k=0;k<p;k++){
			c[i][j] += a[i][k]*b[k][j];		
		}
	}
}
//stop = omp_get_wtime();
stop=clock();

//printf("Elapsed time : %15.10f seconds\n",(double)(stop-start)/CLOCKS_PER_SEC);
//printf("Elapsed  time : %15.10f seconds\n",stop-start);
/*for(	int i=1;i<5;i++)
{
	for(int j;j<5;i++)
	{
		printf("%d\t",c[i][j]);
	}
	printf("\n");
}*/ 
return 0;
}
