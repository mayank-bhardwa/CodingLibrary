/*
Length of shortest common super sequence =m+n-LCS
m is length of string 1
n is length of string 2
if we simply add all elements of 1 and 2 we will have
LCS as common in both so we will remove one LCS
that would be length of super sequence
*/

#include<iostream>
#include<string.h>
using namespace std;

int length(char *a,char *b)
{
    int n=strlen(a);
    int m=strlen(b);
    int t[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j==0 || i==0) t[i][j]=0;
            else if(a[i-1]==b[j-1]) t[i][j]=t[i-1][j-1]+1;
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return m+n-t[n][m];
}

int main()
{
    char *s1="aggtab";
    char *s2="gxtxayb";
    cout<<length(s1,s2);
    return 0;
}