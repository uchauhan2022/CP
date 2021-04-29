#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k, in) for (int i=j; i<k; i+=in)
#define RFOR(i, j, k, in) for (int i=j; i>=k; i-=in)
#define MP make_pair
#define PB push_back
#define endl "\n"
#define yes cout<<"yes"<<endl;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define UM unordered_map
#define CHECK(a) cout<<"a :"<<a<<endl
#define mem(a,v) memset(a,v,sizeof(a))
#define S second
#define F first
typedef vector<unsigned long long int> VI;
typedef vector<string> VS;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;

void addEdge(vector<int> adj[], int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],vector<bool> &visited){
        visited[u] = true;
        for (int i=0; i<adj[u].size(); i++)
                if (visited[adj[u][i]] == false)
                        DFSUtil(adj[u][i], adj, visited);
}

int countTrees(vector<int> adj[], int V){
        vector<bool> visited(V, false);
        int res = 0;
        for (int u=0; u<V; u++){
                if (visited[u] == false){
                        DFSUtil(u, adj, visited);
                        res++;
                }
        }
        return res;
}

int main()
{
        int V = 5;
        vector<int> adj[V];
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 2);
        addEdge(adj, 3, 4);
        cout << countTrees(adj, V);
        return 0;
}
