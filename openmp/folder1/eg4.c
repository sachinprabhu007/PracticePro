#include <stdio.h>
#include <omp.h>

void read(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int main()
{
    const int N = 5;
    int a[N], b[N];
    int amin, amax,bmin,bmax;

    printf("Enter for a\n");
    read(a, N);
    printf("Enter for b\n");
    read(b, N);

    omp_set_num_threads(5);

    #pragma omp parallel 
    {

        if (omp_get_thread_num() == 0)
        {
            amin = a[0];
            for(int i = 0; i < N; i++)
            {
                if (a[i] < amin)
                    amin = a[i];
            }
            amax=a[0];
            for(int i=0;i<N;i++)
            {
                if(a[i]>amax)
                    amax = a[i];
            }
        }
        else
        {


            bmin = b[0];
            for(int i = 0; i < N; i++)
            {
                if (a[i] < bmin)
                    bmin = b[i];
            }
            bmax = b[0];
            for(int i = 0; i < N; i++)
            {
                if (b[i] > bmax)
                    bmax = b[i];
            }
        }
    }

    printf("a min = %d , a max = %d\n",amin,amax);
    printf("a min = %d; b max = %d\n", bmin, bmax);

    return 0;
}
