/*
    Complexity: N*log(log(N))
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<bool> prime(n+1,true);
    int p = ceil(sqrt(n)) ;
    
    for(int i=2;i<=p;i++)
    {
        if(prime[i])
            for(int j=i+i;j<=n;j+=i)
                prime[j] = false;
    }

    for(int i=2;i<=n;i++)
        if(prime[i]) cout<<i<<", ";
    return 0;
}