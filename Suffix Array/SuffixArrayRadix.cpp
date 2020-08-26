/*
    S=ababba
    add $ sign to end of S $ is less 
    than all elements of S it could be
    any character smaller than elements
    of S. S+='$'
    Suffix Array of S
    6   $
    5   a$
    0   ababba$
    2   abba$
    4   ba$
    1   babba$
    3   bba$
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void radixSort(vector<pair<pair<int,int>,int>> &arr)
{
    int n=arr.size();
    {
        vector<int> cnt(n);
        for(auto x:arr)
        {
            cnt[x.first.second]++;
        }
        vector<pair<pair<int,int>,int>> output(n);
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++)
        {
            pos[i]=pos[i-1]+cnt[i-1];
        }

        for(auto x:arr)
        {
            int i=x.first.second;
            output[pos[i]]=x;
            pos[i]++;
        }
        arr=output;
    }
    {
        vector<int> cnt(n);
        for(auto x:arr)
        {
            cnt[x.first.first]++;
        }
        vector<pair<pair<int,int>,int>> output(n);
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++)
        {
            pos[i]=pos[i-1]+cnt[i-1];
        }

        for(auto x:arr)
        {
            int i=x.first.first;
            output[pos[i]]=x;
            pos[i]++;
        }
        arr=output;
    }
}

vector<int> BuildSuffixArray(string s)
{
    s+="$";
    int n=s.length();
    vector<int> rank(n),index(n);
    {
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
    }
    int k=0;
    while((1<<k)<n)
    {
        vector<pair<pair<int,int>,int>> a(n);
        for(int i=0;i<n;i++)
            a[i]={{rank[i],rank[(i+(1<<k)%n)%n]},i};
        
        radixSort(a);

        for(int i=0;i<n;i++)index[i]=a[i].second;
        rank[index[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].first == a[i-1].first)
            {
                rank[index[i]]=rank[index[i-1]];
            }
            else
            {
                rank[index[i]]=rank[index[i-1]]+1;
            }
        }
        k++;
    }
    return index;
}

void judge()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}

int main()
{
    judge();
    string arr;
    cin>>arr;
    vector<int> suffixarray = BuildSuffixArray(arr); 
    for(auto i:suffixarray)
    {
        cout<<i<<" ";//<<arr.substr(i,arr.length()-i)<<endl;
    }
    return 0;   
}