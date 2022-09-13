#include <iostream>
using namespace std;
struct Job{
    char id;
    int profit, deadline;
};

void JobSequencing(Job arr[],int n){
    Job temp;
    for(int i=1;i<n;i++){  //SORTING THE JOB STRUCT IN DECREASING ORDER OF PROFIT USING BUBBLE SORT
        for(int j=0;j<n-i;j++){
            if(arr[j].profit<arr[j+1].profit){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    char slot[n]={0};
    int maxProfit=0;
    for(int i=0;i<n;i++){
        while(arr[i].deadline>0){ 
            if(slot[arr[i].deadline -1]==0){
                maxProfit+=arr[i].profit; //updating the max profit
                slot[arr[i].deadline-1]=arr[i].id;  //giving the slot to particular job
                cout<<"At slot "<<arr[i].deadline-1<<" Job "<<arr[i].id<<" will be done"<<endl;
                break;
            }
            arr[i].deadline--;
        }
    }
    
    cout<<"Maximum Profit is of "<<maxProfit;
}

int main()
{
    struct Job arr[] = { { 'A', 100, 2 },
                  { 'B', 19, 1 },
                  { 'C', 27, 2 },
                  { 'D', 25, 1 },
                  { 'E', 15, 3 } };
    int n=sizeof(arr)/sizeof(arr[0]);  //to calculate no. of elements in arr
    JobSequencing(arr,n);

    return 0;
}