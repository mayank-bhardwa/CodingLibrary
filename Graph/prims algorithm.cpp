// Implementation of Prims Algorith for 
// finding minimum spanning tree

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int,int> ipair;

class weighted_graph{
    protected :
        int V;
        vector<ipair> *adj;
        int k=0,mst_weight=0;
    public :
        weighted_graph(int n)
        {
            V=n;
            adj = new vector<ipair>[V];
        }
        void addEdge(int u,int v,int w)
        {
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        void DFS(int start=0)
        {
            vector<bool> visited(V,false);
            for(int i=0;i<V;i++)
            {
                if(!visited[i])goDeep(i,visited);
            }
        }

        void mst()
        {
            int source=0;
            priority_queue<ipair , vector<ipair> , greater<ipair>> pq;
            
            vector<int> key(V,INT_MAX);        // set containg weigths

            vector<int> parent(V,-1);          // set containg parents

            vector<bool> inMST(V,false);       // set to keep track of items added

            pq.push({source,0});               // 
            parent[source]=source;
            key[source] = 0;
            inMST[source] = true;
            while (!pq.empty())
            {
                inMST[pq.top().first] = true;
                int u = pq.top().first;
                pq.pop();
                for(auto i : adj[u])
                {
                    if(inMST[i.first]==false && key[i.first] > i.second)
                    {
                        pq.push(i);
                        key[i.first] = i.second;
                        parent[i.first] = u;
                    }
                }  
            }
            
            for(int i=1;i<V;i++)
            {
                mst_weight+=key[i];
                cout<<parent[i]+1<<" "<< i+1 << " " << key[i] <<endl;
            }
            cout<<"Weight of minimum spanning tree is :"<<mst_weight;
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
                cout<<t+1<<" ";
                for(int i=adj[t].size()-1;i>=0;i--)
                {
                    if(!visited[adj[t][i].first])
                    {
                        visited[adj[t][i].first] = true;
                        deep.push(adj[t][i].first);
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

    int n, m;
    cin>>n>>m;
    weighted_graph graph(n);
    int a,b,c;
    int k=0;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        graph.addEdge(a-1,b-1,c);
    }
    // graph.DFS();
    // cout<<endl;
    graph.mst();
    return 0;
}