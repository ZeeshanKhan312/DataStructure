#include<iostream>
using namespace std;

void CountSort(int A[], int n){
    int max = 0; 
    for( int i = 0; i<n; i++){
        if(A[i]>max)
        max = A[i];
    }
    int count[max+1]= { 0 };
    for(int j=0; j<n; j++){
        count[A[j]]=count[A[j]]+1;
    }
    int j = 0 , i = 0 ;
    while(i<n){
        if(count[j]>0){
            A[i]=j;
            i++;
            count[j]=count[j]-1;
        }
        else
            j++;
        }
        for(int i = 0; i < n; i++){
            cout<<A[i]<<" ";
        }
}

int main(){
    int A[]= {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
    int n = 17;
    CountSort(A, n);
    
    return 0; 
}