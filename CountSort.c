#include<stdio.h>
void countsort(int arr[], int n)
{
	int k = 0, i;
	for (i = 0; i <= n; i++)
	{
		if (arr[i] > k)
			k = arr[i];
	}
	int m = k;
	int count['m'] = { 0 };
	for (i = 0; i < n; i++)
	{
		k = arr[i];
		count[k] += +1;
	}
	k = m;
	for (i = 1; i <= k; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	int b['n'];
	for (i = n - 1; i >= 0; i--)
	{
		b[--count[arr[i]]] = arr[i];
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = b[i];
	}
}
void main()
{
	int n, i;
	printf("Enter the number of element: ");
	scanf("%d", &n);
	int arr['n'];
	for (i = 0; i < n; i++)
	{
		printf("Enter the Number:");
		scanf("%d", &arr[i]);
	}
	countsort(arr, n);
	printf("The Number's after sorting:");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}