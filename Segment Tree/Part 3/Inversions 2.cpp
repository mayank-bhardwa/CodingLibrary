#include <iostream>
#include <vector>
using namespace std;

struct SegTree
{
    int size;
    vector<int> seg;

    SegTree(int n)
    {
        size = 1;
        while (size < n) size <<=1 ;
        seg.resize(size<<1 -1,1);
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    SegTree segtree(n);
    vector<int> vl(n);
    for(int i=n-1;i>=0;i--)
    {
        cin >> vl[i] ;
    }
    return 0;
}