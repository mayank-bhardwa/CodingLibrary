#include<iostream>
using namespace std;

bool recurse(int arr[],int n,int sum){
    if(n==0&&sum!=0){
        return false;
    }
    if(sum==0){
        return true;
    }

    if(arr[n-1]>sum){
        return recurse(arr,n-1,sum);
    }else{
        return recurse(arr,n-1,sum-arr[n-1]) || recurse(arr,n-1,sum);
    }
}

bool equalsum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2==0){
        return recurse(arr,n,sum/2);
    }
    else{
        return false;
    }
}

int main(){
    int arr[]={1,5,11,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<equalsum(arr,n);
    return 0;
}