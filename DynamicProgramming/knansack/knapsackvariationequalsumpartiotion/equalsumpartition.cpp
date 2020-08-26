/*
program to check if a array can be dividied into two
partion whose sum are equal
*/

#include<iostream>
using namespace std;

bool equalsum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    if(sum%2 != 0){           //if sum of arr is odd it can never be divided into two equal parts
        return false;
    }
    else{                     //if sum of arr is odd we simply apply subset sum method to check 
        sum=sum/2;            //if arr has a subset sum equal to half of total sum which means left 
        bool t[n+1][sum+1];   //subset has other half of sum
    for(int i=0;i<=n;i++){
        t[i][0]=true;
    }
    for(int i=0;i<=sum;i++){
        t[0][i]=false;
    }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
               if(arr[i-1]>j){
                    t[i][j]=t[i-1][j];
                }
                else
                {
                    t[i][j]= t[i-1][j] || t[i-1][j-arr[i-1]];
                }
                
            }
        }
        return t[n][sum];
    }
}


int main(){
    int arr[]={1,5,11,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<equalsum(arr,n);
    return 0;
}