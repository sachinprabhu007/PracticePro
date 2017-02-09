#include<stdio.h>
#include<omp.h>
#include<math.h>

void main()
{
	int sep[20],array[20],key,i,j,n,left,right,size,interval,index,break_value=0,tid;

	printf("Enter the size of array\n");
	scanf("%d",&size);

	printf("Enter the elements in ascending order\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}

	printf("Enter the key to be searched\n");
	scanf("%d",&key);

	printf("Enter the value of n for n-ary search algo\n");
	scanf("%d",&n);

	left=0;
	right=size-1;

	if(key>=array[left] && key<=array[right])
	{
		while(left!=right)
		{
			//find sep start

			printf("left = %d , right=%d, size=%d\n",left,right,size);
			if(size<=n)
			{
				#pragma omp parallel for num_threads(size)
				for(i=0;i<size;i++)
				{
					sep[i] = left+i;
					tid = omp_get_thread_num();
					printf("Thread %d allocated sep[%d] = %d\n",tid,i,sep[i]);
				}
			}
			else
			{
				sep[0]=left;
				interval = ceil((float)size/(float)n);
			}

			#pragma omp parallel for num_threads(n-1)

			for (i=1;i<=n;i++)
			{
				sep[i]=left+interval*i-1;
				tid = omp_get_thread_num();
				printf("Thread %d allocated sep[%d] =%d\n",tid,i,sep[i]);
			}

			sep[n] = right;
		
		//end - code to find sep

		//start - code for comparison

		for(int i=0;i<=n;i++)
		{
			if(key == array[sep[i]])
			{
				index=sep[i];
				printf("Element found at pos = %d\n",index+1);
				break_value=1;
				break;
			}
			if(key<array[sep[i]])
			{
				right = sep[i];
				if(i!=0)
					left = 1+sep[i-1];
				size = right-left+1;
				break;
			}
		}
		//end of comparison

		if(break_value==1)
			break;
		}
	}

	

	if(left == right || !(key >= array[left]) && key<=array[right])
		printf("Element does not present in the list\n");

}