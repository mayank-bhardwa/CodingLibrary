#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
    int v;
    vector<int> parent,size;
    
    DisjointSet(int n)
    {
        this->v=n;
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            size[i] = 1;
            parent[i] = i;
        } 
    }

    int find(int a)
    {
        while( a != parent[a] ) a = parent[a];
        return a;
    }

    void merge(int a,int b)
    {
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(size[a] < size[b]) swap(a,b);

        parent[b] = a;
        size[a] += size[b];
    }

    void print()
    {
        for(int i=1;i<=v;i++)
        {
            cout<<i<<" "<<parent[i]<<" "<<size[i]<<endl;
        }
    }
};

int main()
{
    DisjointSet ds(4);
    ds.merge(1,2);
    ds.merge(1,3);
    ds.merge(2,3);
    // ds.merge(1,2);
    // ds.merge(2,3);
    ds.print();
    return 0;
}