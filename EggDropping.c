#include<stdio.h>
int max(int a,int b)
{
     if(a>b)
    return a;
    else
    return b;
}
int eggDrop(int E,int floors)
{
    int table[E+1][floors+1];
    for(int i=0;i<=floors;i++)//filling the 1st row 
    table[1][i]=i;
    for(int j=1;j<=E;j++) //filling the 0th & 1st column
    {
        table[j][0]=0;
        table[j][1]=1;
    }
    for(int i=2;i<=E;i++) // filling the remaining table starting from 2 bcuz 1st row has been filled
    {
        for(int j=2;j<=floors;j++) //starting from 2 bcuz 0th and 1st column had been filled
        {
            int min=999;    
        for(int k=1;k<=j;k++) //to compare all the floors till 'j'
        {
            int x = max(table[i-1][k-1],table[i][j-k]); // taking the maximum of trails remaining to be done [if the egg broke or if it doesn't]
            if(x<min)//selecting the minimum from the maximum of all floors till 'j'
            { 
            min=x;
            }
        }
        table[i][j]=1+min; //storing the minimum number of trails for that number of floors
        }
    }
    return table[E][floors];
}
void main()
{
    int E,floors;
    printf("Enter the number of Eggs and Floors:");
    scanf("%d %d",&E,&floors);
    int m=eggDrop(E,floors);
    printf("The minimum attempts required %d ",m);
}