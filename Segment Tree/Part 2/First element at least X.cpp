#include <iostream>
#include <vector>
using namespace std;

struct SegTree
{
    int size;
    vector<int> seg;
    SegTree(int n)
    {
        size=1;
        while(size<n) size <<=1;
        seg.resize(2*size-1,0);
    }

    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            seg[x] = v ;
            return ;
        }
        int mid = (rx+lx)>>1;
        if(i<mid) set(i,v,2*x+1,lx,mid);
        else set(i,v,2*x+2,mid,rx);

        seg[x] = max(seg[2*x+1] , seg[2*x+2]);
    }

    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }

    int get(int v,int x,int lx,int rx)
    {
        if(seg[x]<v) return -1;
        if(rx-lx==1)
        {
            return lx;
        }
        int mid = (rx+lx)>>1;
        int res = get(v,2*x+1,lx,mid);
        if(res==-1) res = get(v,2*x+2,mid,rx);
        return res;
    }

    int atleast(int x)
    {
        return get(x,0,0,size);
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

    int n,m,a,i,v;
    cin >> n >> m ;
    SegTree segtree(n);
    for (i = 0; i < n; i++)
    {
        cin >> a;
        segtree.set(i,a);
    }

    for(int j=0;j<m;j++)
    {
        cin >> i ;
        if(i==1)
        {
            cin >> a >> v;
            segtree.set(a,v);
        }
        else
        {
            cin >> v ;
            cout<<segtree.atleast(v)<<"\n";
        }
    }
    return 0;
}