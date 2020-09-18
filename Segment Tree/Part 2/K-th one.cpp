#include<iostream>
#include<vector>
using namespace std;

struct SegTree
{
    int size;
    vector<int> seg;
    SegTree(int n)
    {
        size = 1 ;
        while(size < n) size <<= 1;
        seg.resize(size*2,0);
    }

    void set(int i,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            seg[x] = 1-seg[x];
            return;
        }
        int mid = (lx+rx)/2;
        if(i<mid) set(i,2*x+1,lx,mid);
        else set(i,2*x+2,mid,rx) ;

        seg[x] = seg[2*x+1]+seg[2*x+2];
    }

    void set(int i)
    {
        set(i,0,0,size);
    }

    int get(int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            return lx;
        }
        int mid = (lx+rx)/2;

        int s1=seg[2*x+1];
        if(v<s1)
        {
            return get(v,2*x+1,lx,mid);
        }
        else 
        {
            return get(v-s1,2*x+2,mid,rx);
        }
    }

    int get(int v)
    {
        return get(v,0,0,size);
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

    int n,m;
    cin>>n>>m;
    SegTree segtree(n);
    int i,v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
        if(v)segtree.set(i);
    }

    for(int j=0;j<m;j++)
    {
        cin>>i>>v;
        if(i==1)
        {
            segtree.set(v);
        }
        else
        {
            cout<<segtree.get(v)<<"\n";
        }
    }
    return 0;
}