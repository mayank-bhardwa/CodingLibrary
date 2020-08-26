/*
Program to find number of ways to reach an amount from
given source of coins with infinite stock for each 
coin.
*/
#include<iostream>
using namespace std;

int coinchange(int coins[],int n,int Amount){
    if(Amount==0){
        return 1;
    }
    if(n==0){
        return 0;
    }

    if(coins[n-1]>Amount){
        return coinchange(coins,n-1,Amount);
    }
    else{
        return coinchange(coins,n-1,Amount)+coinchange(coins,n,Amount-coins[n-1]);
    }
}

int main(){
    int coins[]={1,2,5};
    int n=sizeof(coins)/sizeof(coins[0]);
    int Amount=10;
    cout<<coinchange(coins,n,Amount);
    return 0;
}