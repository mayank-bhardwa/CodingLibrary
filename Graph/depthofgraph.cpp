/*
    C++ program to find longest path in a acyclic 
    graph from given starting node
*/
#include<iostream>
#include<vector>

using namespace std;

class graph{
    private:
        int V;
        vector<int> *adj;
    public:
        graph(int V)
        {
            this->V=V;
            adj = new vector<int>[V];
        }
        
        void addEdge(int u,int v)
        {
            adj[u].push_back(v);
        }

        int longestPath(int start)
        {
            vector<bool> visited(V,false);
            return path(start,visited);
        }
    private:
        int path(int u,vector<bool> &visited)
        {
            int depth=0;
            for(int i=0;i<adj[u].size();i++)
            {
                if(!visited[adj[u][i]])
                {
                    visited[adj[u][i]] = true;
                    depth=max(depth,path(adj[u][i],visited));
                }
            }
            return ++depth;
        }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,t;
    cin>>n;
    graph g(n);
    vector<int> starters;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t==-1)starters.push_back(i);
        else g.addEdge(t-1,i);
    }

    int mx=0;
    for(auto i : starters)
    {
        mx=max(mx,g.longestPath(i));
    }

    cout<<mx;
    return 0;
}