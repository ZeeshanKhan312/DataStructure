#include<stdio.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Heapify(int arr[], int n,int i)
{
	int  largest=i;
		int l = (2 * i) + 1;
		int r = (2 * i) + 2;
		if(l < n && arr[largest] < arr[l])
			largest = l;
		if(r < n && arr[largest] < arr[r])
			largest = r;
		if (largest != i)
		{
			swap(&arr[largest], &arr[i]);
			Heapify(arr, n, largest);
		}
}
void main()
{
	int n, i;
	printf("Enter the size of array:");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the Numbers:");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = (n-1)  / 2; i >= 0; i--)//to form a MAX Heap tree
	{
		Heapify(arr, n, i);
	}
	for (i = n-1; i >= 0; i--)//to sort it using Heapify
	{
		swap(&arr[0], &arr[i]);//bringing the highest numer at the last and fixing it position.
		Heapify(arr, i, 0);
	}
	printf("Number after sorting:");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
}