/*
C++ program to print length of 
*/
#include<iostream>
#include<string.h>
using namespace std;

int common(string X,string Y,int n,int m){
    int t[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][m];
}

int main()
{
    char *X="mayank";
    int n=strlen(X);
    char *Y="ansh";
    int m=strlen(Y);
    
    cout<<common(X,Y,n,m);
    return 0;
}