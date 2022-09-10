//  KADANE ALGORITHM   //
#include<iostream>
using namespace std; 

int kadane(int A[], int n){
    int subArray_sum=A[0];
    int max_sum=A[0];
    
    for(int i=1; i<n; i++){
        subArray_sum=subArray_sum+A[i];
        if(subArray_sum<A[i])
        subArray_sum=A[i];
        
        if(max_sum<subArray_sum)
        max_sum=subArray_sum;
    }
    return max_sum;
}

int main(){
    int A[] = {-2, 4, -1, 3, -2, 1}; 
    int n = 6; 
    
    int max_sum= kadane(A, n);
    cout<<"The maximum sum of the contiguous subarray is  ";
    cout<<max_sum; 
    
    return 0; 
}