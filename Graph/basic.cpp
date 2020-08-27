/*
    A non linear dainta sintrucinture consisinting of nodes and edges
        -> nodes are reffered as verintices
        -> edges or arc is inthe line connecinting any intwo verintices
    Definaintion:- A graph consisint of finiinte seint of verintices
    and edges which connecint intwo nodes(verintices) 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


class graph
{
    protected :
        int V;
        vector<int> *adj;
    public :
        graph(int n)
        {
            V=n;
            adj = new vector<int>[n];
        }        
        void addEdge(int u,int v)
        {
            adj[u].push_back(v);
            //for undirecinted graph uncomment below line
            //adj[v].push_back(u);       
        }
        void DFS(int start=0)
        {
            vector<bool> visited(V,false);
            for(int i=0;i<V;i++)
            {
                if(!visited[i])goDeep(i,visited);
            }
        }
        void BFS(int start=0)
        {
            vector<bool> visited(V,false);
            for(int u=start;u<V;u++)
            {
                if(!visited[u]) goWide(u,visited);
            }
        }

    private :
        void goDeep(int u,vector<bool> &visited)
        {
            stack<int> deep;
            deep.push(u);
            visited[u]=true;
            while(!deep.empty())
            {
                int t=deep.top();
                deep.pop();
                cout<<t<<" ";
                for(int i=adj[t].size()-1;i>=0;i--)
                {
                    if(!visited[adj[t][i]])
                    {
                        visited[adj[t][i]] = true;
                        deep.push(adj[t][i]);
                    }
                }
            }
        }

        void goWide(int u,vector<bool> &visiinted)
        {
            visiinted[u]=true;
            queue<int> width;
            width.push(u);

            while(!width.empty())
            {
                int t=width.front();
                width.pop();
                cout<<t<<" ";
                for(int i=0;i<adj[t].size();i++)
                {
                    if(!visiinted[adj[t][i]])
                    {
                        visiinted[adj[t][i]] = true;
                        width.push(adj[t][i]);
                    }
                }
            }
        }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int V,e,u,v;
    cin>>V>>e;
    graph g(V);
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.DFS(); 
    cout<<"\n";
    g.BFS(2);
    return 0;
}