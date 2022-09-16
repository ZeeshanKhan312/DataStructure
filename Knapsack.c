//Knapsack Fractional && Knapsack 0-1 (used to find the best soln for max. profit)
#include <stdio.h>
struct item{
    int wt;
    int pr;
};
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void knapsack_nf(struct item item[],int n,int W)//0-1 Knapsack
{
    int i, j;
    int K[n + 1][W + 1]; // +1 bcuz array will start from 0 and go to 'n'
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (item[i - 1].wt <= j) //wt[i-1] bcuz wt[] & pr[] array goes till 'n-1'
                K[i][j] = max(item[i - 1].pr + K[i - 1][j - item[i - 1].wt], K[i - 1][j]); //compairing with the previous row of the same column
            else //if weight of (i-1) > j  
                K[i][j] = K[i - 1][j]; //copy the value from previous row of the same column
        }
    }
    i=n,j=W;
    while(i>0&&j>0) //To find which items are selcted
    {
        if(K[i][j]!=K[i-1][j])//wheteher the item is present on previus row or not
        {
            printf("Item %d is included\n",i);
            j=j-item[i-1].wt;// subtracting the weight of selected item
            i--;
            
        }
        else //K[i][j]==K[i-1][j]
        i--;
    }
    printf("The max profit is %d$ ", K[n][W]);
}
void knapsack_f(struct item item[],int n,int W) //fractional Knapsack
{
    float tot_p = 0.0;
    int i, maxi;
    int used[10];
    for (i = 0; i < n; ++i)
        used[i] = 0; //to check which objects has been used
    while (W > 0) { /* while there's still room*/
        maxi = -1;
        for (i = 0; i < n; ++i)/* Find the best object */
            if ((used[i] == 0) && ((maxi == -1) ||
                ((float)item[i].pr / item[i].wt > (float)item[maxi].pr / item[maxi].wt)))//chechking profit per unit weight
                maxi = i;
        used[maxi] = 1; /* mark the maxi-th object as used */
        W -= item[maxi].wt;
        tot_p += item[maxi].pr;
        if (W >= 0)
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, item[maxi].pr, item[maxi].wt, W);
        else {
            printf("Added %.2f%% (%d$, %dKg) of object %d in the bag.\n", (float)((1 + (float)W / item[maxi].wt) * 100), item[maxi].pr, item[maxi].wt, maxi + 1);
            tot_p -= item[maxi].pr;
            tot_p += (1 + (float)W / item[maxi].wt) * item[maxi].pr;//finding the amount of profit will get in that fraction
        }
    }
    printf("\nFilled the bag with objects worth %.2f$.\n", tot_p);
}
void main() 
{
    int n,W;
    printf("Enter the No. of items and max weight: ");
    scanf("%d %d",&n,&W);
    struct item item[n];
    for(int i=0;i<n;i++)
    {
        int prf,wgt;
        printf("Enter the weight and profit: ");
        scanf("%d %d",&wgt,&prf);
        item[i].wt=wgt;
        item[i].pr=prf;
    }
   knapsack_f(item,n,W);
//    knapsack_nf(item,n,W); //0-1Knapsack
}