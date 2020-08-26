#include<iostream>
using namespace std;

int mindiffsubset(int arr[],int n,int range,int total)
{

    if(n==0){
        return abs(range-2*range);
    }

    return min(mindiffsubset(arr,n-1,range,total),mindiffsubset(arr,n-1,range-arr[n-1],total));
}

int main(){
    int arr[]={3, 1, 4, 2, 2, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<mindiffsubset(arr,n,0,sum);
    return 0;
}