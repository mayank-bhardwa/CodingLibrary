/*
Below is a cpp program to find max profit that could be made 
if we have given weights of items and their corresponding
values we have to choose weights such that sum of values 
is maximum and total weight is less than or equal to capacity 
of knapsack (w) 
*/
//this is dynamic solution using memoization
//in this we create matrix t of size n*m where n and m are 
//variables that are changing in recursive function
#include<iostream>
using namespace std;

int knapsack(int values[],int weights[],int W,int n){
    int t[n+1][W+1];
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int i=0;i<=W;i++){
        t[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(weights[i-1]<=j){
                t[i][j]=max( t[i-1][j] ,
                             t[i-1][j-weights[i-1]]+values[i-1] );
            }
            else{
                t[i][j]=t[i-1][j];  
            }
        }
    }
/*for (int i = 0; i <= n; i++)    //for printing table
     { 
       for (int j = 0; j <= W; j++) 
          printf ("%4d", t[i][j]); 
       printf("\n"); 
     }*/
    return t[n][W];
}

int main(){
    //below lines make code input output fast
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int weights[] = {5,7,6,1,2,5,3,11,3,4};
    int values[] = {3,1,8,7,1,6,2,15,6,2};
    int n=sizeof(weights)/sizeof(weights[0]);
    int w=15;

    cout<<knapsack(weights,values,w,n);

    return 0;
}