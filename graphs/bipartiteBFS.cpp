#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
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

bool check(int start, int v, vector<int> adj[], vector<int> &visited){
  list<int> queue;
  queue.push_back(start);
  visited[start]=0;
  while(!queue.empty()){
    int cur = queue.front();
    queue.pop_front();
    for(int i = 0; i<adj[cur].size(); i++){
      if(visited[adj[cur][i]]==-1){
        visited[adj[cur][i]]=1-visited[cur];
        queue.push_back(adj[cur][i]);
      }
      else if(visited[adj[cur][i]]==visited[cur])  return true;
    }
  }
  return false;
}

bool bipartite(vector<int> adj[], int v){
  vector<int> visited(v,-1);

  for(int i = 0 ; i<v; i++){
    if(visited[i]==-1){
      if(check(i,v,adj,visited))  return false;
    }
  }
  return true;
}
void addEdge(vector<int> adj[], int s, int d){
        adj[s].push_back(d);
}


int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<"Enter number of testcases : ";
        int t;
        cin>>t;
        while(t--) {
                cout<<"Enter number of vertices : ";
                int v, e;
                cin>>v;
                cout<<"Enter number of edges : ";
                cin>>e;
                cout<<"Enter the edges pair one by one:-"<<endl;
                vector<int> adj[v];
                for(int i = 0; i<e; i++) {
                        int source,destination;
                        cin>>source>>destination;
                        addEdge(adj,source,destination);
                        addEdge(adj,destination,source);
                }

                if(bipartite(adj, v)) cout<<"The graph is bipartite"<<endl;
                else cout<<"The graph isnt bipartite"<<endl;
        }
        return 0;
}
