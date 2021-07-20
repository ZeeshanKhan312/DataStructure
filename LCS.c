#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    return a>b?a:b;
}
void main()
{
    char str1[20],str2[20];
    printf("Enter the two strings:\n");
    scanf("%s %s",str1,str2);
    int a=strlen(str1),b=strlen(str2);//storing the size of string
    int LCS[a+1][b+1];  //+1 bcuz array will go from 0 till n
    int i,j;
    for(int i=0;i<a+1;i++)
    {
        for(int j=0;j<b+1;j++)
        {
            if(i==0||j==0)
            LCS[i][j]=0;
            else if(str1[i-1]==str2[j-1])
            {
               // printf("%c",str1[i-1]);
                LCS[i][j]=1+LCS[i-1][j-1];
            }
            else
            LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    i=a;j=b;
    while(LCS[i][j]!=0)
    {
        if(LCS[i][j]!=LCS[i][j-1])
        {
            printf("%c ",str2[j-1]);
            i--;j--;
        }
        else
        j--;
    }
    printf("\n%d",LCS[a][b]);
}