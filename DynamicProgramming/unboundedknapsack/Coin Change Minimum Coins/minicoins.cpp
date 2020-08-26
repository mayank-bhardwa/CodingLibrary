#include<iostream>
using namespace std;

int minicoins(int coins[],int n,int Amount){
    int t[n+1][Amount+1];
    for(int i=0;i<=n;i++){
        t[i][0]= 0;
    }
    for(int i=1;i<=Amount;i++){
        t[0][i]=INT_MAX-1;
        if(i%coins[0]==0)
            t[1][i]=i/coins[0];
        else
        {
            t[1][i]=INT_MAX-1;
        }   
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=Amount;j++){
            if(coins[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else
            {
                t[i][j]=min(t[i-1][j],t[i][j-coins[i-1]]+1);
            }
            
        }
    }    
if(t[n][Amount]==INT_MAX-1)return -1;
return t[n][Amount];
}

int main()
{
    int coins[]={2};
    int amount=27;
    int n=sizeof(coins)/sizeof(coins[0]);
    cout<<minicoins(coins,n,amount);
    return 0;
}