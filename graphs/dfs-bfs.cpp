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

void bfs(vector<int> &adj[], vector<int> &visited[], int v){
								list<int> queue;
								visited[v]=1;
								list<int>::iterator i;
								queue.push_back(v)
								while (!queue.empty()){
																v=queue.front();
																queue.pop_front();
																for(int i = adj[v].begin(), i!=adj[v].end(); i++)
																{
																								if(!visited[*i]) {
																																visited[*i] = true;
																																queue.push_back(*i);
																								}
																}
								}
}
void dfs(vector<int> &adj[], vector<int> &visited, int v){
								visited[v]=1;
								for(int i = 0; i<adj[v].size(); i++)
																if(visited[adj[v][i]]==0)
																								dfs(adj,visited,i);
}
void addEdge(vector<int> &adj[],int u, int v){
								adj[u].push_back(v);
}

int main()
{
								ios_base::sync_with_stdio(false);
								cin.tie(NULL);

								return 0;
}
