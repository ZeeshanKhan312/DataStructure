#include<stdio.h>
void main()
{
    int n;
    printf("Enter the last No\n");
    scanf("%d", &n);
    int i, j, k;
    for (i = n / 2; i <= n; i += 2)
    {
        for (j = 1; j < n - i; j += 2)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("*");
        }
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (i = n; i >= 1; i--)
    {
        for (j = i; j < n; j++)
        {
            printf(" ");
        }
        for (k = 1; k <= (i * 2) - 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}