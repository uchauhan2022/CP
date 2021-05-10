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

struct node{
  int u;
  int v;
  int weight;
  node(int f, int s, int w){
    u=f;
    v=s;
    weight=w;
  }
};

bool comp(node a, node b){
  return a.weight<b.weight;
}

int findParent(int a, vector<int> &parent){
  if(parent[a]==a)  return a;
  return parent[a]= findParent(parent[a],parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
  u = findParent(u,parent);
  v  = findParent(v,parent);
  if(rank[u]>rank[v]){
    parent[v]=u;
  }
  else if(rank[v]>rank[u]){
    parent[u]=v;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}

void krushals(vector<node> &adj, int n){
  vector<int> parent(n,0);
  for(int i = 0 ; i<n; i++){
    parent[i]=i;
  }
  vector<int> rank(n,0);
  int cost = 0;
  vector<pair<int,int> > mst;
  for(auto it: adj){
    if(findParent(it.u,parent)!=findParent(it.v,parent)){
      unionn(it.u,it.v,parent,rank);
      mst.push_back(MP(it.u,it.v));
      cost+=it.weight;
    }
  }
  cout<<cost<<endl;
  for(auto it:mst){
    cout<<it.F<<" "<<it.S<<" "<<endl;
  }

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
                vector<node> adj;
                for(int i = 0; i<e; i++) {
                        int source,destination,weight;
                        cin>>source>>destination>>weight;
                        adj.push_back(node(source,destination,weight));
                }
                sort(adj.begin(), adj.end(), comp);
                krushals(adj,v);


        }
        return 0;
}
