#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
    int v;
    vector<int> parent,rank;
    
    DisjointSet(int n)
    {
        this->v=n;
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int find(int a)
    {
        while( a != parent[a] ) a = parent[a];
        return a;
    }

    int merge(int a,int b)
    {
        a = find(a);
        b = find(b);

        if(rank[a] < rank[b]) swap(a,b);

        parent[b] = a;
        rank[a] += rank[b];
    }
};

int main()
{
    DisjointSet ds(4);
    
    return 0;
}