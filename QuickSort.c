#include <stdio.h>
int partition(int arr[], int start, int end)
{
    int i=start;
    int pivot=arr[start];
    int temp;
    while (start < end)
    {
        while (arr[start] <= pivot)  
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)  //swapping the two Number
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    //placing the pivot element at right pos. & return it's loc
    arr[i] = arr[end]; 
    arr[end] = pivot;
    return end;
}
void quickSort(int A[], int i, int j)
{  
    if (i < j)
    {
        int loc; // Location of pivot after partition
        loc = partition(A, i, j);
        quickSort(A, i, loc - 1);  // sort left subarray 
        quickSort(A, loc + 1, j); // sort right subarray
    }
}
void main()
{
    int arr[]={6,17,9,2,4};
    int n=5;
    quickSort(arr, 0, n - 1);//Quick Sortion
	printf("Number after sorting:\n");
	for (int i = 0; i < n; i++)//displaying the element
		printf("%d ", arr[i]);
}
