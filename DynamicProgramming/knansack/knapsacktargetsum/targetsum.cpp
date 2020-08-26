/*
Some problem as count number of subset sum difference only way of asking is changed
if we have give array assing '+' and '-' to each element such that they make sum of 
given target sum if we group all -ve elements and +ve elements we are again doing 
same as diff subset count problem
*/
#include<iostream>
using namespace std;
 
int targetsum(int arr[],int n,int tarsum){
        int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int dsum=(sum+tarsum)/2;
    int t[n+1][dsum+1];
    for(int i=0;i<=n;i++){
        t[i][0]=1;
    }
    for(int i=1;i<=dsum;i++){
        t[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=dsum;j++){
            if(arr[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j] + t[i-1][j-arr[i-1]];
            }
            
        }
    }
    return t[n][dsum];
}

int main(){
    int arr[]={1};
    int diff=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<targetsum(arr,n,diff);
    return 0;
}