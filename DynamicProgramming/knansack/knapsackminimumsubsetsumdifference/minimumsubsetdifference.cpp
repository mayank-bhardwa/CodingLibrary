/*

*/
#include<iostream>
using namespace std;

int minsubdiff(int arr[],int n,int range){
    bool t[n+1][range+1];
    for(int i=0;i<=n;i++){
        t[i][0]=true;
    }
    for(int i=1;i<=range;i++){
        t[0][i]=false;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            if(arr[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else
            {
                t[i][j]= t[i-1][j] || t[i-1][j-arr[i-1]];
            }
            
        }
    }
    
    int min=range/2;

    for(int i=min;i>=0;i--){
        if(t[n][i]){
            return range-2*i;
        }
    }
    return range;
}

int main(){
    int arr[]={3, 1, 4, 2, 2, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<minsubdiff(arr,n,sum);
    return 0;
}