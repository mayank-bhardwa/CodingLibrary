/*
Recursive solution to the unbounded knapsack problem where repetition of items is allowed
Only difference in this problem from 0-1 knapsack is that we were changing the n(index)
whenever we encounter a value to mark it as processed but in this case an item is marked
procesed only if it is rejected if it is accepted then no changes were made to it.
*/
#include<iostream>
using namespace std;

int unbknapsack(int wts[],int val[],int MaxW,int n){
    int t[n+1][MaxW+1];
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int i=1;i<=MaxW;i++){
        t[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=MaxW;j++){
            if(wts[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else{
                t[i][j]= max( t[i][j-wts[i-1]]+val[i-1] ,t[i-1][j] );
            }
        }
    }
    return t[n][MaxW];
}

int main(){
    int val[] = {10, 30, 20}; 
    int wts[] = {5, 10, 15}; 
    int Max=100;
    int n=sizeof(wts)/sizeof(wts[0]);
    cout<<unbknapsack(wts,val,Max,n);
    return 0;
}