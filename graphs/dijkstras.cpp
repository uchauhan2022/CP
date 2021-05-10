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


void dijsktra(vector<pair<int,int> > adj[], int n, int source){
  priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > pq;
  vector<int> dist(n,INT_MAX);
  dist[source]=0;
  pq.push(MP(0,source));
  while(!pq.empty()){
    int dis = pq.top().F;
    int node = pq.top().S;
    pq.pop();
    for(int i = 0; i<adj[node].size(); i++){
      int next = adj[node][i].F;
      int w = adj[node][i].S;
      if(dist[next]>dist[node]+w){
        dist[next]=dist[node]+w;
        pq.push(MP(dist[next],next));
      }
    }
  }
  cout<<"Distances = ";
  for(int i = 0; i<n; i++){
    cout<<dist[i]<<" ";
  }
  cout<<endl;

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
                dijsktra(adj,v,0);


        }
        return 0;
}
