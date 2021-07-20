 #include<stdio.h>
int minmax(int arr[], int* min, int* max)
{
	*min = *max = arr[0];
	int i;
	for (i = 0; i < 16; i++)
	{
		if (arr[i] > * max)
			*max = arr[i]; 
		if (arr[i] < *min)
			*min = arr[i];
	}
	return 0;
}
 void main()
 {
	 int arr[] = { 244,45,67,768,8,966,544,33,23,56,10002,-3,45,-34,-98,56 };
	 int  min, max;
	 minmax(arr, &min, &max);
	 printf("min=%d \nmax=%d", min, max);
 }