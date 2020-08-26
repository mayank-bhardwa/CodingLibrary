/*
Recursive solution to the unbounded knapsack problem where repetition of items is allowed
Only difference in this problem from 0-1 knapsack is that we were changing the n(index)
whenever we encounter a value to mark it as processed but in this case an item is marked
procesed only if it is rejected if it is accepted then no changes were made to it.
*/
#include<iostream>
using namespace std;

int unboundknapsack(int wts[],int val[],int n,int Max)
{
    if(Max==0 || n==0){
        return 0;
    }
    if(wts[n-1]>Max){
        return unboundknapsack(wts,val,n-1,Max);                       //item is rejected so marked processed by reducing the n
    }
    else{
        return max( unboundknapsack(wts,val,n,Max-wts[n-1])+val[n-1] , unboundknapsack(wts,val,n-1,Max) );  //item remains unprocessed if item is accepted
    }
}


int main(){
    int val[] = {10, 30, 20}; 
    int wts[] = {5, 10, 15}; 
    int Max=100;
    int n=sizeof(wts)/sizeof(wts[0]);
    cout<<unboundknapsack(wts,val,n,Max);
    return 0;
}