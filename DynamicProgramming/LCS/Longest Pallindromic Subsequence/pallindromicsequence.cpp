/*
Program to find longest pallendrome length hidden in the word
ex geeksforgeeks
eekee len=7
this problem is same as lcs but we have only one string we get 
other string by reversing the given string then applying lcs
*/

#include<iostream>
#include<algorithm>
using namespace std;

int palindromelength(string s)
{
    int n=s.size();
    string revS= s;
    reverse(s.begin(),s.end());
    int t[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) t[i][j]=0;
            else if (s[i-1]==revS[j-1])
            {
                t[i][j]=t[i-1][j-1]+1;
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
            
        }
    }
    return t[n][n];
}

int main()
{
    string s="geeks for geeks";
    cout<<palindromelength(s);
    return 0;
}