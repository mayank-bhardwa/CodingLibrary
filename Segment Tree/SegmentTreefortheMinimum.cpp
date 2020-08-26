#include <iostream>
#include <vector>
using namespace std;

struct SegTreeMin
{
	int size;
	vector<int> mins;

	void init(int n)
	{
		size = 1;
		while(size < n)size *= 2;
		mins.assign(2*size,0);
	}	

	void set(int i , int v, int x, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			mins[x] = v;
			return;
		}
		int m = (rx + lx)/2 ;

		if(i < m)	set(i ,v ,2*x+1 ,lx ,m);
		else	set(i ,v ,2*x+2 ,m ,rx);

		mins[x] = min( mins[2*x+1] , mins[2*x+2] );
	}

	void set(int i, int v)
	{
		set(i , v, 0, 0, size);
	}

	int getMin(int l ,int r ,int x ,int lx ,int rx)
	{
		if(rx <= l || r <= lx) return INT_MAX;
		if(rx <= r && lx >= l) return mins[x];
		int m = (rx + lx)/2;

		int m1 = getMin(l,r,2*x+1,lx,m);
		int m2 = getMin(l,r,2*x+2,m,rx);

		return min(m1 , m2);
	}

	int getMin(int l , int r)
	{
		return getMin(l,r,0,0,size);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,a;
	cin>>n>>m;
	SegTreeMin st;
	st.init(n);
	for(int i=0 ;i<n;i++)
	{
		cin>>a;
		st.set(i,a);
	}

	int x,y,z;
	for(int i=0;i<m;i++)
	{
		cin>>x;
		if (x==1)
		{
			cin>>y>>z;
			st.set(y,z);
		}
		else
		{
			cin>>y>>z;
			cout<<st.getMin(y,z)<<"\n";
		}
	}

	return 0;
}