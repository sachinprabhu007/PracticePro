#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void initVector(int vector[], const int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        vector[i] = rand() % 100 + 1;
}

void printVector(int vector[], const int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", vector[i]);
    printf("\n");
}

int countOfNine(int vector[], const int n)
{
    int count = 0;
    omp_set_num_threads(4);
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        if (vector[i] % 9 == 0)
        {
        #pragma omp atomic
            count++;
        }
    }
    return count;
}

int main()
{
    const int N = 30;
    int a[N];
    initVector(a, N);
    printVector(a, N);
    printf("count = %d\n", countOfNine(a, N));
    return 0;
}

/*

29 52 99 40 79 53 63 71 1 73 74 28 53 8 33 10 71 18 77 24 7 53 75 79 97 14 45 15 42 75 
count = 4

41 9 33 39 94 82 92 24 86 59 65 59 58 31 93 40 63 31 75 98 82 14 14 44 17 82 95 31 41 64 
count = 2

57 12 68 66 19 53 57 100 21 41 2 21 41 63 15 23 91 14 43 34 13 93 100 71 94 92 56 96 73 15 
count = 1

56 28 11 18 54 51 95 66 98 43 84 23 29 72 34 54 96 98 23 28 27 52 55 29 96 1 85 36 23 34 
count = 6

*/