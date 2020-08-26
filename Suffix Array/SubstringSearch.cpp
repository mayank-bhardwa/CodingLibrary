#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void CountSort(vector<int> &index,vector<int> &rank)
{
    int n=index.size();

    vector<int> cnt(n);
    for(auto x:rank)
    {
        cnt[x]++;
    }
    vector<int> index_new(n);
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++)          //making containers
    {
        pos[i]=pos[i-1]+cnt[i-1];
    }

    for(auto x:index)
    {
        int i=rank[x];
        index_new[pos[i]]=x;
        pos[i]++;
    }
    index=index_new;
}

vector<int> BuildSuffixArray(string s)
{
    s+="$";
    int n=s.length();
    vector<int> rank(n),index(n);
    
        vector<pair<char,int>> a(n);
        for(int i=0;i<n;i++)
        {
            a[i]={s[i],i};
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)index[i]=a[i].second;
        rank[index[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].first==a[i-1].first)
            {
                rank[index[i]]=rank[index[i-1]];
            }
            else
            {
                rank[index[i]]=rank[index[i-1]]+1;
            }
        }
    
    int k=0;
    while((1<<k)<n)
    {
        for(int i=0;i<n;i++)
        {
            index[i] = (index[i] - (1<<k) +n)%n;
        }

        CountSort(index,rank);

        vector<int> rank_new(n);
        rank_new[index[0]]=0;
        for(int i=1;i<n;i++)
        {
            pair<int ,int> prev={ rank[index[i-1]] , rank[(index[i-1]+(1<<k))%n] };
            pair<int ,int> now ={ rank[index[i]] , rank[(index[i]+(1<<k))%n] };
            if(prev==now)
            {
                rank_new[index[i]]=rank_new[index[i-1]];
            }
            else
            {
                rank_new[index[i]]=rank_new[index[i-1]]+1;
            } 
        }
        rank=rank_new;
        k++;
    }
    return index;
}

bool binary_search(vector<int> &sarray,string s,string t)
{
	int l=0,r=sarray.size()-1,mid,k=s.size();
	while(l<=r)
	{
		mid=(l+r)/2;
		if(t.substr(sarray[mid],k)==s)
		{
			return 1;
		}

		else if(t.substr(sarray[mid],k) > s)
		{
			r=mid-1;
		}

		else
		{
			l=mid+1;
		}
	}
	return 0;
}

int main()
{
	string t;
	cin>>t;
	vector<int> sarray = BuildSuffixArray(t);
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		if(binary_search(sarray,s,t))
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
}					