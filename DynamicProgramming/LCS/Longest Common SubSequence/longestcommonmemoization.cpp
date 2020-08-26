#include<iostream>
#include<string.h>
using namespace std;
int static d[100][100];
int common(string X,int n,string Y,int m){
    if(n==0 || m==0){
        return d[n][m]=0;
    }
    
    if(d[n][m]!=-1){
        return d[n][m];
    }

    if(X[n-1]==Y[m-1]){
        return d[n][m]=common(X,n-1,Y,m-1)+1;
    }
    else{
        return d[n][m]=max(common(X,n-1,Y,m),common(X,n,Y,m-1));
    }
}

int main()
{
    char *X="mayank";
    int n=strlen(X);
    char *Y="ansh";
    int m=strlen(Y);
    memset(d,-1,sizeof(d));
    cout<<common(X,n,Y,m);
    return 0;
}