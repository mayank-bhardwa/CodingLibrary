#include<iostream>
#include<algorithm>
using namespace std;

int minimum(string a)
{
    int n=a.size();
    string c=a;
    reverse(a.begin(),a.end());
    int t[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)t[i][j]=0;
            else if(c[i-1]==a[j-1])t[i][j]=t[i-1][j-1]+1;
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }

    return a.size()-t[n][n];  //we can either remove or add this much elements to make it pallindrome
}


int main()
{
    string s="geeksforgeeks";
    cout<<minimum(s);
    return 0;
}