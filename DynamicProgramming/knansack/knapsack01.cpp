/*
Below is a cpp program to find max profit that could be made 
if we have given weights of items and their corresponding
values we have to choose weights such that sum of values 
is maximum and total weight is less than or equal to capacity 
of knapsack (w) 
*/
//this is recursive solution

#include<iostream>
using namespace std;

int knapsack(int weights[],int values[],int w,int n){

        if(n==0 || w==0){                  //base case if their is no item or no space in knapsack stop calling
            return 0;
        }

        else if(weights[n-1]<=w){         //if item weight is less or equal to w then we have two choice accept it or reject it  
            return max( values[n-1]+knapsack(weights,values,w-weights[n-1],n-1) , knapsack(weights,values,w,n-1) );
        }

        else{                            //if item weight is more than w then it could not be inserted
            return knapsack(weights,values,w,n-1);
        }
}

int main(){
    //below lines make code input output fast
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n=10;
    int weights[] = {5,7,6,1,2,5,3,11,3,4};
    int values[] = {3,1,8,7,1,6,2,15,6,2};
    int w=15;

    cout<<knapsack(weights,values,w,n);

    return 0;
}