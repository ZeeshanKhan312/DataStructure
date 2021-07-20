#include<stdio.h>
void main()
{
    int n;
    printf("Enter the max job:");
    scanf("%d",&n);
    int profit[n];
    int deadline[n];
    int preference[n];
    int max;
    for(int i=0;i<n;i++)
    {
           printf("Enter the profit and Deadline of Job %d : ",(i+1));
           scanf("%d %d",&profit[i],&deadline[i]);
           preference[i]=0;
    }
    for(int i=0;i<n-1;i++)//sorting in decreasing order of profit
    {
        max=i;
        for(int j=i+1;j<n;j++)
        {
        if(profit[max]<profit[j])
        {
            max=j;
        }
        }
        int x=profit[max];
        int y=deadline[max];
        profit[max]=profit[i];
        deadline[max]=deadline[i];
        profit[i]=x;
        deadline[i]=y;
    }
    //now finding the prefernce according to deadline
   for(int i=0;i<n;i++)
    {
        while(deadline[i]>=1)
        {
        if(preference[deadline[i]-1]==0)
        {
            preference[deadline[i]-1]=profit[i];
            break;
        }
        deadline[i]--;
        }
    }
    for(int k=0;k<n;k++)
    {
        printf("Job with %d profit\n",preference[k]);//if 0 profit that means empty slot
    }
}