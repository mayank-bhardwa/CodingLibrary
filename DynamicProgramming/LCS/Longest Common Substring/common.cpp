#include<iostream>
using namespace std;

int common(string a,string b)
{
    int n=a.size();
    int m=b.size();
    int t[n+1][m+1];
    int result=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
            if(a[i-1]==b[j-1] && i!=j)
            {
                t[i][j]=t[i-1][j-1]+1;
                result=max(result,t[i][j]);
            }
            else t[i][j]=0;
        }
    }
    return result;
}

int main()
{
    string a="xabcvst";
    string b="wklabcpstl";
    cout<<common(a,b);
    return 0;
}