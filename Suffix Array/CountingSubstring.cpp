#include <iostream>
#include <algorithm>
#include <vector>
#define deb(a) cout<<#a<<" "<<a;
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

template<typename T>
int array_high(T arr,int low,int high,string x,string t)
{
    if(low>high) return -1;
    int mid=(low + high)/2;

    if(t.substr(arr[mid],x.size())==x)
    {
        if(mid==high)return mid;
        if(t.substr(arr[mid+1],x.size())==x)
        {
            if(mid==high-1)return high;
            return array_high(arr,mid+1,high,x,t);
        }
        else
        {
            return mid;
        }
    }

    else if(t.substr(arr[mid],x.size()) > x)
    {
        return array_high(arr,low,mid-1,x,t);
    }

    else
    {
        return array_high(arr,mid+1,high,x,t);
    }
}

template <typename T>
int array_low(T arr, int low, int high,string x,string t)  
{    
    if(low>high)return -1;

    int mid=(low + high)/2;

    if(t.substr(arr[mid],x.size()) == x)
    {
        if(t.substr(arr[mid-1],x.size())==x && mid>low)
        {
            return array_low(arr,low,mid-1,x,t);
        }
        else
        {
            return mid;
        }
    }

    else if(t.substr(arr[mid],x.size()) > x)
    {
        return array_low(arr,low,mid-1,x,t);
    }

    else
    {
        return array_low(arr,mid+1,high,x,t);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string t;
	cin>>t;
	vector<int> sarray = BuildSuffixArray(t);
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
        int count=0;
        int k=array_high(sarray,0,sarray.size()-1,s,t);
        int l=array_low(sarray,0,sarray.size()-1,s,t);
        if(k==-1||l==-1)cout<<"0\n";
        else cout<<k-l+1<<"\n";
	}
}					