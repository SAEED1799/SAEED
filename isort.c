#include <stdio.h>
#include "isort.h"
#define size_arr 50

void shift_element(int* arr,int i)
{
		int counter=1;
		int current=*arr,save_next;
		for(;counter<=i;counter++)//Count shifting to the right side of the array
		{
			
			save_next=*(arr+1);
			*(arr+1)=current;
			current=save_next;	
			arr++;
		}
}
void insertion_sort(int*arr,int len)
{
	int i,key,j;
	for(i=1;i<len;i++)
	{
		int count_shifts=0;
		key=*(arr+i);
		j=i-1;
		while(j>=0&&*(arr+j)>=key)
		{
			count_shifts++;
			j--;
		}	
		shift_element(arr+j+1,count_shifts);
		*(arr+j+1)=key;
	}
	
}

void PrintArr(int*arr,int len)
{
	int i;
	for(i=0;i<len-1;i++)
	{
		printf("%d,",*(arr+i));
	}
	printf("%d",*(arr+i));
	printf("\n");
}

int main(int argc, char **argv)
{
	int i;
	int arr[size_arr]={0};
	printf("Please enter %d values -->\n",size_arr);
	for(i=0;i<size_arr;i++)
	{
		scanf("%d",arr+i);
	}
	insertion_sort(arr,size_arr);
	PrintArr(arr,size_arr);
	printf("all numbers are now sorted!\n\n");

	return 0;
}
