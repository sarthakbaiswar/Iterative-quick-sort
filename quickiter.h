#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define maxsize 50
#define minvalue -999

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int beg, int end, int pivot_index)
{
	long int pivot_value;
	int i = beg - 1;
	int j;
	pivot_value = arr[pivot_index];
	swap(&arr[pivot_index],&arr[end]);
	for(j=beg;j<end;j++)
	{
		if(arr[j]<pivot_value)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[end]);
	return i+1;
}

void quickSortIter_user_pivot (int arr[], int beg, int end, int len)
{
		int top = -1;
		int stack[ maxsize ];
		stack[++top] = beg;
		stack[++top] = end;
		int j = beg;
		int k = end;
		int pivot_index;
		while( top >= 0 )
		{
				end = stack[top--];
				beg = stack[top--];
				if( j == beg && k == end )
				{
					do{
		        printf("Enter a value for pivot index(  starting from 0 )\n");
		        scanf("%d",&pivot_index);
		      }while(pivot_index>len-1);
				}
				else
				{
					srand(time(0));
			  	pivot_index = beg + rand()%(end - beg + 1);
				}
				{
					int p = partition(arr, beg, end, pivot_index);
					if( p-1 > beg )
					{
						stack[++top] = beg;
						stack[++top] = p-1;
					}
					if( p+1 < end )
					{
						stack[++top] = p+1;
						stack[++top] = end;
					}
				}
				//display
				int i;
				printf("Iterations:\n");
				for (i = 0; i <len; i++)
				{
					if(arr[i]!=minvalue)
					printf("%d ", arr[i]);
				}
				printf("\n");
		}
}
