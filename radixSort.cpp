#include<iostream>
using namespace std; 

void count_sort(int arr[], int n, int place){
    int count[10]={0};

    int pos;
    for(int i=0; i<n; i++){
        pos=(arr[i]/place)%10;
        count[pos]++;
    }
    //updaing the count array 
    for(int i=1; i<10; i++)
        count[i]+=count[i-1];
    
    int output[n];
    int pos2;
    for(int i=n-1; i>=0; i--){
        pos=(arr[i]/place)%10;
        pos2=--count[pos];  //pos2=pos-1 cant be written as we have to maintain changes in count also 
        output[pos2]=arr[i];
        }

    //updating array 
    for(int i=0; i<n; i++)
        arr[i]=output[i];
    
}

void radix_sort(int arr[], int n){
    int max=-1;
    for(int i=0; i<n; i++){
        if(arr[i]>max)
        max=arr[i];
    }

    for(int place=1; max/place>0; place=place*10){
        count_sort(arr, n, place);
    }

}
int main(){
    int n=7;
    int arr[n]={23, 45, 67, 122, 12, 89, 199};
    radix_sort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}