#include<stdio.h>
int gcd(int n, int k)
{
	if (k == 0)
		return n;
	else
		return gcd(k, n % k);
}
void main()
{
	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
	int k,x,j,temp;
	scanf("%d", &k);
	x= gcd(9, k);//to find the greatest common divisor
	int d=-1;
	for (int i = 0; i < x; i++)
	{
		temp = arr[i];
		j = i;
		while (1)
		{
			d = (j + k) % 9;
			if (d == i)
			{
				break;
			}
			arr[j] = arr[d];
			j = d;
		}
		arr[j] = temp;
	}
	for (int i = 0; i < 9; i++)
		printf("%d ",arr[i]);
}