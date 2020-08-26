/*
In this we have to find out all subset of array whose sum is equal to 
given difference we solve if mathematically and then apply normal
subset sum method sum(P1)-sum(P2)=diff
                  sum(p1)+sum(P2)=sum(array)
                  sum(p1)=(diff + sum(array))/2
*/
#include<iostream>
using namespace std;

int diffsubset(int arr[],int n,int diff){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int dsum=(sum+diff)/2;
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
    int arr[]={1,1,2,3};
    int diff=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<diffsubset(arr,n,diff);
    return 0;
}