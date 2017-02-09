    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>
    #include <omp.h>


     

    void mergeSort(int [], int, int, int);

    void partition(int [],int, int);

      
     double start,stop;
    int main()

    {

        int list[10000];

        int i, size;

       
        
        srand(time(NULL));

     

        printf("Enter total number of elements:");

        scanf("%d", &size);

        
       for(i=0; i<size; i++)
        {
          list[i] = rand()%10000;
        }  

        printf("Elements added !! ");

        partition(list, 0, size - 1);

        printf("After merge sort:\n");

        for(i = 0;i < size; i++)

        {

             printf("%d  ",list[i]);

        }
        printf("\n");

        printf("Elapsed time =%15.10f ",stop-start);
     

       return 0;

    }

     

    void partition(int list[],int low,int high)

    {

        int mid;

      

        if(low < high)

        {

            mid = (low + high) / 2;

            start = omp_get_wtime();

            #pragma omp parallel sections num_threads(2) 
            {
                #pragma omp section
                {
                partition(list, low, mid);
                }

                #pragma omp section
                {
                partition(list, mid + 1, high);
                }

                #pragma omp section
                {   
                mergeSort(list, low, mid, high);
                }
            }


        }
        stop = omp_get_wtime();


    }

     

    void mergeSort(int list[],int low,int mid,int high)

    {

        int i, mi, k, lo, temp[10000];

     

        lo = low;

        i = low;

        mi = mid + 1;

        while ((lo <= mid) && (mi <= high))

        {

            if (list[lo] <= list[mi])

            {

                temp[i] = list[lo];

                lo++;

            }

            else

            {

                temp[i] = list[mi];

                mi++;

            }

            i++;

        }

        if (lo > mid)

        {

            for (k = mi; k <= high; k++)

            {

                temp[i] = list[k];

                i++;

            }

        }

        else

        {

            for (k = lo; k <= mid; k++)

            {

                 temp[i] = list[k];

                 i++;

            }

        }

     

        for (k = low; k <= high; k++)

        {

            list[k] = temp[k];

        }

    }