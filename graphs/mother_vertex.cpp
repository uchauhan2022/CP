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

void dfs(vector<int> adj[], vector<int> &visited, int i){
        visited[i]=1;
        for(int j = 0; j<adj[i].size(); j++) {
                if(!visited[adj[i][j]]) dfs(adj,visited,adj[i][j]);
        }
        return;
}

int motherVertex(vector<int> adj[], int v){
        vector<int> visited(v,0);
        int ans = 0;
        for(int i = 0; i<v; i++) {
                if(!visited[i]) {
                        dfs(adj,visited,i);
                        ans = i;
                }
        }
        return ans;
}
void addEdge(vector<int> adj[], int x, int y){
        adj[x].push_back(y);
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int v,e;
        cin>>v>>e;
        vector<int> adj[v];
        for(int i = 0; i<e; i++) {
                int x,y;
                cin>>x>>y;
                addEdge(adj,x,y);
        }
        cout<<motherVertex(adj,v)<<endl;
        return 0;
}
