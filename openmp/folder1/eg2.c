#include <stdio.h>
#include <omp.h>


void runp(int threads_count)
{
    omp_set_num_threads(threads_count);
    printf("You set threads count eql %d\n", threads_count);
    #pragma omp parallel if (threads_count > 1)
    if (omp_in_parallel())
    {
        printf("multi threads: threads count = %d; current threas number = %d\n", omp_get_num_threads(), omp_get_thread_num());
    }
}

int main()
{
    runp(3);
    runp(1);
    return 0;
}