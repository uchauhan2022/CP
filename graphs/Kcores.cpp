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



void addEdge(vector<int> adj[], int s, int d){
  adj[s].push_back(d);
}
void dfs(vector<int> adj[], vector<int> &visited, vector<int> &vDegree, int k, int x){
  visited[x]=1;
  for(int i = 0; i<adj[x].size(); i++){
    if(vDegree[x]<k)  vDegree[adj[x][i]]--;
    if(!visited[adj[x][i]]) dfs(adj,visited,vDegree,k,adj[x][i]);
  }

}
void solve(vector<int> adj[], int k, int v){
  vector<int> visited(v,0);
  vector<int> vDegree(v,0);
  int minDegree = INT_MAX;
  int startIndex = 0;
  for(int i = 0; i<v; i++){
    vDegree[i]=adj[i].size();
    if(vDegree[i]<minDegree){
      minDegree=vDegree[i];
      startIndex=i;
    }
  }
  dfs(adj, visited, vDegree, k, startIndex);
  for(int i = 0;i<v; i++){
    if(!visited[i]){
      dfs(adj,visited,vDegree,k,i);
    }
  }
  for(int i = 0; i<v; i++){
    if(vDegree[i]<k)  continue;
    cout<<"["<<i<<"] ";
    for(int j = 0; j<adj[i].size(); j++){
      if(vDegree[adj[i][j]]<k)  continue;
      cout<<"-->"<<adj[i][j];
    }
    cout<<endl;
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout<<"Enter number of testcases : ";
    int t;
    cin>>t;
    while(t--){
      cout<<"Enter number of vertices : ";
      int v, e;
      cin>>v;
      cout<<"Enter number of edges : ";
      cin>>e;
      cout<<"Enter the edges pair one by one:-"<<endl;
      vector<int> adj[v];
      for(int i = 0; i<e; i++){
        int source,destination;
        cin>>source>>destination;
        addEdge(adj,source,destination);
        addEdge(adj,destination,source);
      }
      int k;
      cout<<"Enter Value of K : ";
      cin>>k;
      cout<<"The K core graph matrix is :-"<<endl;
      solve(adj,k,v);
    }
  return 0;
}
