#include <stdio.h>
void main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    int arr['n'];
    int i = 0;
    for(i;i<n;i++)
    {
        printf("Enter the number \n");
        scanf_s("%d",&arr[i]);
    }
    int x,element_found=0;
    printf("Enter the number to check\n");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
    if(x==arr[i])
        element_found=1;
    }
    if(element_found)
    printf("Element found");

    else
        printf("Element not found");

}