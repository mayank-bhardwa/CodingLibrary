/*
Recursive solution to subsetsum problem
*/
#include<iostream>
using namespace std;

bool subsetsum(int arr[],int sum,int n){
    if(sum == 0){
        return true;
    }

    if(n==0 && sum!=0){
        return false; 
    }
    else if(arr[n-1]>sum){
        return subsetsum(arr,sum,n-1);
    }
    else
    {
        return subsetsum(arr,sum,n-1) || subsetsum(arr,sum-arr[n-1],n-1);
    }
}

int main()
{
    int arr[]={2,3,7,5,10};
    int sum=27;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subsetsum(arr,sum,n);
    return 0;
}