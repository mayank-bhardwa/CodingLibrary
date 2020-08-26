#include<iostream>
using namespace std;

int fibo(int n){
    int d[n+2];
    d[0]=0;
    d[1]=1;
    
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+d[i-2];        
    }
    return d[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}