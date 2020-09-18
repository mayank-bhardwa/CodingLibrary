#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct item 
{
    ll sum,suffix,prefix,seg;
};

struct SegTree{
    int size;
    vector<item> seg;
    SegTree(int n)
    {
        size = 1 ;
        while (size < n)
        {
            size<<=1;
        }
        seg.resize(size*2-1,{0LL,0LL,0LL,0LL});
    }

    item merge(item a,item b)
    {
        return {
            a.sum+b.sum,
            max(a.suffix+b.sum,b.suffix),
            max(a.prefix,a.sum+b.prefix),
            max(a.seg,max(b.seg,a.suffix+b.prefix))
        };
    }

    void insert(int i,int v,int x,int lx,int rx)
    {
        if(rx-lx == 1)
        {
            if(v>=0) seg[x]={v,v,v,v};
            else seg[x] = {v,0,0,0};
            return; 
        }

        int mid = (lx+rx)/2;
        if(i<mid)
        {
            insert(i,v,2*x+1,lx,mid);
        }
        else
        {
            insert(i,v,2*x+2,mid,rx);
        }
        
        seg[x] = merge(seg[2*x+1],seg[2*x+2]);
    }

    void insert(int i,int a)
    {
        insert(i,a,0,0,size);
    }

    ll get()
    {
        return seg[0].seg;
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
    cin >> n >> m ;
    SegTree segtree(n);
    int a;
    for(int i=0;i<n;i++)
    {
        cin >> a ;
        segtree.insert(i,a);
    } 

    cout<<segtree.get()<<"\n";
    int i;
    for(int j=0;j<m;j++)
    {
        cin>>i>>a;
        segtree.insert(i,a);
        cout<<segtree.get()<<"\n";
    }
    return 0;
}