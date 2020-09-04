/*
    While using krushkals algorithm it is convinient to use edge list representation
    First phase of algorithm sorts edge list in nlogn time

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ipair;

struct Disjoint
{
    int n;
    vector<int> parent,rank;

    Disjoint(int V)
    {
        this->n = V;
        parent.resize(V+1);
        rank.resize(V+1,0);
        for(int i=0;i<=V;i++)parent[i] = i;
    }

    int find(int x)
    {
        while(x != parent[x]) x = parent[x];
        return x;
    }

    void merge(int a,int b)
    {
        a = find(a);
        b = find(b);

        if(rank[a] < rank[b])  swap(a,b) ;

        rank[a] += rank[b];
        parent[b] = a;
    }
};
class graph
{
    protected :
        int V;
        vector<pair<int,ipair>> adj;
        int mst_weight=0;
    public :
        graph(int V)
        {
            this->V=V;
        }

        void addEdge(int u,int v,int w)
        {
            adj.push_back({u,{v,w}});
        }

        void krushkals()
        {
            sort(adj.begin(),adj.end(),[](auto a,auto b){return a.second.second < b.second.second;});
            
            Disjoint dj(V);
            for(auto i : adj)
            {
                if(dj.find(i.first)!=dj.find(i.second.first))
                {
                    dj.merge(i.first,i.second.first);
                    mst_weight+=i.second.second;
                    cout<<i.first+1<<" "<<i.second.first+1<<" "<<i.second.second<<endl;
                }
            }
            cout<<"Weight of minimum spanning tree :"<<mst_weight;       
        }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m,u,v,w;
    cin>>n>>m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>w;
        g.addEdge(u-1,v-1,w);
    }
    g.krushkals();
    return 0;
}