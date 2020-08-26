/*
Rod cutting problem dynamic solution this is similar to the unboundedknapsack problem
in this problem we have cost of rod for corresponding rod size we have big rod of given 
length we have to cut in smaller pieces so that we could make max money
*/
#include<iostream>
using namespace std;

int cutrod(int Rsize[],int Rcost[],int n,int Length,int **dp)
{
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=Length;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=Length;j++){
            if(Rsize[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(Rcost[i-1]+dp[i][j-Rsize[i-1]] , dp[i-1][j]);
            }
        }
    }
    return dp[n][Length];
}

int main()
{
   int Rsize[]={5,6,8};
   int Rcost[]={10,5,6};
   int n=sizeof(Rsize)/sizeof(Rsize[0]);
   int Tlength=50;
   int **dp=new int*[n+1];
   for(int i=0;i<=n;i++){
       dp[i]=new int[Tlength+1];
   }
 
   cout<<cutrod(Rsize,Rcost,n,Tlength,dp);
   return 0;
}