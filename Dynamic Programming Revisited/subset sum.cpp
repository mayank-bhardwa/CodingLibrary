// Given a set of n numbers ai sum up to M, and any K ≤ M, whether there is a subset of the
// numbers such that they sum up to (hit) K? We assume n might be as big as 1000, but M or K is not too
// big

#include <iostream>
#include <vector>
using namespace std;

int SubsetSum( vector<int> a ,int Sum ,int c=0)
{
    // if(Sum==0)
    // {
    //     return 1;
    // }
    // if( c==a.size() )
    // {
    //     return 0 ;
    // }

    // if(Sum >= a[c])
    // {
    //     return SubsetSum(a,Sum-a[c],c+1) || SubsetSum(a,Sum,c+1) ;
    // }
    // else
    // {
    //     return SubsetSum(a,Sum,c+1);
    // }

    int dp[a.size()+1][Sum+1];

    for ( int i = 0; i <= a.size() ; i++ )
        for( int j = 0; j <=Sum ;j++)
        {
            if(j==0)dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else if(j >= a[i-1]) dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            else dp[i][j] = dp[i-1][j]; 
        }
    return dp[a.size()][Sum];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int m;
    cin >> m ;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin>>a[i];
    }

    int Sum;
    cin>>Sum;

    cout<<SubsetSum(a,Sum);
    return 0;
}