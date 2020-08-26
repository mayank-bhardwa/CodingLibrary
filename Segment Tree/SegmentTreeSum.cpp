#include <iostream>
#include <vector>

using namespace std;

struct SegTree
{
	int size;
	vector<long long> sums;

	void init(int n)
	{
		size=1;
		while(size<n)size *=2;
		sums.assign(2*size,0LL);
	}

	void build(vector<int> &a ,int x ,int lx ,int rx)
	{
		if(rx - lx ==1)
		{
			if(lx < (int)a.size())
			{
				sums[x] = a[lx];
			}
			return;
		}

		int m = (lx + rx)/2;

		build(a,2*x+1,lx,m);
		build(a,2*x+2,m,rx);
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void build(vector<int> &a)
	{
		build(a,0,0,size);
	}

	void set(int i, int v, int x, int lx, int rx)
	{
		if(rx-lx==1)
		{
			sums[x] = v;
			return ;
		} 
		int mid=(lx + rx)/2;
		if(i < mid)
		{
			set(i ,v ,2*x+1 ,lx ,mid);
		}
		else
		{
			set(i ,v ,2*x+2 ,mid,rx);
		}

		sums[x] = sums[2*x + 1] + sums[2*x + 2];
	}

	void set(int i,int v)
	{
		set(i ,v ,0 ,0 ,size);		
	}

	long long sum(int l, int r, int x, int lx, int rx)
	{
		if(lx >=r || l >= rx) return 0;
		if(lx >= l && rx <= r) return sums[x]; 

		int m = (lx + rx)/2;

		long long lsum = sum(l ,r ,2*x + 1 ,lx ,m);
		long long rsum = sum(l ,r ,2*x + 2 ,m , rx);
		return lsum + rsum;
	}

	long long sum(int l,int r)  //calculate sum from i=l to i=r-1
	{
		return sum(l ,r ,0 ,0 ,size);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,v;
	cin>>n>>m;
	SegTree st;
	st.init(n);

	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	st.build(a);
	int t,l,r;
	for(int i=0;i<m;i++)
	{
		cin >> t ;
		if ( t == 2 )
		{
			cin>>l>>r;
			cout<<st.sum(l,r)<<"\n";
		}
		else
		{
			cin>>l>>v;
			st.set(l,v);
		}
	}
	return 0;
}