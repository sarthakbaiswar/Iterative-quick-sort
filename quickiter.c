/*
DATE: 11-11-2017
AUTHOR NAME: SARTHAK BAISWAR
AIM:  06.Write a C program to include non-recursive routines to implement a quick sort.
      It would be desirable if the pivot position is decided by user.
      Include basic utility routines to create and display the list.
*/


#include <stdio.h>
#include<stdlib.h>
#include"quickiter.h"
#include"arr_quick.h"

#define maxsize 50
#define minvalue -999

int main()
{
    int arr[maxsize];
    int copy[maxsize];
    initialize(arr);
    initialize(copy);
    int len = 0;

    printf("\t(Enter -999 to end)\n");
    create( arr, len);
    len=arrlength(arr);
    copy_arr(arr, copy, len);
    printf("Number of elements are %d\n",len);
    printf("--------------------------------\n");
    int pivot_index;
    int cont;

    do{
      printf("Before sorting:\t");
      display(arr, len);
      printf("\n");
      printf("--------------------------------\n");
      printf("Number of elements are %d\n",len);
      printf("--------------------------------\n");

      quickSortIter_user_pivot ( arr, 0, len-1, len );
      printf("---------------------------------\n");

      printf("After sorting:\t");
      display(arr, len);
      printf("\n");
      printf("---------------------------------\n");

      copy_arr(copy, arr, len);
      printf("\nDo you want to continue with another pivot index:\n");
      scanf("%d",&cont);
  }while(cont!=0);
}
