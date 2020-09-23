#include<iostream>
#include<vector>
using namespace std;

struct SegTree
{
    int size;
    vector<int> seg;

    SegTree(int n)
    {
        size = 1;
        while(size < n) size <<=1;
        seg.resize(2*size-1,0);
    }

    void mark(int i,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            seg[x] = 1;
            return ;
        }
        int mid = (rx+lx)>>1;
        if(i<mid)   mark(i,2*x+1,lx,mid);
        else    mark(i,2*x+2,mid,rx);
        seg[x] = seg[2*x+1] + seg[2*x+2];
    }

    void mark(int i)
    {
        mark(i,0,0,size);
    }

    int cal(int l,int r,int x,int lx,int rx)    
    {
		if(lx >=r || l >= rx) return 0;
		if(lx >= l && rx <= r) return seg[x]; 

		int m = (lx + rx)/2;

		long long lcal = cal(l ,r ,2*x + 1 ,lx ,m);
		long long rcal = cal(l ,r ,2*x + 2 ,m , rx);
		return lcal + rcal;
    }

    int get(int i)
    {
        int res = cal(i,size,0,0,size);
        mark(i);
        return res;
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
    int n,a;
    cin>>n;
    SegTree segtree(n);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cout << segtree.get(a-1) << " " ;
    }

    return 0;
}