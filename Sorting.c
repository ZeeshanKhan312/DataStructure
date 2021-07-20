//CODE FOR SORTING ELEMENTS USING BUBBLE/INSERTION/SELECTION
#include<stdio.h>
int bubble(int n, int arr['n'])
{
	for (int i = 1; i < n; i++)//for no of pass
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}
int insert(int n,int arr['n'])
{
	for (int i = 1; i < n; i++)//for no of pass
	{
		int temp, j;
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
	return arr;
}
int selection(int n, int arr['n'])
{
	for (int i = 0; i < n-1; i++)//for no of pass
	{
		int min = i;
		for (int j = i+1; j < n ; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		int temp;
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	return arr;
}
void main()
{
	int n,ch;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int arr['n'];
	for (int i = 0; i < n; i++)//inserting the element
	{
		printf("Enter the Number: ");
		scanf("%d", &arr[i]);
	}
	printf("Choose the method to do the sorting:\n1.Bubble sort\n2.Insertion sort\n3.Selection Sort\n");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1://Bubble Sort
		arr[n] = bubble(n, arr);
		break;
	case 2://Insertion SORT
		arr[n] = insert(n, arr);
		break;
	case 3://Selection Sort
		arr[n] = selection(n, arr);
		break;
	default:printf("Error..!");
		exit(1);
	}
	printf("Number after sorting:\n");
	for (int i = 0; i < n; i++)//displaying the element
		printf("%d ", arr[i]);
}