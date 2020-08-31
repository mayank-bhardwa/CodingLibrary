#include <iostream>
#include <vector>

using namespace std;

int SubSumMaxCount(vector<int> a,int sum)
{
    int dp[a.size()+1][sum+1];

    for(int i=0;i<=a.size();i++)
        for (int j = 0; j <= sum; j++)
        {
            if(j==0 || i==0)dp[i][j]=0;
            else if(j>=a[i-1]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i-1]]+1);
            else dp[i][j] = dp[i-1][j];
        }
    return dp[a.size()][sum];        
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,sum;
    cin>>n>>sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<<SubSumMaxCount(a,sum);
    return 0;    
}