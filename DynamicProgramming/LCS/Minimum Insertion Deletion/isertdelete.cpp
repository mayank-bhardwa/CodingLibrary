/*
CPP Program to calculate minimum number of insertion and deletion
to conver string A to string B it make use of longest common
sequence to calculate both insertion and deletions
insertions=len(final)-LCS
deletions=len(given)-LCS
*/
#include<iostream>

using namespace std;

int getcount(string g,string f)
{
    int n=g.size();
    int m=f.size();
    int t[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)        t[i][j]=0;
            else if(g[i-1]==f[j-1]) t[i][j]=t[i-1][j-1]+1;
            else                    t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    int insertions=m-t[n][m];
    int deletions=n-t[n][m];
    return insertions+deletions;
}

int main()
{
    string g="heapsort";
    string f="easport";
    cout<<getcount(g,f);
    return 0;
}