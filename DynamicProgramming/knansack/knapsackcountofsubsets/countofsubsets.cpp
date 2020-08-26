/*
Program to count number of subsets present in the array
such that their sum is equal to given sum
*/
#include<iostream>
using namespace std;

int countsubsets(int arr[],int n,int sum){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){            //if sum is equal to 0 and then then return 1 as count as only null subset accepted
        t[i][0]=1;
    }
    for(int i=1;i<=sum;i++){          //if sum>0 and n==0 no 
        t[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                t[i][j]=t[i-1][0];
            }
            else{
                t[i][j]=t[i-1][j] + t[i-1][j-arr[i-1]];    //in subset sum we were taking or(||) as we are only concerned if any of them is accepted
            }                                              //but in this case we will count all that are accepted therfore + is used instead of (||)
        }
    }

    return t[n][sum];
}

int main()
{
    int arr[]={2,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=4;
    cout<<countsubsets(arr,n,sum);
    return 0;
}