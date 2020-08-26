#include<string.h>
#include<iostream>
using namespace std;

int common(string X,int n,string Y,int m){
    if(m==0 || n==0)return 0;

    if(X[n-1]==Y[m-1])return common(X,n-1,Y,m-1)+1;
    else{
        return max(common(X,n-1,Y,m),common(X,n,Y,m-1));
    }
}

int main()
{
    char *X="mayank";
    int n=strlen(X);
    char *Y="ansh";
    int m=strlen(Y);
    cout<<common(X,n,Y,m);
    return 0;    
}