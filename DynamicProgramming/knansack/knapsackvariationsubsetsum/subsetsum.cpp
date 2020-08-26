/*
Dynamic programming approach to check if a subset 
of arr equals to desired sum if it is present di-
splay true or1 else display false 0. This problem 
is similar to typical knapsack which has two array
weights and values here we only have single array
which is arr[] which will behave like weights as
as it will make up the sum and is modifying 
*/

#include<iostream>
using namespace std;

bool subsestsum(int arr[],int sum,int n){
    bool t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        t[i][0]=true;
    }
    for(int i=1;i<=sum;i++){
        t[0][i]=false;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
           if(arr[i-1]>j){       //if size of array element is greater than left sum
                t[i][j]=t[i-1][j];         //it could not be accepted and hence it is left
            }

            else                       //take the vale which is true on accepting the elemet and rejecting the element
            {
                t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];  // '||' or operator is used to take true value only
            }
        }
    }
/*for (int i = 0; i <= n; i++)    //for printing table
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", t[i][j]); 
       printf("\n"); 
     }*/
    return t[n][sum];
}

int main(){
    int arr[]={2,3,5,6,8,10};
    int sum=10;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subsestsum(arr,sum,n);
    return 0;
}