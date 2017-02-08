#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<omp.h>
 
int main()
{
  int m, n, p, q, c, d, k, sum = 0;
  clock_t tic,toc;
  double start=0,end=0;
  int first[100][100], second[100][100], multiply[200][200];
 
  printf("Enter the number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
//  printf("Enter the elements of first matrix\n");
 srand(time(NULL));
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
	first[c][d] = rand();
      //scanf("%d", &first[c][d]);
 
  printf("Enter the number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);
 
  if (n != p)
    printf("Matrices with entered orders can't be multiplied with each other.\n");
  else
  {
//    printf("Enter the elements of second matrix\n");
 
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
	second[c][d] = rand();
        //scanf("%d", &second[c][d]);

//start = omp_get_wtime();
 tic = clock();

 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
//end = omp_get_wtime();
 
toc = clock();

/*#pragma omp parallel shared
{
#pragma omp for schedule(static)
	  for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
		
	}
}
		
*/
}
/*    printf("Product of entered matrices:-\n");
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);
 
      printf("\n");
    }*/
//printf("Elapsed time : %15.10f seconds\n",(double)(toc-tic)/CLOCKS_PER_SEC); 
  //    printf("Elapsed time : %15.10f seconds\n",end-start); 
return 0;

  }

  
