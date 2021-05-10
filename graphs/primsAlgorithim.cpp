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

void prims(vector<pair<int,int> > adj[], int n){
  vector<int> key(n,INT_MAX);
  vector<int> parent(n,-1);
  vector<int> mst(n,false);
  key[0]=0;
  parent[0];
  priority_queue< pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq;
  pq.push(MP(key[0],0));
  for(int i = 0; i<n-1; i++){
    int u = pq.top().S;
    pq.pop();
    mst[u]=true;
    for(int j = 0; j<adj[u].size(); j++){
      int v = adj[u][j].F;
      int w = adj[u][j].S;
      if(mst[v]==false && w<key[v]){
        key[v]=w;
        parent[v]=u;
        pq.push(MP(key[v],v));
      }
    }
  }
  for(int i = 1; i<n; i++){
    cout<<parent[i]<<"  is the parent of "<<i<<endl;
  }
}


void addEdge(vector<pair<int,int> > adj[], int s,int w, int d){
        adj[s].push_back(MP(d,w));
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
                cout<<"Enter the edges pair and weight one by one:-"<<endl;
                vector<pair<int,int> > adj[v];
                for(int i = 0; i<e; i++) {
                        int source,destination,weight;
                        cin>>source>>destination>>weight;
                        addEdge(adj,source,weight,destination);
                        addEdge(adj,destination,weight,source);
                }
                prims(adj,v);


        }
        return 0;
}
