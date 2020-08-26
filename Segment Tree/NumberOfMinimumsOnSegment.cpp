#include <iostream>
#include <vector>
using namespace std;

struct SegTreeMinC
{
	int size;

	pair<int,int> utility(pair<int,int> x,pair<int,int> y)
	{
		if(x.first == y.first) return {x.first,x.second+y.second};
		else if(x.first > y.first) return y;
		else return x;
	}

	vector<pair<int,int>> minc;

	void init(int n)
	{
		size = 1;
		while(size < n) size *= 2 ;
		minc.assign(2*size,{0,0});
	}

	void set(int i ,int v ,int x ,int lx ,int rx)
	{
		if(rx - lx == 1)
		{
			minc[x] = {v,1};
			return;
		}

		int m = (lx + rx)/2;

		if(i < m)set(i,v,2*x+1,lx,m);
		else set(i,v,2*x+2,m,rx);

		minc[x] = utility(minc[2*x+1],minc[2*x+2]);
	}

	void set(int i, int v)
	{
		set(i ,v ,0 ,0 ,size);
	}

	pair<int,int> getc(int l, int r, int x, int lx, int rx)
	{
		if(rx <= l || lx>=r) return {INT_MAX,0};
		if(lx >= l && rx <= r) return minc[x];

		int m = (lx + rx)/2;

		pair<int,int> a = getc(l,r,2*x+1,lx,m);
		pair<int,int> b = getc(l,r,2*x+2,m,rx);

		return utility(a,b);
	}

	pair<int,int> getc(int l, int r)
	{
		return getc(l,r,0,0,size);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,a;
	cin>>n>>m;
	SegTreeMinC st;
	st.init(n);
	for(int i=0;i<n;i++)
	{
		cin>>a;
		st.set(i,a);
	}

	int x,y,z;
	for(int i=0;i<m;i++)
	{
		cin>>x;
		if(x==1)
		{
			cin>>y>>z;
			st.set(y,z);
		}
		else
		{
			cin>>y>>z;
			pair<int,int> a=st.getc(y,z);
			cout<<a.first<<" "<<a.second<<"\n";
		}
	}
	return 0;
}