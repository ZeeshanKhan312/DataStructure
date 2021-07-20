#include <stdio.h>
void merge(int arr[], int start, int mid, int end)
{
	int i, j, k,arr2[100];
	i = start;
	j = mid+1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			arr2[k] = arr[i];
			i++;
		}
		else
		{
			arr2[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid || j <= end)
	{
		if (i <= mid)
		{
			arr2[k] = arr[i];
			i++;
			k++;
		}
		else 
		{
			arr2[k] = arr[j];
			j++;
			k++;
		}
	}
	for (k = start; k <= end; k++)
	{
		arr[k] = arr2[k];
	}
}
void mergesort(int arr[], int i, int j)
{
	if (i < j)
	{
		int mid = (i + j) / 2;
		mergesort(arr, i, mid);
		mergesort(arr, mid + 1, j);
		merge(arr, i, mid, j);
	}
}
void main()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int arr['n'];
	for (int i = 0; i < n; i++)//inserting the element
	{
		printf("Enter the Number: ");
		scanf("%d", &arr[i]);
	}
	mergesort(arr, 0, n);//Merge Sortion
	printf("Number after sorting:\n");
	for (int i = 0; i < n; i++)//displaying the element
		printf("%d ", arr[i]);
}