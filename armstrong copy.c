#include <stdio.h>
void main()
{
	int n, r, c, sum , temp, x, cnt, count ;
	printf("Enter the last number\n");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		x = i;
		count = 0;
		while (x > 0)
		{
			x = x / 10;
			count++;
		}
		r = 0;
		sum = 0;
		temp =i ;
		while (i > 0)
		{
			cnt = count;
			c = 1;
			r = i % 10;
			while (cnt > 0)
			{
				c *= r;
				cnt--;
			}
			sum += c;
			i = i / 10;
		}
		i = temp;
		if (i == sum)
			printf("Armstrong Number=%d\n",i);
	}
}