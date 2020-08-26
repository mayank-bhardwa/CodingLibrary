/*
Program to find number of subsets in arr having sum equal to
given sum using recursion
*/

#include<iostream>
using namespace std;

int countofsubsets(int arr[],int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n==0 && sum!=0){
        return 0;
    }

    if(arr[n-1]>sum){
        return countofsubsets(arr,n-1,sum);
    }
    else{
        return countofsubsets(arr,n-1,sum)+countofsubsets(arr,n-1,sum-arr[n-1]);
    }
}

int main()
{
    int arr[]={2,3,5,6,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=10;
    cout<<countofsubsets(arr,n,sum);
    return 0;
}