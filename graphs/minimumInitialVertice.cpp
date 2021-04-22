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


void dfs(int x,int y, vector<vector<int> > &adj, vector<vector<int> > &visited, int n, int m){
  visited[x][y]=1;
  if(x+1<n && !visited[x+1][y] && adj[x][y]>=adj[x+1][y]) dfs(x+1,y,adj,visited,n,m);
  if(x-1>=0 && !visited[x-1][y] && adj[x][y]>=adj[x-1][y]) dfs(x-1,y,adj,visited,n,m);
  if(y-1>=0 && !visited[x][y-1] && adj[x][y]>=adj[x][y-1]) dfs(x,y-1,adj,visited,n,m);
  if(y+1<m && !visited[x][y+1] && adj[x][y]>=adj[x][y+1]) dfs(x,y+1,adj,visited,n,m);

}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--) {
                cout<<"Enter dimensions of matrix (nxm) :";
                int n,m;
                cin>>n>>m;
                cout<<"Enter a matrix of "<<n<<"x"<<m<<" :";
                vector<pair<int,pair<int,int> > > v;
                vector<vector<int> > adj(n,vector<int> (m,0));
                for(int i = 0; i<n; i++) {
                        for(int j = 0; j<m; j++) {
                                int x;
                                cin>>x;
                                adj[i][j]=x;
                                v.push_back(make_pair(x,make_pair(i,j)));
                        }
                }
                vector<vector<int> > visited(n,vector<int> (m,0));
                sort(v.begin(), v.end());
                for(int i = v.size()-1; i>=0; i--) {
                        if(!visited[v[i].second.first][v[i].second.second]) {
                                cout<<v[i].second.first<<","<<v[i].second.second<<endl;
                                dfs(v[i].second.first,v[i].second.second, adj, visited, n, m);
                        }
                }
        }
        return 0;
}
