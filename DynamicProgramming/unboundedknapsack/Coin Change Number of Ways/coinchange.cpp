/*
Program to find number of ways a given coins can be used to make up a
given sum. This is dynamic solution for this problem
*/
#include<iostream>
using namespace std;

int coinways(int coins[],int N,int Amount,int **dp){
    for(int i=0;i<=N;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=Amount;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=Amount;j++){
            if(coins[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[N][Amount];
}

int main(){
    int coins[]={1,2,5};
    int n=sizeof(coins)/sizeof(coins[0]);
    int Amount=10;
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[Amount+1];
    }

    cout<<coinways(coins,n,Amount,dp);
    return 0;
}